#include "../../Stdafx.h"
#include "../Headers/UndoWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

int IJWLayer::UndoManager::getRedoCount()
{
   if (IsAlive())
      return GetObjectPtr()->getRedoCount();
   return -1;
}

void IJWLayer::UndoManager::clearAll()
{
   if (IsAlive())
      GetObjectPtr()->clearAll();
}

int IJWLayer::UndoManager::getUndoCount()
{
   if (IsAlive())
      return GetObjectPtr()->getUndoCount();
   return -1;
}

String^ IJWLayer::UndoManager::getUndoName(int index)
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getUndoName(index));
   return nullptr;
}

String^ IJWLayer::UndoManager::getRedoName(int index)
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getRedoName(index));
   return nullptr;
}

void IJWLayer::UndoManager::undo()
{
   if (IsAlive())
      GetObjectPtr()->undo();
}

void IJWLayer::UndoManager::redo()
{
   if (IsAlive())
      GetObjectPtr()->redo();
}

String^ IJWLayer::UndoManager::getNextUndoName()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getNextUndoName());
   return nullptr;
}

String^ IJWLayer::UndoManager::getNextRedoName()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getNextRedoName());
   return nullptr;
}

void IJWLayer::UndoAction::addToManager(IJWLayer::UndoManager^ undoManager)
{
   if (IsAlive() && undoManager->IsAlive())
      GetObjectPtr()->addToManager(undoManager->GetObjectPtr());
}

void IJWLayer::UndoAction::addToManager()
{
   if (IsAlive())
      GetObjectPtr()->addToManager(NULL);
}