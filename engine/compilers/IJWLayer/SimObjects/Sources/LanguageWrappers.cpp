#include "../../Stdafx.h"
#include "../Headers/LanguageWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

int IJWLayer::LangTable::addLanguage(String^ filename, String^ languageName)
{
   if (!IsAlive())
      return -1;
   UTF8 scriptFilenameBuffer[1024];

   char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();
   char* _languageName = (char*)Marshal::StringToHGlobalAnsi(languageName).ToPointer();
   Con::expandPath((char*)scriptFilenameBuffer, sizeof(scriptFilenameBuffer), _filename);
   return GetObjectPtr()->addLanguage(scriptFilenameBuffer, (const UTF8*)_languageName);
}


int IJWLayer::LangTable::addLanguage(String^ filename)
{
   return addLanguage(filename, nullptr);
}

String^ IJWLayer::LangTable::getString(int string)
{
   if (!IsAlive())
      return nullptr;

   char *ret;
   const char *str;

   if ((str = (const char*)GetObjectPtr()->getString(string)))
   {
      ret = Con::getReturnBuffer(dStrlen(str) + 1);
      dStrcpy(ret, str);
      return gcnew String(ret);
   }

   return nullptr;
}

void IJWLayer::LangTable::setDefaultLanguage(int language)
{
   if (IsAlive())
      GetObjectPtr()->setDefaultLanguage(language);
}

void IJWLayer::LangTable::setCurrentLanguage(int language)
{
   if (IsAlive())
      GetObjectPtr()->setCurrentLanguage(language);
}

int IJWLayer::LangTable::getCurrentLanguage()
{
   if (IsAlive())
      GetObjectPtr()->getCurrentLanguage();
   return -1;
}

String^ IJWLayer::LangTable::getLangName(int language)
{
   if (!IsAlive())
      return nullptr;

   char *ret;
   const char *str;

   if ((str = (const char*)GetObjectPtr()->getLangName(language)))
   {
      ret = Con::getReturnBuffer(dStrlen(str) + 1);
      dStrcpy(ret, str);
      return gcnew String(ret);
   }

   return nullptr;
}

int IJWLayer::LangTable::getNumLang()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getNumLang();
}