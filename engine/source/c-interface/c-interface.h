
#ifndef C_INTERFACE_H
#define C_INTERFACE_H

#include "platform\platform.h"

extern "C" {
   DLL_PUBLIC void SetCallFunctionCallback(void* ptr);
}

#define CALL_CINTERFACE_FUNCTION(name, ...){const char *v[] = { __VA_ARGS__ }; CInterface::CallFunction(name, v, sizeof(v) / sizeof(*v));}

class CInterface {
   typedef char* (*CallFunctionCallback)(const char* name, const char **argv, int argc);
   CallFunctionCallback mCallback;
   char* _CallFunction(const char* name, const char **argv, int argc);
public:
   CInterface(){
      mCallback = NULL;
   }

   static char* CallFunction(const char* name, const char **argv, int argc);
   static CInterface& GetCInterface();
   void SetCallFunctionCallback(void* ptr) { mCallback = (CallFunctionCallback)ptr; };
};

#endif // C-INTERFACE_H