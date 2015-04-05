#include "../../stdafx.h"
#include "../Headers/AssetWrappers.h"

using namespace System::Runtime::InteropServices;

String^ IJWLayer::DeclaredAssets::Path::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getPath());
   return nullptr;
}

void IJWLayer::DeclaredAssets::Path::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setPath(_val);
}

String^ IJWLayer::DeclaredAssets::Extension::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getExtension());
   return nullptr;
}

void IJWLayer::DeclaredAssets::Extension::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setExtension(_val);
}

bool IJWLayer::DeclaredAssets::Recurse::get()
{
   if (IsAlive())
      return GetObjectPtr()->getRecurse();
   return false;
}

void IJWLayer::DeclaredAssets::Recurse::set(bool val)
{
   if (IsAlive())
      return;

   GetObjectPtr()->setRecurse(val);
}

String^ IJWLayer::ReferencedAssets::Path::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getPath());
   return nullptr;
}

void IJWLayer::ReferencedAssets::Path::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setPath(_val);
}

String^ IJWLayer::ReferencedAssets::Extension::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getExtension());
   return nullptr;
}

void IJWLayer::ReferencedAssets::Extension::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setExtension(_val);
}

bool IJWLayer::ReferencedAssets::Recurse::get()
{
   if (IsAlive())
      return GetObjectPtr()->getRecurse();
   return false;
}

void IJWLayer::ReferencedAssets::Recurse::set(bool val)
{
   if (IsAlive())
      return;

   GetObjectPtr()->setRecurse(val);
}

String^ IJWLayer::AssetBase::AssetName::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getAssetName());
   return nullptr;
}

void IJWLayer::AssetBase::AssetName::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setAssetName(_val);
}

String^ IJWLayer::AssetBase::AssetDescription::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getAssetDescription());
   return nullptr;
}

void IJWLayer::AssetBase::AssetDescription::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setAssetDescription(_val);
}

String^ IJWLayer::AssetBase::AssetCategory::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getAssetCategory());
   return nullptr;
}

void IJWLayer::AssetBase::AssetCategory::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setAssetCategory(_val);
}

bool IJWLayer::AssetBase::AutoUnload::get()
{
   if (IsAlive())
      return GetObjectPtr()->getAssetAutoUnload();
   return false;
}

void IJWLayer::AssetBase::AutoUnload::set(bool val)
{
   if (IsAlive())
      return;

   GetObjectPtr()->setAssetAutoUnload(val);
}

bool IJWLayer::AssetBase::Internal::get()
{
   if (IsAlive())
      return GetObjectPtr()->getAssetInternal();
   return false;
}

void IJWLayer::AssetBase::Internal::set(bool val)
{
   if (IsAlive())
      return;

   GetObjectPtr()->setAssetInternal(val);
}

bool IJWLayer::AssetBase::Private::get()
{
   if (IsAlive())
      return GetObjectPtr()->getAssetPrivate();
   return false;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Refresh asset. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///-------------------------------------------------------------------------------------------------

void IJWLayer::AssetBase::refreshAsset()
{
   if (IsAlive())
      GetObjectPtr()->refreshAsset();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets asset identifier. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else the asset identifier. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::AssetBase::getAssetId()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(GetObjectPtr()->getAssetId());
}

String^ IJWLayer::AudioAsset::AudioFile::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getAudioFile());
   return nullptr;
}

void IJWLayer::AudioAsset::AudioFile::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setAudioFile(_val);
}

float IJWLayer::AudioAsset::Volume::get()
{
   if (IsAlive())
      return GetObjectPtr()->getVolume();
   return false;
}

void IJWLayer::AudioAsset::Volume::set(float val)
{
   if (IsAlive())
      return;

   GetObjectPtr()->setLooping(val);
}

int IJWLayer::AudioAsset::VolumeChannel::get()
{
   if (IsAlive())
      return GetObjectPtr()->getVolumeChannel();
   return false;
}

void IJWLayer::AudioAsset::VolumeChannel::set(int val)
{
   if (IsAlive())
      return;

   GetObjectPtr()->setVolumeChannel(val);
}

bool IJWLayer::AudioAsset::Looping::get()
{
   if (IsAlive())
      return GetObjectPtr()->getLooping();
   return false;
}

void IJWLayer::AudioAsset::Looping::set(bool val)
{
   if (IsAlive())
      return;

   GetObjectPtr()->setLooping(val);
}

bool IJWLayer::AudioAsset::Streaming::get()
{
   if (IsAlive())
      return GetObjectPtr()->getStreaming();
   return false;
}

