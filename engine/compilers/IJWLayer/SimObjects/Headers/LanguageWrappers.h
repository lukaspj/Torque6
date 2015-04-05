// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "gui/language/lang.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System;

typedef LangTable EngineLangTable;

namespace IJWLayer {

   public ref class LangTable : SimObject
   {
   public:
      static LangTable^ Wrap(int ID) { return static_cast<LangTable^>(SimObject::Wrap(ID)); };
      static LangTable^ Wrap(EngineLangTable* obj) { return static_cast<LangTable^>(SimObject::Wrap(obj)); };

      EngineLangTable* GetObjectPtr(){
         return static_cast<EngineLangTable*>(mObject);
      };

      int addLanguage(String^ filename, String^ languageName);
      int addLanguage(String^ filename);
      String^ getString(int string);
      void setDefaultLanguage(int languageName);
      void setCurrentLanguage(int languageName);
      int getCurrentLanguage();
      String^ getLangName(int languageID);
      int getNumLang();
   };

}
