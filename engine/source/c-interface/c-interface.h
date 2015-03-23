
#ifndef C_INTERFACE_H
#define C_INTERFACE_H

#include "platform/platform.h"
#include "sim/simObject.h"

extern "C" {
   DLL_PUBLIC void SetCallbacks(void* ptr, void* methodPtr, void* isMethodPtr);
}

#define CALL_CINTERFACE_FUNCTION(name, ...){const char *v[] = { __VA_ARGS__ }; CInterface::CallFunction(name, v, sizeof(v) / sizeof(*v));}

class CInterface {
   typedef bool (*IsMethodCallback)(const char* className, const char* methodName);
   typedef char* (*CallFunctionCallback)(const char* name, const char **argv, int argc, bool *result);
   typedef char* (*CallMethodCallback)(const char* className, U32 object, const char* name, const char **argv, int argc, bool *result);
   IsMethodCallback mIsMethodCallback;
   CallFunctionCallback mFunctionCallback;
   CallMethodCallback mMethodCallback;
   char* _CallFunction(const char* name, const char **argv, int argc, bool *result);
   char* _CallMethod(const char* className, U32 object, const char* name, const char **argv, int argc, bool *res);
   bool _isMethod(const char* className, const char* methodName);
public:
   CInterface(){
      mFunctionCallback = NULL;
      mMethodCallback = NULL;
   }

   static char* CallFunction(const char* name, const char **argv, int argc, bool *result);
   static char* CallMethod(SimObject* obj, const char* name, const char **argv, int argc, bool *res);
   static bool isMethod(const char* className, const char* methodName);
   static CInterface& GetCInterface();
   void SetCallFunctionCallback(void* ptr) { mFunctionCallback = (CallFunctionCallback)ptr; };
   void SetCallMethodCallback(void* ptr) { mMethodCallback = (CallMethodCallback)ptr; };
   void SetCallIsMethodCallback(void* ptr) { mIsMethodCallback = (IsMethodCallback)ptr; };
};

#endif // C-INTERFACE_H