using namespace System;

namespace IJWLayer {

   public ref class MarshalHelper
   {
   public:
      static array<const char*>^ MarshalStringArrayToChar(array<String^>^ args, int prependPadding);
   };
}