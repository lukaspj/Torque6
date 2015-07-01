
#ifndef C_INTERFACE_H
#define C_INTERFACE_H

#include "platform/platform.h"
#include "sim/simObject.h"
#include "graphics/color.h"

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

   struct ColorParam{
   public:
      int r;
      int g;
      int b;
      int a;
      ColorParam(const ColorI& copyCol)
      {
         r = copyCol.red;
         g = copyCol.green;
         b = copyCol.blue;
         a = copyCol.alpha;
      }
      operator ColorI() const{
         return ColorI(r, g, b, a);
      }
   };

   struct Point2IParam{
   public:
      S32 x;
      S32 y;
      Point2IParam(const Point2I& copyPoint)
      {
         x = copyPoint.x;
         y = copyPoint.y;
      }
      operator Point2I() const{
         return Point2I(x, y);
      }
   };

   struct Point2FParam{
   public:
      F32 x;
      F32 y;
      Point2FParam(const Point2F& copyPoint)
      {
         x = copyPoint.x;
         y = copyPoint.y;
      }
      operator Point2F() const{
         return Point2F(x, y);
      }
   };

   struct Point3IParam{
   public:
      S32 x;
      S32 y;
      S32 z;
      Point3IParam(const Point3I& copyPoint)
      {
         x = copyPoint.x;
         y = copyPoint.y;
         z = copyPoint.z;
      }
      operator Point3I() const{
         return Point3I(x, y, z);
      }
   };

   struct Point3FParam{
   public:
      F32 x;
      F32 y;
      F32 z;
      Point3FParam(const Point3F& copyPoint)
      {
         x = copyPoint.x;
         y = copyPoint.y;
         z = copyPoint.z;
      }
      operator Point3F() const{
         return Point3F(x, y, z);
      }
   };
};

#endif // C-INTERFACE_H