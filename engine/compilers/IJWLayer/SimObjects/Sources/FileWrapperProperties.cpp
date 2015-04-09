#include "../../stdafx.h"
#include "../Headers/FileWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

void IJWLayer::FileDialog::DefaultPath::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   EngineFileDialog::setDefaultPath(GetObjectPtr(), _value);
}

String^ IJWLayer::FileDialog::DefaultPath::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getData().mDefaultPath);
   return nullptr;
}

void IJWLayer::FileDialog::DefaultFile::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   EngineFileDialog::setDefaultFile(GetObjectPtr(), _value);
}

String^ IJWLayer::FileDialog::DefaultFile::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getData().mDefaultFile);
   return nullptr;
}

void IJWLayer::FileDialog::FileName::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   EngineFileDialog::setFile(GetObjectPtr(), _value);
}

String^ IJWLayer::FileDialog::FileName::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getData().mFile);
   return nullptr;
}

void IJWLayer::FileDialog::Filters::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   EngineFileDialog::setFilters(GetObjectPtr(), _value);
}

String^ IJWLayer::FileDialog::Filters::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getData().mFilters);
   return nullptr;
}

void IJWLayer::FileDialog::Title::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->getData().mTitle = _value;
}

String^ IJWLayer::FileDialog::Title::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getData().mTitle);
   return nullptr;
}

void IJWLayer::FileDialog::ChangePath::set(bool value)
{
   if (!IsAlive())
      return;
   if (value)
      GetObjectPtr()->getData().mStyle |= FileDialogData::FDS_CHANGEPATH;
   else
      GetObjectPtr()->getData().mStyle &= ~FileDialogData::FDS_CHANGEPATH;
}

bool IJWLayer::FileDialog::ChangePath::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getData().mStyle & FileDialogData::FDS_CHANGEPATH;
}

void IJWLayer::OpenFileDialog::MustExist::set(bool value)
{
   if (!IsAlive())
      return;
   if (value)
      GetObjectPtr()->getData().mStyle |= FileDialogData::FDS_MUSTEXIST;
   else
      GetObjectPtr()->getData().mStyle &= ~FileDialogData::FDS_MUSTEXIST;
}

bool IJWLayer::OpenFileDialog::MustExist::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getData().mStyle & FileDialogData::FDS_MUSTEXIST;
}

void IJWLayer::OpenFileDialog::MultipleFiles::set(bool value)
{
   if (!IsAlive())
      return;
   if (value)
      GetObjectPtr()->getData().mStyle |= FileDialogData::FDS_MULTIPLEFILES;
   else
      GetObjectPtr()->getData().mStyle &= ~FileDialogData::FDS_MULTIPLEFILES;
}

bool IJWLayer::OpenFileDialog::MultipleFiles::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getData().mStyle & FileDialogData::FDS_MULTIPLEFILES;
}

void IJWLayer::OpenFolderDialog::FileMustExist::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->mMustExistInDir = _value;
}

String^ IJWLayer::OpenFolderDialog::FileMustExist::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->mMustExistInDir);
   return nullptr;
}

void IJWLayer::SaveFileDialog::OverwritePrompt::set(bool value)
{
   if (!IsAlive())
      return;
   if (value)
      GetObjectPtr()->getData().mStyle |= FileDialogData::FDS_OVERWRITEPROMPT;
   else
      GetObjectPtr()->getData().mStyle &= ~FileDialogData::FDS_OVERWRITEPROMPT;
}

bool IJWLayer::SaveFileDialog::OverwritePrompt::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getData().mStyle & FileDialogData::FDS_OVERWRITEPROMPT;
}