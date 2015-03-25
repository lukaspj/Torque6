#include "Stdafx.h"
#include "AssetWrappers.h"

using namespace System::Runtime::InteropServices;

///-------------------------------------------------------------------------------------------------
/// <summary>  Refresh asset. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///-------------------------------------------------------------------------------------------------

void IJWLayer::AssetBaseWrapper::refreshAsset()
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

String^ IJWLayer::AssetBaseWrapper::getAssetId()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(GetObjectPtr()->getAssetId());
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the path to the ImageFile. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else the path. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ImageAssetWrapper::ImageFile::get()
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

void IJWLayer::ImageAssetWrapper::ImageFile::set(String^ imageFile)
{
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

String^ IJWLayer::ImageAssetWrapper::FilterMode::get()
{
   return gcnew String(ImageAsset::getFilterModeDescription(GetObjectPtr()->getFilterMode()));
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the given filter mode. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="filterMode"> The filter mode to set. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAssetWrapper::FilterMode::set(String^ filterMode)
{
   const char* _filterMode = (char*)Marshal::StringToHGlobalAnsi(filterMode).ToPointer();
   // Fetch Texture Filter Mode.
   const ImageAsset::TextureFilterMode enumFilterMode = ImageAsset::getFilterModeEnum(_filterMode);

   // Valid Filter?
   if (enumFilterMode == ImageAsset::FILTER_INVALID)
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

bool IJWLayer::ImageAssetWrapper::Force16Bit::get()
{
   return GetObjectPtr()->getForce16Bit();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets whether to force the image to 16 bit colors. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   True to force, false to not force. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAssetWrapper::Force16Bit::set(bool value)
{
   GetObjectPtr()->setForce16Bit(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets whether CELL row order should be used or not. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  Whether CELL row order should be used or not. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::ImageAssetWrapper::CellRowOrder::get()
{
   return GetObjectPtr()->getCellRowOrder();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets whether cell row order should be used or not. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   Whether the row order should be used or not. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAssetWrapper::CellRowOrder::set(bool value)
{
   GetObjectPtr()->setCellRowOrder(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the cell x-offset. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The offset. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAssetWrapper::CellOffsetX::get()
{
   return GetObjectPtr()->getCellOffsetX();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the cell x-offset. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new offset. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAssetWrapper::CellOffsetX::set(int value)
{
   GetObjectPtr()->setCellOffsetX(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the cell y-offset. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The offset. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAssetWrapper::CellOffsetY::get()
{
   return GetObjectPtr()->getCellOffsetY();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the cell y-offset. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new offset. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAssetWrapper::CellOffsetY::set(int value)
{
   GetObjectPtr()->setCellOffsetY(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the cell x-stride. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The stride. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAssetWrapper::CellStrideX::get()
{
   return GetObjectPtr()->getCellStrideX();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the cell x-stride. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new stride. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAssetWrapper::CellStrideX::set(int value)
{
   GetObjectPtr()->setCellStrideX(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the cell y-stride. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The stride. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAssetWrapper::CellStrideY::get()
{
   return GetObjectPtr()->getCellStrideY();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the cell y-stride. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new stride. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAssetWrapper::CellStrideY::set(int value)
{
   GetObjectPtr()->setCellStrideY(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the horizontal cell count. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The count. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAssetWrapper::CellCountX::get()
{
   return GetObjectPtr()->getCellCountX();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the horizontal cell count. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new count. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAssetWrapper::CellCountX::set(int value)
{
   GetObjectPtr()->setCellCountX(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the vertical cell count. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The count. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAssetWrapper::CellCountY::get()
{
   return GetObjectPtr()->getCellCountY();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the vertical cell count. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new count. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAssetWrapper::CellCountY::set(int value)
{
   GetObjectPtr()->setCellCountY(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the width of the cells. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The width. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAssetWrapper::CellWidth::get()
{
   return GetObjectPtr()->getCellWidth();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the width of the cells. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new width. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAssetWrapper::CellWidth::set(int value)
{
   GetObjectPtr()->setCellWidth(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the height of the cells. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The height. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAssetWrapper::CellHeight::get()
{
   return GetObjectPtr()->getCellHeight();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the height of the cells. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <param name="value">   The new height. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ImageAssetWrapper::CellHeight::set(int value)
{
   GetObjectPtr()->setCellHeight(value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the width of the image in pixels. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The width. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAssetWrapper::ImageWidth::get()
{
   return GetObjectPtr()->getImageWidth();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the height of the image in pixels. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The height. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAssetWrapper::ImageHeight::get()
{
   return GetObjectPtr()->getImageHeight();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the size of the image in pixels. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else a space-seperated string with the coordinates. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ImageAssetWrapper::ImageSize::get()
{
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

bool IJWLayer::ImageAssetWrapper::IsImagePOT::get()
{
   return isPow2(GetObjectPtr()->getImageWidth()) && isPow2(GetObjectPtr()->getImageHeight());
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the frame count. </summary>
///
/// <remarks>  Lukas, 25-03-2015. </remarks>
///
/// <returns>  The frame count. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::ImageAssetWrapper::FrameCount::get()
{
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

String^ IJWLayer::ImageAssetWrapper::getFrameSize(int frame)
{
   // Check Frame.
   if (frame < 0 || frame >= (S32)GetObjectPtr()->getFrameCount())
   {
      // Warn.
      Con::warnf("ImageAsset::getFrameSize() - Invalid Frame; Allowed range is 0 to %d", GetObjectPtr()->getFrameCount() - 1);
      // Finish Here.
      return nullptr;
   }

   // Fetch Selected Frame Pixel Area.
   const ImageAsset::FrameArea::PixelArea& framePixelArea = GetObjectPtr()->getImageFrameArea(frame).mPixelArea;

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

bool IJWLayer::ImageAssetWrapper::clearExplicitCells()
{
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

bool IJWLayer::ImageAssetWrapper::addExplicitCell(int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, String^ cellName)
{
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

bool IJWLayer::ImageAssetWrapper::insertExplicitCell(int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, String^ cellName)
{
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

bool IJWLayer::ImageAssetWrapper::removeExplicitCell(int cellIdx)
{
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

bool IJWLayer::ImageAssetWrapper::setExplicitCell(int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, String^ cellName)
{
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

int IJWLayer::ImageAssetWrapper::getExplicitCellCount()
{
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

String^ IJWLayer::ImageAssetWrapper::getExplicitCellOffset(int cellIdx)
{
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

String^ IJWLayer::ImageAssetWrapper::getExplicitCellOffset(String^ cellName)
{
   const char* _cellName = (char*)Marshal::StringToHGlobalAnsi(cellName).ToPointer();
   // Using cell name.
   ImageAsset::FrameArea& frameRegion = GetObjectPtr()->getCellByName(_cellName);

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

int IJWLayer::ImageAssetWrapper::getExplicitCellWidth(int cellIdx)
{
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

int IJWLayer::ImageAssetWrapper::getExplicitCellWidth(String^ cellName)
{
   const char* _cellName = (char*)Marshal::StringToHGlobalAnsi(cellName).ToPointer();
   // Using cell name.
   ImageAsset::FrameArea& frameRegion = GetObjectPtr()->getCellByName(_cellName);

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

int IJWLayer::ImageAssetWrapper::getExplicitCellHeight(int cellIdx)
{
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

int IJWLayer::ImageAssetWrapper::getExplicitCellHeight(String^ cellName)
{
   const char* _cellName = (char*)Marshal::StringToHGlobalAnsi(cellName).ToPointer();
   // Using cell name.
   ImageAsset::FrameArea& frameRegion = GetObjectPtr()->getCellByName(_cellName);

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

String^ IJWLayer::ImageAssetWrapper::getExplicitCellName(int cellIdx)
{
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

int IJWLayer::ImageAssetWrapper::getExplicitCellIndex(String^ cellName)
{
   const char* _cellName = (char*)Marshal::StringToHGlobalAnsi(cellName).ToPointer();
   return GetObjectPtr()->getExplicitCellIndex(_cellName);
}