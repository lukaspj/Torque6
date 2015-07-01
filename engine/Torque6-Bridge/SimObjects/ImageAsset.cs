using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class ImageAsset : AssetBase
   {
      public ImageAsset()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.ImageAssetCreateInstance());
      }

      public ImageAsset(uint pId) : base(pId)
      {
      }

      public ImageAsset(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public ImageAsset(string pName) : base(pName)
      {
      }

      public ImageAsset(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetImageFile(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetImageFile(IntPtr imageAsset, string imageFile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetGetForce16bit(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetForce16bit(IntPtr imageAsset, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetFilterMode(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetFilterMode(IntPtr imageAsset, string filterMode);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetGetExplicitMode(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetExplicitMode(IntPtr imageAsset, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetGetCellRowOrder(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetCellRowOrder(IntPtr imageAsset, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellOffsetX(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetCellOffsetX(IntPtr imageAsset, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellOffsetY(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetCellOffsetY(IntPtr imageAsset, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellStrideX(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetCellStrideX(IntPtr imageAsset, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellStrideY(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetCellStrideY(IntPtr imageAsset, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellCountX(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetCellCountX(IntPtr imageAsset, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellCountY(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetCellCountY(IntPtr imageAsset, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellWidth(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetCellWidth(IntPtr imageAsset, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellHeight(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ImageAssetSetCellHeight(IntPtr imageAsset, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ImageAssetCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetImageWidth(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetImageHeight(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetImageSize(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetGetIsImagePOT(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetFrameCount(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetFrameSize(IntPtr imageAsset, int frame);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetClearExplicitCells(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetAddExplicitCell(IntPtr imageAsset, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetInsertExplicitCell(IntPtr imageAsset, int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetRemoveExplicitCell(IntPtr imageAsset, int cellIdx);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetSetExplicitCell(IntPtr imageAsset, int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellCount(IntPtr imageAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetExplicitCellOffset(IntPtr imageAsset, int cellIdx);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetExplicitCellOffsetByName(IntPtr imageAsset, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellWidth(IntPtr imageAsset, int cellIdx);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellWidthByName(IntPtr imageAsset, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellHeight(IntPtr imageAsset, int cellIdx);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellHeightByName(IntPtr imageAsset, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetExplicitCellName(IntPtr imageAsset, int cellIdx);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellIndex(IntPtr imageAsset, string cellName);


      }
      #endregion

      #region Properties

      public string ImageFile
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetImageFile(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetImageFile(ObjectPtr->ObjPtr, value);
         }
      }
      public bool Force16bit
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetForce16bit(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetForce16bit(ObjectPtr->ObjPtr, value);
         }
      }
      public string FilterMode
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetFilterMode(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetFilterMode(ObjectPtr->ObjPtr, value);
         }
      }
      public bool ExplicitMode
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetExplicitMode(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetExplicitMode(ObjectPtr->ObjPtr, value);
         }
      }
      public bool CellRowOrder
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetCellRowOrder(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetCellRowOrder(ObjectPtr->ObjPtr, value);
         }
      }
      public int CellOffsetX
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetCellOffsetX(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetCellOffsetX(ObjectPtr->ObjPtr, value);
         }
      }
      public int CellOffsetY
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetCellOffsetY(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetCellOffsetY(ObjectPtr->ObjPtr, value);
         }
      }
      public int CellStrideX
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetCellStrideX(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetCellStrideX(ObjectPtr->ObjPtr, value);
         }
      }
      public int CellStrideY
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetCellStrideY(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetCellStrideY(ObjectPtr->ObjPtr, value);
         }
      }
      public int CellCountX
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetCellCountX(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetCellCountX(ObjectPtr->ObjPtr, value);
         }
      }
      public int CellCountY
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetCellCountY(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetCellCountY(ObjectPtr->ObjPtr, value);
         }
      }
      public int CellWidth
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetCellWidth(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetCellWidth(ObjectPtr->ObjPtr, value);
         }
      }
      public int CellHeight
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetCellHeight(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetCellHeight(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion
      
      #region Methods

      public void GetImageWidth()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetImageWidth(ObjectPtr->ObjPtr);
      }

      public void GetImageHeight()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetImageHeight(ObjectPtr->ObjPtr);
      }

      public void GetImageSize()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetImageSize(ObjectPtr->ObjPtr);
      }

      public void GetIsImagePOT()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetIsImagePOT(ObjectPtr->ObjPtr);
      }

      public void GetFrameCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetFrameCount(ObjectPtr->ObjPtr);
      }

      public void GetFrameSize(int frame)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetFrameSize(ObjectPtr->ObjPtr, frame);
      }

      public void ClearExplicitCells()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetClearExplicitCells(ObjectPtr->ObjPtr);
      }

      public void AddExplicitCell(int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetAddExplicitCell(ObjectPtr->ObjPtr, cellOffsetX, cellOffsetY, cellWidth, cellHeight, cellName);
      }

      public void InsertExplicitCell(int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetInsertExplicitCell(ObjectPtr->ObjPtr, cellIndex, cellOffsetX, cellOffsetY, cellWidth, cellHeight, cellName);
      }

      public void RemoveExplicitCell(int cellIdx)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetRemoveExplicitCell(ObjectPtr->ObjPtr, cellIdx);
      }

      public void SetExplicitCell(int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetSetExplicitCell(ObjectPtr->ObjPtr, cellIndex, cellOffsetX, cellOffsetY, cellWidth, cellHeight, cellName);
      }

      public void GetExplicitCellCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetExplicitCellCount(ObjectPtr->ObjPtr);
      }

      public void GetExplicitCellOffset(int cellIdx)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetExplicitCellOffset(ObjectPtr->ObjPtr, cellIdx);
      }

      public void GetExplicitCellOffsetByName(string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetExplicitCellOffsetByName(ObjectPtr->ObjPtr, cellName);
      }

      public void GetExplicitCellWidth(int cellIdx)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetExplicitCellWidth(ObjectPtr->ObjPtr, cellIdx);
      }

      public void GetExplicitCellWidthByName(string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetExplicitCellWidthByName(ObjectPtr->ObjPtr, cellName);
      }

      public void GetExplicitCellHeight(int cellIdx)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetExplicitCellHeight(ObjectPtr->ObjPtr, cellIdx);
      }

      public void GetExplicitCellHeightByName(string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetExplicitCellHeightByName(ObjectPtr->ObjPtr, cellName);
      }

      public void GetExplicitCellName(int cellIdx)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetExplicitCellName(ObjectPtr->ObjPtr, cellIdx);
      }

      public void GetExplicitCellIndex(string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ImageAssetGetExplicitCellIndex(ObjectPtr->ObjPtr, cellName);
      }

      #endregion
   }
}