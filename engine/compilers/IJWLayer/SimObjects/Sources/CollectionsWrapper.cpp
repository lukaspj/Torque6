#include "../../Stdafx.h"
#include "../Headers/CollectionsWrapper.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

void IJWLayer::SimSet::listObjects()
{
   if (!IsAlive())
      return;

   GetObjectPtr()->lock();
   EngineSimSet::iterator itr;
   for (itr = GetObjectPtr()->begin(); itr != GetObjectPtr()->end(); itr++)
   {
      EngineSimObject *obj = *itr;
      bool isSet = dynamic_cast<EngineSimSet *>(obj) != 0;
      const char *name = obj->getName();
      if (name)
         Con::printf("   %d,\"%s\": %s %s", obj->getId(), name,
         obj->getClassName(), isSet ? "(g)" : "");
      else
         Con::printf("   %d: %s %s", obj->getId(), obj->getClassName(),
         isSet ? "(g)" : "");
   }
   GetObjectPtr()->unlock();
}

void IJWLayer::SimSet::add(...array<SimObject^>^ objects)
{
   if (!IsAlive())
      return;
   for (int ii = 0; ii < objects->Length; ii++)
   {
      if (objects[ii]->IsAlive())
         GetObjectPtr()->addObject(objects[ii]->GetObjectPtr());
      else
         Con::printf("Set::add: Object \"%s\" doesn't exist", "TODO, add object reference");
   }
}

void IJWLayer::SimSet::remove(...array<SimObject^>^ objects)
{
   if (!IsAlive())
      return;
   for (int ii = 0; ii < objects->Length; ii++)
   {
      GetObjectPtr()->lock();
      if (objects[ii]->IsAlive() && GetObjectPtr()->find(GetObjectPtr()->begin(), GetObjectPtr()->end(), objects[ii]->GetObjectPtr()) != GetObjectPtr()->end())
         GetObjectPtr()->removeObject(objects[ii]->GetObjectPtr());
      else
         Con::printf("Set::remove: Object \"%s\" does not exist in set", "TODO, add object reference");
      GetObjectPtr()->unlock();
   }
}

void IJWLayer::SimSet::deleteObjects()
{
   if (IsAlive())
      GetObjectPtr()->deleteObjects();
}

void IJWLayer::SimSet::clear()
{
   if (IsAlive())
      GetObjectPtr()->clear();
}

void IJWLayer::SimSet::callOnChildren(String^ method, ...array<String^>^ args)
{
   if (!IsAlive())
      return;
   const char* _method = (char*)Marshal::StringToHGlobalAnsi(method).ToPointer();

   pin_ptr<const char*> array_pin = &MarshalHelper::MarshalStringArrayToChar(args, 0)[0];
   GetObjectPtr()->callOnChildren(_method, args->Length, array_pin);
}

void IJWLayer::SimSet::reorderChild(SimObject^ obj1, SimObject^ obj2)
{
   if (!IsAlive())
      return;
   if (obj1->IsAlive() && obj2->IsAlive())
      GetObjectPtr()->reOrder(obj1->GetObjectPtr(), obj2->GetObjectPtr());
}

int IJWLayer::SimSet::getCount()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->size();
}

IJWLayer::SimObject^ IJWLayer::SimSet::getObject(int index)
{
   if (!IsAlive())
      return nullptr;
   if (index < 0 || index >= S32(getCount()))
   {
      Con::printf("Set::getObject index out of range.");
      return nullptr;
   }
   return SimObject::Wrap((*GetObjectPtr())[index]);
}

bool IJWLayer::SimSet::isMember(SimObject^ object)
{
   if (!object->IsAlive())
   {
      Con::printf("SimSet::isMember: %s is not an object.", "TODO: Implement object references");
      return false;
   }

   GetObjectPtr()->lock();
   for (EngineSimSet::iterator i = GetObjectPtr()->begin(); i != GetObjectPtr()->end(); i++)
   {
      if (*i == object->GetObjectPtr())
      {
         GetObjectPtr()->unlock();
         return true;
      }
   }
   GetObjectPtr()->unlock();

   return false;
}

IJWLayer::SimObject^ IJWLayer::SimSet::findObjectByInternalName(String^ name, bool searchChildren)
{
   if (!IsAlive())
      return nullptr;
   const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();

   StringTableEntry pcName = StringTable->insert(_name);

   EngineSimObject* child = GetObjectPtr()->findObjectByInternalName(pcName, searchChildren);
   if (child)
      return SimObject::Wrap(child);
   return nullptr;
}
IJWLayer::SimObject^ IJWLayer::SimSet::findObjectByInternalName(String^ name)
{
   return findObjectByInternalName(name, false);
}

void IJWLayer::SimSet::bringToFront(IJWLayer::SimObject^ object)
{
   if (!IsAlive() || !object->IsAlive())
      return;
   GetObjectPtr()->bringObjectToFront(object->GetObjectPtr());
}

void IJWLayer::SimSet::pushToBack(IJWLayer::SimObject^ object)
{
   if (!IsAlive() || !object->IsAlive())
      return;
   GetObjectPtr()->pushObjectToBack(object->GetObjectPtr());
}