void IJWLayer::AudioAsset::Streaming::set(bool val)
{
   if (IsAlive())
      return;

   GetObjectPtr()->setStreaming(val);
}

IJWLayer::ShaderAsset^ IJWLayer::BaseMaterialAsset::getShaderAsset()
{
   if (IsAlive())
      return ShaderAsset::Wrap(GetObjectPtr()->getShader());
   return nullptr;
}

void IJWLayer::BaseMaterialAsset::setShaderAsset(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setShader(_val);
}

String^ IJWLayer::MeshAsset::MeshFile::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getMeshFile());
   return nullptr;
}

void IJWLayer::MeshAsset::MeshFile::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setMeshFile(_val);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the path to the ImageFile. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else the path. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ImageAsset::ImageFile::get()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(GetObjectPtr()->getImageFile());
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the image to the given image file. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="imageFile">  The image file to set. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::ImageFile::set(String^ imageFile)
{
   if (!IsAlive())
      return;
   const char* _imageFile = (char*)Marshal::StringToHGlobalAnsi(imageFile).ToPointer();
   GetObjectPtr()->setImageFile(_imageFile);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the filtermode. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else a String^. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ImageAsset::FilterMode::get()
{
   if (IsAlive())
      return gcnew String(EngineImageAsset::getFilterModeDescription(GetObjectPtr()->getFilterMode()));
   return nullptr;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the given filter mode. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="filterMode"> The filter mode to set. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::FilterMode::set(String^ filterMode)
{
   if (!IsAlive())
      return;
   const char* _filterMode = (char*)Marshal::StringToHGlobalAnsi(filterMode).ToPointer();
   // Fetch Texture Filter Mode.
   const EngineImageAsset::TextureFilterMode enumFilterMode = EngineImageAsset::getFilterModeEnum(_filterMode);

   // Valid Filter?
   if (enumFilterMode == EngineImageAsset::FILTER_INVALID)
   {
      // Warn.
      Con::warnf("ImageAsset::setFilterMode() - Invalid Filter Mode Specified! (%s)", _filterMode);
      // Finish Here.
      return;
   }

   // Set Filter Mode.
   GetObjectPtr()->setFilterMode(enumFilterMode);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets whether this image is forced to 16bit colors. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  true if it is forced, false if not. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::ImageAsset::Force16Bit::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getForce16Bit();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets whether to force the image to 16 bit colors. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   True to force, false to not force. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::Force16Bit::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setForce16Bit(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets whether CELL row order should be used or not. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  Whether CELL row order should be used or not. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::ImageAsset::CellRowOrder::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getCellRowOrder();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets whether cell row order should be used or not. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   Whether the row order should be used or not. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::CellRowOrder::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setCellRowOrder(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the cell x-offset. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The offset. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::CellOffsetX::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getCellOffsetX();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the cell x-offset. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new offset. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::CellOffsetX::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setCellOffsetX(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the cell y-offset. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The offset. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::CellOffsetY::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getCellOffsetY();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the cell y-offset. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new offset. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::CellOffsetY::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setCellOffsetY(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the cell x-stride. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The stride. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::CellStrideX::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getCellStrideX();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the cell x-stride. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new stride. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::CellStrideX::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setCellStrideX(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the cell y-stride. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The stride. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::CellStrideY::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getCellStrideY();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the cell y-stride. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new stride. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::CellStrideY::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setCellStrideY(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the horizontal cell count. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The count. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::CellCountX::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getCellCountX();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the horizontal cell count. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new count. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::CellCountX::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setCellCountX(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the vertical cell count. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The count. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::CellCountY::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getCellCountY();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the vertical cell count. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new count. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::CellCountY::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setCellCountY(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the width of the cells. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The width. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::CellWidth::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getCellWidth();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the width of the cells. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new width. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::CellWidth::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setCellWidth(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the height of the cells. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The height. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::CellHeight::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getCellHeight();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the height of the cells. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new height. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAsset::CellHeight::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setCellHeight(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the width of the image in pixels. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The width. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::ImageWidth::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getImageWidth();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the height of the image in pixels. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The height. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::ImageHeight::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getImageHeight();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the size of the image in pixels. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else a space-seperated string with the coordinates. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ImageAsset::ImageSize::get()
{
   if (!IsAlive())
      return nullptr;
   // Create Returnable Buffer.
   char* pBuffer = Con::getReturnBuffer(32);

   // Format Buffer.
   dSprintf(pBuffer, 32, "%d %d", GetObjectPtr()->getImageWidth(), GetObjectPtr()->getImageHeight());

   // Return Buffer.
   return gcnew String(pBuffer);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets whether the image has power-of-two dimensions or not. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  true if it has power-of-two dimensions, false if not. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::ImageAsset::IsImagePOT::get()
{
   if (!IsAlive())
      return false;
   return isPow2(GetObjectPtr()->getImageWidth()) && isPow2(GetObjectPtr()->getImageHeight());
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the frame count. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The frame count. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::FrameCount::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getFrameCount();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets size of the specified frame. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="frame">   The frame's index. </param>
///
/// <returns>  nullptr if it fails, else the frame size. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ImageAsset::getFrameSize(int frame)
{
   if (!IsAlive())
      return nullptr;
   // Check Frame.
   if (frame < 0 || frame >= (S32)GetObjectPtr()->getFrameCount())
   {
      // Warn.
      Con::warnf("ImageAsset::getFrameSize() - Invalid Frame; Allowed range is 0 to %d", GetObjectPtr()->getFrameCount() - 1);
      // Finish Here.
      return nullptr;
   }

   // Fetch Selected Frame Pixel Area.
   const EngineImageAsset::FrameArea::PixelArea& framePixelArea = GetObjectPtr()->getImageFrameArea(frame).mPixelArea;

   // Create Returnable Buffer.
   char* pBuffer = Con::getReturnBuffer(32);

   // Format Buffer.
   dSprintf(pBuffer, 32, "%d %d", framePixelArea.mPixelWidth, framePixelArea.mPixelHeight);

   // Return Velocity.
   return gcnew String(pBuffer);
}

///-------------------------------------------------------------------------------------------------
/// <summary>
///   Clears the explicit cells. The image asset stays in explicit mode however with no explicit
///   cells a single full-frame cell becomes default.
/// </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  true if it succeeds, false if it fails. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::ImageAsset::clearExplicitCells()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->clearExplicitCells();
}

///-------------------------------------------------------------------------------------------------
/// <summary>
///   Adds an explicit cell. The image asset must be in explicit mode for this operation to
///   succeed.
/// </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellOffsetX">   The offset in the X axis to the top-left of the cell. </param>
/// <param name="cellOffsetY">   The offset in the Y axis to the top-left of the cell. </param>
/// <param name="cellWidth">     Width of the cell. </param>
/// <param name="cellHeight">    Height of the cell. </param>
/// <param name="cellName">      Name of the cell's region. </param>
///
/// <returns>  true if it succeeds, false if it fails. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::ImageAsset::addExplicitCell(int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, String^ cellName)
{
   if (!IsAlive())
      return false;
   const char* _cellName = (char*)Marshal::StringToHGlobalAnsi(cellName).ToPointer();

   return GetObjectPtr()->addExplicitCell(cellOffsetX, cellOffsetY, cellWidth, cellHeight, _cellName);
}

///-------------------------------------------------------------------------------------------------
/// <summary>
///   Inserts an explicit cell. The image asset must be in explicit mode for this operation to
///   succeed.
/// </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellIndex">     Zero-based index of the cell.  This will work when no cells are
///                              present. If the index is beyond the cell count then the cell is
///                              simply added. </param>
/// <param name="cellOffsetX">   The offset in the X axis to the top-left of the cell. </param>
/// <param name="cellOffsetY">   The offset in the Y axis to the top-left of the cell. </param>
/// <param name="cellWidth">     Width of the cell. </param>
/// <param name="cellHeight">    Height of the cell. </param>
/// <param name="cellName">      Name of the cell. </param>
///
/// <returns>  true if it succeeds, false if it fails. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::ImageAsset::insertExplicitCell(int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, String^ cellName)
{
   if (!IsAlive())
      return false;
   const char* _cellName = (char*)Marshal::StringToHGlobalAnsi(cellName).ToPointer();

   return GetObjectPtr()->insertExplicitCell(cellIndex, cellOffsetX, cellOffsetY, cellWidth, cellHeight, _cellName);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Removes the explicit cell at the index described by cellIdx. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellIdx"> Zero-based index of the cell. </param>
///
/// <returns>  true if it succeeds, false if it fails. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::ImageAsset::removeExplicitCell(int cellIdx)
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->removeExplicitCell(cellIdx);
}

///-------------------------------------------------------------------------------------------------
/// <summary>
///   Sets explicit cell. The image asset must be in explicit mode for this operation to succeed.
/// </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellIndex">     Zero-based index of the cell. </param>
/// <param name="cellOffsetX">   The offset in the X axis to the top-left of the cell. </param>
/// <param name="cellOffsetY">   The offset in the Y axis to the top-left of the cell. </param>
/// <param name="cellWidth">     Width of the cell. </param>
/// <param name="cellHeight">    Height of the cell. </param>
/// <param name="cellName">      Name of the cell. </param>
///
/// <returns>  true if it succeeds, false if it fails. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::ImageAsset::setExplicitCell(int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, String^ cellName)
{
   if (!IsAlive())
      return false;
   const char* _cellName = (char*)Marshal::StringToHGlobalAnsi(cellName).ToPointer();

   return GetObjectPtr()->setExplicitCell(cellIndex, cellOffsetX, cellOffsetY, cellWidth, cellHeight, _cellName);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets explicit cell count. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The explicit cell count. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::getExplicitCellCount()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getExplicitCellCount();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the offset of the cell in Explicit Mode. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellIdx"> Zero-based index of the cell. </param>
///
/// <returns>  nullptr if it fails, else the explicit cell offset. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ImageAsset::getExplicitCellOffset(int cellIdx)
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(GetObjectPtr()->getExplicitCellOffset(cellIdx).scriptThis());
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the offset of the cell in Explicit Mode. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellName">   Name of the cell. </param>
///
/// <returns>  nullptr if it fails, else the explicit cell offset. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ImageAsset::getExplicitCellOffset(String^ cellName)
{
   if (!IsAlive())
      return nullptr;
   const char* _cellName = (char*)Marshal::StringToHGlobalAnsi(cellName).ToPointer();
   // Using cell name.
   EngineImageAsset::FrameArea& frameRegion = GetObjectPtr()->getCellByName(_cellName);

   const Vector2 offset = frameRegion.mPixelArea.mPixelOffset;

   return gcnew String(offset.scriptThis());
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the width of the cell in Explicit Mode. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellIdx"> Zero-based index of the cell. </param>
///
/// <returns>  The explicit cell width. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::getExplicitCellWidth(int cellIdx)
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getExplicitCellWidth(cellIdx);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the width of the cell in Explicit Mode. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellName">   Name of the cell. </param>
///
/// <returns>  The explicit cell width. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::getExplicitCellWidth(String^ cellName)
{
   if (!IsAlive())
      return -1;
   const char* _cellName = (char*)Marshal::StringToHGlobalAnsi(cellName).ToPointer();
   // Using cell name.
   EngineImageAsset::FrameArea& frameRegion = GetObjectPtr()->getCellByName(_cellName);

   return frameRegion.mPixelArea.mPixelWidth;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the height of the cell in Explicit Mode. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellIdx"> Zero-based index of the cell. </param>
///
/// <returns>  The explicit cell height. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::getExplicitCellHeight(int cellIdx)
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getExplicitCellHeight(cellIdx);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the height of the cell in Explicit Mode. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellName">   Name of the cell. </param>
///
/// <returns>  The explicit cell height. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::getExplicitCellHeight(String^ cellName)
{
   if (!IsAlive())
      return -1;
   const char* _cellName = (char*)Marshal::StringToHGlobalAnsi(cellName).ToPointer();
   // Using cell name.
   EngineImageAsset::FrameArea& frameRegion = GetObjectPtr()->getCellByName(_cellName);

   return frameRegion.mPixelArea.mPixelHeight;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets cell region name in Explicit Mode. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellIdx"> Zero-based index of the cell. </param>
///
/// <returns>  nullptr if it fails, else the explicit cell name. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ImageAsset::getExplicitCellName(int cellIdx)
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(GetObjectPtr()->getExplicitCellName(cellIdx));
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets cell region name in Explicit Mode. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="cellName">   Name of the cell. </param>
///
/// <returns>  nullptr if it fails, else the explicit cell name. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAsset::getExplicitCellIndex(String^ cellName)
{
   if (!IsAlive())
      return -1;
   const char* _cellName = (char*)Marshal::StringToHGlobalAnsi(cellName).ToPointer();
   return GetObjectPtr()->getExplicitCellIndex(_cellName);
}

String^ IJWLayer::PluginAsset::PluginFile::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getPluginPath());
   return nullptr;
}

void IJWLayer::PluginAsset::PluginFile::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setPluginPath(_val);
}

String^ IJWLayer::ShaderAsset::VertexShaderFile::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getVertexShaderPath());
   return nullptr;
}

void IJWLayer::ShaderAsset::VertexShaderFile::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setVertexShaderPath(_val);
}

String^ IJWLayer::ShaderAsset::PixelShaderFile::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getPixelShaderPath());
   return nullptr;
}

void IJWLayer::ShaderAsset::PixelShaderFile::set(String^ val)
{
   if (IsAlive())
      return;

   const char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setPixelShaderPath(_val);
}