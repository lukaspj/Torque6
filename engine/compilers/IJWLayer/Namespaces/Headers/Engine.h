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
         static void setEchoFileLoads(bool enable);
         static void quit();
         static void quitWithErrorMessage(String^ msg);
         static void gotoWebPage(String^ address);
         static void print(String^ str);
         static String^ expandPath(String^ path);
         static void dumpConsoleClasses(bool dumpScript, bool dumpEngine);
         static void dumpConsoleFunctions(bool dumpScript, bool dumpEngine);
      
         static void echo(String^ text);
         static void echoSeparator();
         static void warn(String^ text);
         static void error(String^ text);
         //static void cls();

         static String^ expandEscape(String^ text);
         static String^ collapseEscape(String^ text);
      }; 
      
      ref class Platform
      {
      public:
         static void setMainDotCsDir(String^ Dir);
         static bool setCurrentDirectory(String^ Dir);
         static bool isiPhoneBuild();
         //static String^ getAppleDeviceIPAddress();
         static String^ enumerateConsoleClasses(String^ baseClass);

         // Possibly somewhere else.
         static String^ expandPath(String^ path);
         static String^ collapsePath(String^ path);
         static void addPathExpando(String^ expando, String^ path);
         static void removePathExpando(String^ expando);
         static bool isPathExpando(String^ expando);
         static int getPathExpandoCount();
         static String^ getPathExpandoKey(int expandoIndex);
         static String^ getPathExpandoValue(int expandoIndex);
      };
      ref class Version
      {
      public:
         /*
         static bool isDebugBuild();
         static int getVersionNumber();
         static String^ getVersionString();
         static String^ getCompileTimeString();
         static String^ getBuildString();
         static String^ getEngineVersion();
         static String^ getiPhoneToolsVersion();
         */
         static void setCompanyAndProduct(String^ company, String^ product);
      };

      ref class Script
      {
      public:
         static void setScriptExecEcho(bool echo);
         static void trace(bool enable);
         static void debug();
         static void backtrace();
         static bool isPackage(String^ packageName);
         static void activatePackage(String^ packageName);
         static void deactivatePackage(String^ packageName);

         static String^ call(String^ funcName, ...array<String^>^ args);
         static String^ getDSOPath(String^ scriptFileName);
         static bool compile(String^ fileName);
         static bool compile(const char *fileName, bool editorScript);
         static String^ compilePath(String^ path);
         static bool exec(String^ fileName, bool noCalls, bool journalScript);
         static String^ eval(String^ script);

         static bool isFunction(String^ funcName);
         static bool isMethod(String^ pNamespace, String^ pMethodName);
         static String^ getModNameFromPath(String^ path);

         static bool OpenRemoteDebugger(int debuggerVersion, int port, String^ password);
         /*
         static void dbgSetParameters(int port, String^ password, bool waitForClient);
         static bool dbgIsConnected();
         static void dbgDisconnect();
         */
      };
      /*
      ref class Profiler{
      public:
         static void MarkerEnable(String^ markerName, bool enable);
         static void Enable(bool enable);
         static void Dump();
         static void DumpToFile(String^ fileName);
         static void Reset();
      };
      */

      ref class Input{
      public:
         static void activateDirectInput();
         static void deactivateDirectInput();
         //static bool activateKeyboard();
         //static void deactivateKeyboard();
         //static bool enableMouse();
         //static void disableMouse();
         //static bool enableJoystick();
         //static void disableJoystick();
         //static void echoInputState();
         //static void enableXInput();
         //static void disableXInput();
         //static void resetXInput();
         //static void isXInputConnected(int controllerID);
         //static void getXInputState(int controllerID, String^ action, bool current);
         //static void rumble(String^ device, float xRumble, float yRumble);
      };
   };
}