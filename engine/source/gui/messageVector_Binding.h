//-----------------------------------------------------------------------------
// Copyright (c) 2013 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

extern "C" {
   DLL_PUBLIC MessageVector* MessageVectorCreateInstance()
   {
      return new MessageVector();
   }

   DLL_PUBLIC void MessageVectorClear(MessageVector* messageVector)
   {
      messageVector->clear();
   }

   DLL_PUBLIC void MessageVectorPushBackLine(MessageVector* messageVector, const char* msg, int tag)
   {
      messageVector->pushBackLine(msg, tag);
   }

   DLL_PUBLIC bool MessageVectorPopBackLine(MessageVector* messageVector)
   {
      if (messageVector->getNumLines() <= 0) {
         Con::errorf(ConsoleLogEntry::General, "MessageVector::popBackLine(): underflow");
         return false;
      }

      messageVector->popBackLine();
      return true;
   }

   DLL_PUBLIC void MessageVectorPushFrontLine(MessageVector* messageVector, const char* msg, int tag)
   {
      messageVector->pushFrontLine(msg, tag);
   }

   DLL_PUBLIC bool MessageVectorPopFrontLine(MessageVector* messageVector)
   {
      if (messageVector->getNumLines() <= 0) {
         Con::errorf(ConsoleLogEntry::General, "MessageVector::popFrontLine(): underflow");
         return false;
      }

      messageVector->popFrontLine();
      return true;
   }

   DLL_PUBLIC bool MessageVectorInsertLine(MessageVector* messageVector, int pos, const char* msg, int tag)
   {
      messageVector->insertLine(pos, msg, tag);
      return true;
   }

   DLL_PUBLIC bool MessageVectorDeleteLine(MessageVector* messageVector, U32 lineIndex)
   {
      if (lineIndex >= messageVector->getNumLines())
         return false;

      messageVector->deleteLine(lineIndex);
      return true;
   }

   DLL_PUBLIC void MessageVectorDump(MessageVector* messageVector, const char* filename, const char* header)
   {
      messageVector->dump(filename, header);
   }

   DLL_PUBLIC int MessageVectorGetNumLines(MessageVector* messageVector)
   {
      return messageVector->getNumLines();
   }

   DLL_PUBLIC const char* MessageVectorGetLineTextByTag(MessageVector* messageVector, int tag)
   {
      for (U32 i = 0; i < messageVector->getNumLines(); i++)
         if (messageVector->getLine(i).messageTag == tag)
            return messageVector->getLine(i).message;
      return NULL;
   }

   DLL_PUBLIC int MessageVectorGetLineIndexByTag(MessageVector* messageVector, int tag)
   {
      for (U32 i = 0; i < messageVector->getNumLines(); i++)
         if (messageVector->getLine(i).messageTag == tag)
            return i;
      return -1;
   }

   DLL_PUBLIC const char* MessageVectorGetLineText(MessageVector* messageVector, U32 index)
   {
      if (index >= messageVector->getNumLines()) {
         Con::errorf(ConsoleLogEntry::General, "MessageVector::getLineText(con): out of bounds line");
         return nullptr;
      }

      return messageVector->getLine(index).message;
   }

   DLL_PUBLIC int MessageVectorGetLineTag(MessageVector* messageVector, U32 index)
   {
      if (index >= messageVector->getNumLines()) {
         Con::errorf(ConsoleLogEntry::General, "MessageVector::getLineText(con): out of bounds line");
         return -1;
      }

      return messageVector->getLine(index).messageTag;
   }
}