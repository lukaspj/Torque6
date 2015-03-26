using System::String;

namespace IJWLayer
{
   public ref class Script
   {
   public: 
      static void setScriptExecEcho(bool echo);
      static void trace(bool enable);
   };
}