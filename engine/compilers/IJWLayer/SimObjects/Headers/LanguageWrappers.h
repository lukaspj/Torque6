// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "gui/language/lang.h"

using namespace System;

namespace IJWLayer {

   public ref class LangTableWrapper : SimObjectWrapper
   {
   public:
      LangTableWrapper(int ID) : SimObjectWrapper(ID){};

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
