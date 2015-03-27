// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "gui/language/lang.h"

using namespace System;

namespace IJWLayer {

   public ref class LangTableWrapper : SimObjectWrapper
   {
   public:
      static LangTableWrapper^ Wrap(int ID) { return static_cast<LangTableWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static LangTableWrapper^ Wrap(LangTable* obj) { return static_cast<LangTableWrapper^>(SimObjectWrapper::Wrap(obj)); };

      LangTable* GetObjectPtr(){
         return static_cast<LangTable*>(mObject);
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
