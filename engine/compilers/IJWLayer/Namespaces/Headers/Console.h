using System::String;

namespace IJWLayer
{
   public ref class Con
   {
   public: 
      static void setLogMode(int mode);
      static void quit();
      static void print(String^ str);
      static String^ expandPath(String^ path);
   };
}