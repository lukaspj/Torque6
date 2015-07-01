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

      internal new struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ImageAssetCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetImageFile(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetSetImageFile(IntPtr pObjectPtr, string val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetFilterMode(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetSetFilterMode(IntPtr pObjectPtr, string val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetGetForce16Bit(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetSetForce16Bit(IntPtr pObjectPtr, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetGetCellRowOrder(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetSetCellRowOrder(IntPtr pObjectPtr, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellOffsetX(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetSetCellOffsetX(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellOffsetY(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetSetCellOffsetY(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellStrideX(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetSetCellStrideX(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellStrideY(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetSetCellStrideY(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellCountX(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetSetCellCountX(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellCountY(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetSetCellCountY(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellWidth(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetSetCellWidth(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetCellHeight(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetSetCellHeight(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetImageWidth(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetSetImageWidth(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetImageHeight(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetSetImageHeight(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetImageSize(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetSetImageSize(IntPtr pObjectPtr, string val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetGetIsImagePOT(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetSetIsImagePOT(IntPtr pObjectPtr, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetFrameCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetSetFrameCount(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetFrameSize(IntPtr pObjectPtr, int frame);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetClearExplicitCells(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetAddExplicitCell(IntPtr pObjectPtr, int cellOffsetX, int cellOffsetY,
            int cellWidth, int cellHeight, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetInsertExplicitCell(IntPtr pObjectPtr, int cellIndex, int cellOffsetX,
            int cellOffsetY, int cellWidth, int cellHeight, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetRemoveExplicitCell(IntPtr pObjectPtr, int cellIdx);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ImageAssetSetExplicitCell(IntPtr pObjectPtr, int cellIndex, int cellOffsetX,
            int cellOffsetY, int cellWidth, int cellHeight, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetExplicitCellOffset(IntPtr pObjectPtr, int cellIdx);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetExplicitCellOffsetByName(IntPtr pObjectPtr, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellWidth(IntPtr pObjectPtr, int cellIdx);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellWidthByName(IntPtr pObjectPtr, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellHeight(IntPtr pObjectPtr, int cellIdx);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellHeightByName(IntPtr pObjectPtr, string cellName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ImageAssetGetExplicitCellName(IntPtr pObjectPtr, int cellIdx);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ImageAssetGetExplicitCellIndex(IntPtr pObjectPtr, string cellName);
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

      public bool Force16Bit
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetForce16Bit(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetForce16Bit(ObjectPtr->ObjPtr, value);
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

      public int ImageWidth
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetImageWidth(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetImageWidth(ObjectPtr->ObjPtr, value);
         }
      }

      public int ImageHeight
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetImageHeight(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetImageHeight(ObjectPtr->ObjPtr, value);
         }
      }

      public string ImageSize
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetImageSize(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetImageSize(ObjectPtr->ObjPtr, value);
         }
      }

      public bool IsImagePOT
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetIsImagePOT(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetIsImagePOT(ObjectPtr->ObjPtr, value);
         }
      }

      public int FrameCount
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ImageAssetGetFrameCount(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ImageAssetSetFrameCount(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion

      #region Methods

      public string GetFrameSize(int frame)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetGetFrameSize(ObjectPtr->ObjPtr, frame);
      }

      public bool ClearExplicitCells()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetClearExplicitCells(ObjectPtr->ObjPtr);
      }

      public bool AddExplicitCell(int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetAddExplicitCell(ObjectPtr->ObjPtr, cellOffsetX, cellOffsetY, cellWidth,
            cellHeight, cellName);
      }

      public bool InsertExplicitCell(int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight,
         string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetInsertExplicitCell(ObjectPtr->ObjPtr, cellIndex, cellOffsetX,
            cellOffsetY, cellWidth, cellHeight, cellName);
      }

      public bool RemoveExplicitCell(int cellIdx)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetRemoveExplicitCell(ObjectPtr->ObjPtr, cellIdx);
      }

      public bool SetExplicitCell(int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight,
         string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetSetExplicitCell(ObjectPtr->ObjPtr, cellIndex, cellOffsetX, cellOffsetY,
            cellWidth, cellHeight, cellName);
      }

      public int GetExplicitCellCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetGetExplicitCellCount(ObjectPtr->ObjPtr);
      }

      public string GetExplicitCellOffset(int cellIdx)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetGetExplicitCellOffset(ObjectPtr->ObjPtr, cellIdx);
      }

      public string GetExplicitCellOffset(string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetGetExplicitCellOffsetByName(ObjectPtr->ObjPtr, cellName);
      }

      public int GetExplicitCellWidth(int cellIdx)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetGetExplicitCellWidth(ObjectPtr->ObjPtr, cellIdx);
      }

      public int GetExplicitCellWidth(string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetGetExplicitCellWidthByName(ObjectPtr->ObjPtr, cellName);
      }

      public int GetExplicitCellHeight(int cellIdx)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetGetExplicitCellHeight(ObjectPtr->ObjPtr, cellIdx);
      }

      public int GetExplicitCellHeight(string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetGetExplicitCellHeightByName(ObjectPtr->ObjPtr, cellName);
      }

      public string GetExplicitCellName(int cellIdx)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetGetExplicitCellName(ObjectPtr->ObjPtr, cellIdx);
      }

      public int GetExplicitCellIndex(string cellName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.ImageAssetGetExplicitCellIndex(ObjectPtr->ObjPtr, cellName);
      }

      #endregion
   }
}