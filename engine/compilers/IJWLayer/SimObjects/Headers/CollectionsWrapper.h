// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "sim/simSet.h"
#include "collection/nameTags.h"

// #pragma unmanaged
#pragma managed(pop)

typedef SimSet EngineSimSet;
typedef SimGroup EngineSimGroup;
typedef NameTags EngineNameTags;
typedef SimDataBlockGroup EngineSimDataBlockGroup;

namespace IJWLayer {

   public ref class SimSet : SimObject
   {
   public:

      static SimSet^ Wrap(int ID) { return static_cast<SimSet^>(SimObject::Wrap(ID)); };
      static SimSet^ Wrap(EngineSimSet* obj) { return static_cast<SimSet^>(SimObject::Wrap(obj)); };

      EngineSimSet* GetObjectPtr(){
         return static_cast<EngineSimSet*>(mObject);
      };

      void listObjects();
      void add(...array<SimObject^>^ objects);
      void remove(...array<SimObject^>^ objects);
      void deleteObjects();
      void clear();
      void callOnChildren(String^ method, ...array<String^>^ args);
      void reorderChild(SimObject^ child1, SimObject^ child2);
      int getCount();
      SimObject^ getObject(int index);
      bool isMember(SimObject^ object);
      SimObject^ findObjectByInternalName(String^ name, bool searchChildren);
      SimObject^ findObjectByInternalName(String^ name);
      void bringToFront(SimObject^ object);
      void pushToBack(SimObject^ object);
   };

   public ref class SimGroup : SimSet
   {
   public:
      static SimGroup^ Wrap(int ID) { return static_cast<SimGroup^>(SimObject::Wrap(ID)); };
      static SimGroup^ Wrap(EngineSimGroup* obj) { return static_cast<SimGroup^>(SimObject::Wrap(obj)); };

      EngineSimGroup* GetObjectPtr(){
         return static_cast<EngineSimGroup*>(mObject);
      };
   };

   public ref class NameTags : SimSet
   {
   public:
      static NameTags^ Wrap(int ID) { return static_cast<NameTags^>(SimObject::Wrap(ID)); };
      static NameTags^ Wrap(EngineNameTags* obj) { return static_cast<NameTags^>(SimObject::Wrap(obj)); };

      EngineNameTags* GetObjectPtr(){
         return static_cast<EngineNameTags*>(mObject);
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

   public ref class SimDataBlockGroup : SimGroup
   {
   public:
      static SimDataBlockGroup^ Wrap(int ID) { return static_cast<SimDataBlockGroup^>(SimObject::Wrap(ID)); };
      static SimDataBlockGroup^ Wrap(EngineSimDataBlockGroup* obj) { return static_cast<SimDataBlockGroup^>(SimObject::Wrap(obj)); };

      EngineSimDataBlockGroup* GetObjectPtr(){
         return static_cast<EngineSimDataBlockGroup*>(mObject);
      };
   };
}
