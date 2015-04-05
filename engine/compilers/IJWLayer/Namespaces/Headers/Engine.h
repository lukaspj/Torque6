using System::String;

namespace IJWLayer
{
   public ref class Engine
   {
   public:
      ref class Con
      {
      public: 
         static void setLogMode(int mode);
         static void quit();
         static void print(String^ str);
         static String^ expandPath(String^ path);
      }; 
      
      ref class Platform
      {
      public:
         static void setMainDotCsDir(String^ Dir);
         static bool setCurrentDirectory(String^ Dir);
      };

      ref class Version
      {
      public:
         static void setCompanyAndProduct(String^ company, String^ product);
      };

      ref class Script
      {
      public:
         static void setScriptExecEcho(bool echo);
         static void trace(bool enable);
      };
   };
}