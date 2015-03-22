#include "c-interface.h"
#include "collection\vector.h"

CInterface& CInterface::GetCInterface()
{
   static CInterface INSTANCE;
   return INSTANCE;
}

char* CInterface::CallFunction(const char* name, const char **argv, int argc)
{
   return GetCInterface()._CallFunction(name, argv, argc);
}


char* CInterface::_CallFunction(const char* name, const char **argv, int argc)
{
   if (mCallback){
      return mCallback(name, argv, argc);
   }
   return NULL;
}

void SetCallFunctionCallback(void* ptr) {
   CInterface::GetCInterface().SetCallFunctionCallback(ptr);
}