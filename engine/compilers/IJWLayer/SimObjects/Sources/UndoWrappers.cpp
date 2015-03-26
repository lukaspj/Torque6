#include "../../Stdafx.h"
#include "../Headers/UndoWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

int IJWLayer::UndoManagerWrapper::getRedoCount()
{
   if (IsAlive())
      return GetObjectPtr()->getRedoCount();
   return -1;
}

void IJWLayer::UndoManagerWrapper::clearAll()
{
   if (IsAlive())
      GetObjectPtr()->clearAll();
}

int IJWLayer::UndoManagerWrapper::getUndoCount()
{
   if (IsAlive())
      return GetObjectPtr()->getUndoCount();
   return -1;
}

String^ IJWLayer::UndoManagerWrapper::getUndoName(int index)
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getUndoName(index));
   return nullptr;
}

String^ IJWLayer::UndoManagerWrapper::getRedoName(int index)
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getRedoName(index));
   return nullptr;
}

void IJWLayer::UndoManagerWrapper::undo()
{
   if (IsAlive())
      GetObjectPtr()->undo();
}

void IJWLayer::UndoManagerWrapper::redo()
{
   if (IsAlive())
      GetObjectPtr()->redo();
}

String^ IJWLayer::UndoManagerWrapper::getNextUndoName()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getNextUndoName());
   return nullptr;
}

String^ IJWLayer::UndoManagerWrapper::getNextRedoName()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getNextRedoName());
   return nullptr;
}

void IJWLayer::UndoActionWrapper::addToManager(IJWLayer::UndoManagerWrapper^ undoManager)
{
   if (IsAlive() && undoManager->IsAlive())
      GetObjectPtr()->addToManager(undoManager->GetObjectPtr());
}

void IJWLayer::UndoActionWrapper::addToManager()
{
   if (IsAlive())
      GetObjectPtr()->addToManager(NULL);
}