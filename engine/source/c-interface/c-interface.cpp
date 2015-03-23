#include "c-interface.h"
#include "collection\vector.h"

CInterface& CInterface::GetCInterface()
{
   static CInterface INSTANCE;
   return INSTANCE;
}

bool CInterface::isMethod(const char* className, const char* methodName)
{
   return GetCInterface()._isMethod(className, methodName);
}

char* CInterface::CallFunction(const char* name, const char **argv, int argc, bool *result)
{
   return GetCInterface()._CallFunction(name, argv, argc, result);
}

char* CInterface::CallMethod(SimObject* obj, const char* name, const char **argv, int argc, bool *res)
{
   return GetCInterface()._CallMethod(obj->getClassName(), obj->getId(), name, argv, argc, res);
}

bool CInterface::_isMethod(const char* className, const char* methodName)
{
   if (mIsMethodCallback){
      return mIsMethodCallback(className, methodName);
   }
   return NULL;
}

char* CInterface::_CallFunction(const char* name, const char **argv, int argc, bool *result)
{
   if (mFunctionCallback){
      return mFunctionCallback(name, argv, argc, result);
   }
   result = false;
   return NULL;
}

char* CInterface::_CallMethod(const char* className, U32 object, const char* name, const char **argv, int argc, bool *res)
{
   if (mMethodCallback){
      return mMethodCallback(className, object, name, argv, argc, res);
   }
   res = false;
   return NULL;
}

void SetCallbacks(void* ptr, void* methodPtr, void* isMethodPtr) {
   CInterface::GetCInterface().SetCallFunctionCallback(ptr);
   CInterface::GetCInterface().SetCallMethodCallback(methodPtr);
   CInterface::GetCInterface().SetCallIsMethodCallback(isMethodPtr);
}