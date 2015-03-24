#include "Stdafx.h"
#include "MarshalHelper.h"

using namespace System::Runtime::InteropServices;

array<const char*>^ IJWLayer::MarshalHelper::MarshalStringArrayToChar(array<String^>^ args, int prependPadding)
{
   array<const char*> ^nativeArray = gcnew array<const char*>(args->Length + prependPadding);
   for (int i = prependPadding; i < args->Length + prependPadding; i++)
   {
      nativeArray[i] = (char*)Marshal::StringToHGlobalAnsi(args[i]).ToPointer();
   }
   return nativeArray;
}