int IJWLayer::NameTags::createTag(String^ tagName)
{
   if (!IsAlive())
      return -1;

   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();
   return GetObjectPtr()->createTag(_tagName);
}

int IJWLayer::NameTags::renameTag(int tagId, String^ newTagName)
{
   if (!IsAlive())
      return -1;

   // Sanity!
   if (tagId == 0)
   {
      Con::warnf("Invalid tag Id.\n");
      return 0;
   }

   const char* _newTagName = (char*)Marshal::StringToHGlobalAnsi(newTagName).ToPointer();
   return GetObjectPtr()->renameTag(tagId, _newTagName);
}

int IJWLayer::NameTags::deleteTag(int tagId)
{
   if (!IsAlive())
      return -1;

   // Sanity!
   if (tagId == 0)
   {
      Con::warnf("Invalid tag Id.\n");
      return NULL;
   }

   return GetObjectPtr()->deleteTag(tagId);
}

int IJWLayer::NameTags::getTagCount()
{
   if (IsAlive())
      return GetObjectPtr()->getTagCount();
   return -1;
}

String^ IJWLayer::NameTags::getTagName(int tagId)
{
   if (!IsAlive())
      return nullptr;

   // Sanity!
   if (tagId == 0)
   {
      Con::warnf("Invalid tag Id.\n");
      return nullptr;
   }

   return gcnew String(GetObjectPtr()->getTagName(tagId));
}

int IJWLayer::NameTags::getTagId(String^ tagName)
{
   if (!IsAlive())
      return -1;

   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();
   return GetObjectPtr()->getTagId(_tagName);
}

String^ IJWLayer::NameTags::getAllTags()
{
   if (!IsAlive())
      return nullptr;

   // Get buffer.
   const U32 bufferLength = 4096;
   char* pBuffer = Con::getReturnBuffer(bufferLength);

   // Format tags.
   const S32 bufferUsed = GetObjectPtr()->formatTags(pBuffer, bufferLength);

   // Sanity!
   if (bufferUsed < 0)
   {
      Con::warnf("Buffer overflow when formatting all tags.  All tags will not be returned.\n");
   }

   return gcnew String(pBuffer);
}

bool IJWLayer::NameTags::tag(int objectId, array<int>^ tagIds)
{
   if (!IsAlive())
      return -1;

   // Iterate tags.
   for (U32 index = 0; index < tagIds->Length; ++index)
   {
      // Fetch tag Id.
      const EngineNameTags::TagId tagId = tagIds[index];

      // Sanity!
      if (tagId == 0)
      {
         Con::warnf("Invalid tag Id.\n");
         return false;
      }

      // Tag.
      if (!GetObjectPtr()->tag(objectId, tagId))
         return false;
   }

   return true;
}

bool IJWLayer::NameTags::untag(int objectId, array<int>^ tagIds)
{
   if (!IsAlive())
      return -1;

   // Iterate tags.
   for (U32 index = 0; index < tagIds->Length; ++index)
   {
      // Fetch tag Id.
      const EngineNameTags::TagId tagId = tagIds[index];

      // Sanity!
      if (tagId == 0)
      {
         Con::warnf("Invalid tag Id.\n");
         return false;
      }

      // Tag.
      if (!GetObjectPtr()->untag(objectId, tagId))
         return false;
   }

   return true;
}

bool IJWLayer::NameTags::hasTags(int objectId, array<int>^ tagIds)
{
   if (!IsAlive())
      return -1;

   // Iterate tags.
   for (U32 index = 0; index < tagIds->Length; ++index)
   {
      // Fetch tag Id.
      const EngineNameTags::TagId tagId = tagIds[index];

      // Sanity!
      if (tagId == 0)
      {
         Con::warnf("Invalid tag Id.\n");
         return false;
      }

      // Tag.
      if (GetObjectPtr()->hasTag(objectId, tagId))
         return true;
   }

   return false;
}

String^ IJWLayer::NameTags::queryTags(array<int>^ tagIds, bool excluded)
{
   if (!IsAlive() || tagIds->Length <= 0)
      return nullptr;

   String^ NLseperatedTags;
   NLseperatedTags += tagIds[0];
   for (int i = 1; i < tagIds->Length; i++)
   {
      NLseperatedTags += "\r\n" + tagIds[i];
   }

   const char* _NLTags = (char*)Marshal::StringToHGlobalAnsi(NLseperatedTags).ToPointer();

   // Query tags.
   GetObjectPtr()->queryTags(_NLTags);

   // Fetch appropriate results.
   EngineNameTags::queryType results;
   if (excluded)
   {
      results = GetObjectPtr()->mIncludedQueryMap;
   }
   else
   {
      results = GetObjectPtr()->mExcludedQueryMap;
   }

   // Format results.
   U32 bufferSize = 8192;
   char* pReturnBuffer = Con::getReturnBuffer(bufferSize);
   dSprintf(pReturnBuffer, bufferSize * sizeof(char), "%s", "");
   char* pBuffer = pReturnBuffer;

   for (EngineNameTags::queryType::iterator itr = results.begin(); itr != results.end(); ++itr)
   {
      const U32 offset = dSprintf(pBuffer, bufferSize, "%d ", itr->key);
      pBuffer += offset;
      bufferSize -= offset;
   }

   return gcnew String(pReturnBuffer);
}