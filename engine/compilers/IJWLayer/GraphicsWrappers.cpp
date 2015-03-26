#include "Stdafx.h"
#include "GraphicsWrappers.h"
#include "MarshalHelper.h"
#include "io/fileStream.h"

using namespace System::Runtime::InteropServices;

bool IJWLayer::PNGImageWrapper::CreateBaseImage(int width, int height, int imageType)
{
   if (IsAlive())
      return GetObjectPtr()->Create(width, height, (PNGImageType)imageType);
   return false;
}

bool IJWLayer::PNGImageWrapper::MergeOn(int width, int height, String^ imageFile)
{
   if (!IsAlive())
      return false;

   char* _imageFile = (char*)Marshal::StringToHGlobalAnsi(imageFile).ToPointer();

   FileStream fStream;

   if (!fStream.open(_imageFile, FileStream::Read))
   {
      Con::printf("Failed to open file '%s'.", imageFile);
      return false;
   }

   PNGImage* newImage = new PNGImage();

   bool didReadImage = newImage->Read(_imageFile);

   if (!didReadImage)
   {
      newImage->CleanMemoryUsage();

      delete newImage;
      return false;
   }

   fStream.close();

   bool didMergeOn = GetObjectPtr()->MergeOn(width, height, newImage);

   newImage->CleanMemoryUsage();
   delete newImage;

   return didMergeOn;
}

bool IJWLayer::PNGImageWrapper::SaveImage(String^ fileName)
{
   if (!IsAlive())
      return false;

   char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();

   FileStream fStream;

   if (!fStream.open(_fileName, FileStream::Write))
   {
      Con::printf("Failed to open file '%s'.", _fileName);
      return false;
   }

   fStream.close();

   GetObjectPtr()->Write(_fileName);

   GetObjectPtr()->CleanMemoryUsage();

   return true;
}