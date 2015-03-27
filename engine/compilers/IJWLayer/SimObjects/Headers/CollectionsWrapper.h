// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

#include "sim/simSet.h"
#include "collection/nameTags.h"

namespace IJWLayer {

   public ref class SimSetWrapper : SimObjectWrapper
   {
   public:

      static SimSetWrapper^ Wrap(int ID) { return static_cast<SimSetWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static SimSetWrapper^ Wrap(SimObject* obj) { return static_cast<SimSetWrapper^>(SimObjectWrapper::Wrap(obj)); };

      SimSet* GetObjectPtr(){
         return static_cast<SimSet*>(mObject);
      };

      void listObjects();
      void add(...array<SimObjectWrapper^>^ objects);
      void remove(...array<SimObjectWrapper^>^ objects);
      void deleteObjects();
      void clear();
      void callOnChildren(String^ method, ...array<String^>^ args);
      void reorderChild(SimObjectWrapper^ child1, SimObjectWrapper^ child2);
      int getCount();
      SimObjectWrapper^ getObject(int index);
      bool isMember(SimObjectWrapper^ object);
      SimObjectWrapper^ findObjectByInternalName(String^ name, bool searchChildren);
      SimObjectWrapper^ findObjectByInternalName(String^ name);
      void bringToFront(SimObjectWrapper^ object);
      void pushToBack(SimObjectWrapper^ object);
   };

   public ref class SimGroupWrapper : SimSetWrapper
   {
   public:
      static SimGroupWrapper^ Wrap(int ID) { return static_cast<SimGroupWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static SimGroupWrapper^ Wrap(SimObject* obj) { return static_cast<SimGroupWrapper^>(SimObjectWrapper::Wrap(obj)); };

      SimGroup* GetObjectPtr(){
         return static_cast<SimGroup*>(mObject);
      };
   };

   public ref class NameTagsWrapper : SimSetWrapper
   {
   public:
      static NameTagsWrapper^ Wrap(int ID) { return static_cast<NameTagsWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static NameTagsWrapper^ Wrap(SimObject* obj) { return static_cast<NameTagsWrapper^>(SimObjectWrapper::Wrap(obj)); };

      NameTags* GetObjectPtr(){
         return static_cast<NameTags*>(mObject);
      };

      int createTag(String^ tagName);
      int renameTag(int tagId, String^ newTagName);
      int deleteTag(int tagId);
      int getTagCount();
      String^ getTagName(int tagId);
      int getTagId(String^ tagName);
      String^ getAllTags();
      bool tag(int objectId, array<int>^ tagIds);
      bool untag(int objectId, array<int>^ tagIds);
      bool hasTags(int objectId, array<int>^ tagId);
      String^ queryTags(array<int>^ tagIds, bool excluded);
   };

   public ref class SimDataBlockGroupWrapper : SimGroupWrapper
   {
   public:
      static SimDataBlockGroupWrapper^ Wrap(int ID) { return static_cast<SimDataBlockGroupWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static SimDataBlockGroupWrapper^ Wrap(SimObject* obj) { return static_cast<SimDataBlockGroupWrapper^>(SimObjectWrapper::Wrap(obj)); };

      SimDataBlockGroup* GetObjectPtr(){
         return static_cast<SimDataBlockGroup*>(mObject);
      };
   };
}
