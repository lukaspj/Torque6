#include "../../Stdafx.h"
#include "../Headers/CollectionsWrapper.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

void IJWLayer::SimSetWrapper::listObjects()
{
   if (!IsAlive())
      return;

   GetObjectPtr()->lock();
   SimSet::iterator itr;
   for (itr = GetObjectPtr()->begin(); itr != GetObjectPtr()->end(); itr++)
   {
      SimObject *obj = *itr;
      bool isSet = dynamic_cast<SimSet *>(obj) != 0;
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

void IJWLayer::SimSetWrapper::add(...array<SimObjectWrapper^>^ objects)
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

void IJWLayer::SimSetWrapper::remove(...array<SimObjectWrapper^>^ objects)
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

void IJWLayer::SimSetWrapper::deleteObjects()
{
   if (IsAlive())
      GetObjectPtr()->deleteObjects();
}

void IJWLayer::SimSetWrapper::clear()
{
   if (IsAlive())
      GetObjectPtr()->clear();
}

void IJWLayer::SimSetWrapper::callOnChildren(String^ method, ...array<String^>^ args)
{
   if (!IsAlive())
      return;
   const char* _method = (char*)Marshal::StringToHGlobalAnsi(method).ToPointer();

   pin_ptr<const char*> array_pin = &MarshalHelper::MarshalStringArrayToChar(args, 0)[0];
   GetObjectPtr()->callOnChildren(_method, args->Length, array_pin);
}

void IJWLayer::SimSetWrapper::reorderChild(SimObjectWrapper^ obj1, SimObjectWrapper^ obj2)
{
   if (!IsAlive())
      return;
   if (obj1->IsAlive() && obj2->IsAlive())
      GetObjectPtr()->reOrder(obj1->GetObjectPtr(), obj2->GetObjectPtr());
}

int IJWLayer::SimSetWrapper::getCount()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->size();
}

IJWLayer::SimObjectWrapper^ IJWLayer::SimSetWrapper::getObject(int index)
{
   if (!IsAlive())
      return nullptr;
   if (index < 0 || index >= S32(getCount()))
   {
      Con::printf("Set::getObject index out of range.");
      return nullptr;
   }
   return gcnew SimObjectWrapper((*GetObjectPtr())[index]);
}

bool IJWLayer::SimSetWrapper::isMember(SimObjectWrapper^ object)
{
   if (!object->IsAlive())
   {
      Con::printf("SimSet::isMember: %s is not an object.", "TODO: Implement object references");
      return false;
   }

   GetObjectPtr()->lock();
   for (SimSet::iterator i = GetObjectPtr()->begin(); i != GetObjectPtr()->end(); i++)
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

IJWLayer::SimObjectWrapper^ IJWLayer::SimSetWrapper::findObjectByInternalName(String^ name, bool searchChildren)
{
   if (!IsAlive())
      return nullptr;
   const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();

   StringTableEntry pcName = StringTable->insert(_name);

   SimObject* child = GetObjectPtr()->findObjectByInternalName(pcName, searchChildren);
   if (child)
      return gcnew SimObjectWrapper(child);
   return nullptr;
}
IJWLayer::SimObjectWrapper^ IJWLayer::SimSetWrapper::findObjectByInternalName(String^ name)
{
   return findObjectByInternalName(name, false);
}

void IJWLayer::SimSetWrapper::bringToFront(IJWLayer::SimObjectWrapper^ object)
{
   if (!IsAlive() || !object->IsAlive())
      return;
   GetObjectPtr()->bringObjectToFront(object->GetObjectPtr());
}

void IJWLayer::SimSetWrapper::pushToBack(IJWLayer::SimObjectWrapper^ object)
{
   if (!IsAlive() || !object->IsAlive())
      return;
   GetObjectPtr()->pushObjectToBack(object->GetObjectPtr());
}

int IJWLayer::NameTagsWrapper::createTag(String^ tagName)
{
   if (!IsAlive())
      return -1;

   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();
   return GetObjectPtr()->createTag(_tagName);
}

int IJWLayer::NameTagsWrapper::renameTag(int tagId, String^ newTagName)
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

int IJWLayer::NameTagsWrapper::deleteTag(int tagId)
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

int IJWLayer::NameTagsWrapper::getTagCount()
{
   if (IsAlive())
      return GetObjectPtr()->getTagCount();
   return -1;
}

String^ IJWLayer::NameTagsWrapper::getTagName(int tagId)
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

int IJWLayer::NameTagsWrapper::getTagId(String^ tagName)
{
   if (!IsAlive())
      return -1;

   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();
   return GetObjectPtr()->getTagId(_tagName);
}

String^ IJWLayer::NameTagsWrapper::getAllTags()
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

bool IJWLayer::NameTagsWrapper::tag(int objectId, array<int>^ tagIds)
{
   if (!IsAlive())
      return -1;

   // Iterate tags.
   for (U32 index = 0; index < tagIds->Length; ++index)
   {
      // Fetch tag Id.
      const NameTags::TagId tagId = tagIds[index];

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

bool IJWLayer::NameTagsWrapper::untag(int objectId, array<int>^ tagIds)
{
   if (!IsAlive())
      return -1;

   // Iterate tags.
   for (U32 index = 0; index < tagIds->Length; ++index)
   {
      // Fetch tag Id.
      const NameTags::TagId tagId = tagIds[index];

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

bool IJWLayer::NameTagsWrapper::hasTags(int objectId, array<int>^ tagIds)
{
   if (!IsAlive())
      return -1;

   // Iterate tags.
   for (U32 index = 0; index < tagIds->Length; ++index)
   {
      // Fetch tag Id.
      const NameTags::TagId tagId = tagIds[index];

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

String^ IJWLayer::NameTagsWrapper::queryTags(array<int>^ tagIds, bool excluded)
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
   NameTags::queryType results;
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

   for (NameTags::queryType::iterator itr = results.begin(); itr != results.end(); ++itr)
   {
      const U32 offset = dSprintf(pBuffer, bufferSize, "%d ", itr->key);
      pBuffer += offset;
      bufferSize -= offset;
   }

   return gcnew String(pReturnBuffer);
}