#include "Stdafx.h"
#include "DebuggerWrapper.h"
#include "MarshalHelper.h"

using namespace System::Runtime::InteropServices;

String^ IJWLayer::RemoteDebugger1Wrapper::getCodeFiles()
{
   if (!IsAlive())
      return nullptr;
   // Fetch a return buffer.  This may be excessive but it avoids reallocation code.
   S32 bufferSize = 1024 * 65;
   char* pBuffer = Con::getReturnBuffer(bufferSize);

   // Get the code files.
   if (!GetObjectPtr()->getCodeFiles(pBuffer, bufferSize))
   {
      // Warn.
      Con::warnf("Fetching code files resulted in a buffer overflow.");
      return nullptr;
   }

   return gcnew String(pBuffer);
}

void IJWLayer::RemoteDebugger1Wrapper::setNextStatementBreak(bool enabled)
{
   if (IsAlive())
      GetObjectPtr()->setNextStatementBreak(enabled);
}