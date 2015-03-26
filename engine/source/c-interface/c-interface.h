
#ifndef C_INTERFACE_H
#define C_INTERFACE_H

#include "platform/platform.h"
#include "sim/simObject.h"

extern "C" {
   DLL_PUBLIC void SetCallbacks(void* ptr, void* methodPtr, void* isMethodPtr, void *mainPtr);
}

#define CALL_CINTERFACE_FUNCTION(name, ...){const char *v[] = { __VA_ARGS__ }; CInterface::CallFunction(name, v, sizeof(v) / sizeof(*v));}

class CInterface {
   typedef bool (*IsMethodCallback)(const char* className, const char* methodName);
   typedef void (*CallMainCallback)();
   typedef const char* (*CallFunctionCallback)(const char* name, const char **argv, int argc, bool *result);
   typedef const char* (*CallMethodCallback)(const char* className, U32 object, const char* name, const char **argv, int argc, bool *result);
   IsMethodCallback mIsMethodCallback;
   CallFunctionCallback mFunctionCallback;
   CallMethodCallback mMethodCallback;
   CallMainCallback mMainCallback;
   const char* _CallFunction(const char* name, const char **argv, int argc, bool *result);
   const char* _CallMethod(const char* className, U32 object, const char* name, const char **argv, int argc, bool *res);
   void _CallMain(bool *res);
   bool _isMethod(const char* className, const char* methodName);
public:
   CInterface(){
      mFunctionCallback = NULL;
      mMethodCallback = NULL;
      mIsMethodCallback = NULL;
      mMainCallback = NULL;
   }

   static const char* CallFunction(const char* name, const char **argv, int argc, bool *result);
   static const char* CallMethod(SimObject* obj, const char* name, const char **argv, int argc, bool *res);
   static void CallMain(bool *res);
   static bool isMethod(const char* className, const char* methodName);
   static CInterface& GetCInterface();
   void SetCallFunctionCallback(void* ptr) { mFunctionCallback = (CallFunctionCallback)ptr; };
   void SetCallMethodCallback(void* ptr) { mMethodCallback = (CallMethodCallback)ptr; };
   void SetCallIsMethodCallback(void* ptr) { mIsMethodCallback = (IsMethodCallback)ptr; };
   void SetMainCallback(void* ptr) { mMainCallback = (CallMainCallback)ptr; };
};

#endif // C-INTERFACE_H