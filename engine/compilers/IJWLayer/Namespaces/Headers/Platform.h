using System::String;

namespace IJWLayer
{
   public ref class Platform
   {
   public: 
      static void setMainDotCsDir(String^ Dir);
      static bool setCurrentDirectory(String^ Dir);
   };
}