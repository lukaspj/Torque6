using System::String;

namespace IJWLayer
{
   public ref class Globals
   {
   public: 
      static String^ GetString(String^ name);
      static void SetString(String^ name, String^ val);
      static void SetString(String^ name, const char* val);
      static int GetInt(String^ name);
      static void SetInt(String^ name, int val);
      static bool GetBool(String^ name);
      static void SetBool(String^ name, bool val);
      static float GetFloat(String^ name);
      static void SetFloat(String^ name, float val);

      static String^ getPrefsPath(String^ fileName);
      static bool execPrefs(String^ fileName, bool noCalls, bool journalScript);
      static void export(String^ wildCard, String^ fileName, bool append);
      static void deleteVariables(String^ wildCard);
   };
}