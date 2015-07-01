using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Types;
using Torque6_Bridge.Utility;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class GuiControlProfile : SimObject
   {
      public GuiControlProfile()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiControlProfileCreateInstance());
      }

      public GuiControlProfile(uint pId) : base(pId)
      {
      }

      public GuiControlProfile(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiControlProfile(string pName) : base(pName)
      {
      }

      public GuiControlProfile(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiControlProfileGetTab(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetTab(IntPtr controlProfile, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiControlProfileGetCanKeyFocus(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetCanKeyFocus(IntPtr controlProfile, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiControlProfileGetMouseOverSelected(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetMouseOverSelected(IntPtr controlProfile, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiControlProfileGetModal(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetModal(IntPtr controlProfile, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiControlProfileGetOpaque(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetOpaque(IntPtr controlProfile, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetFillColor(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFillColor(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetFillColorHL(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFillColorHL(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetFillColorNA(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFillColorNA(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiControlProfileGetBorder(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetBorder(IntPtr controlProfile, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiControlProfileGetBorderThickness(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetBorderThickness(IntPtr controlProfile, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetBorderColor(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetBorderColor(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetBorderColorHL(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetBorderColorHL(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetBorderColorNA(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetBorderColorNA(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetBevelColorHL(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetBevelColorHL(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetBevelColorLL(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetBevelColorLL(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string GuiControlProfileGetFontType(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFontType(IntPtr controlProfile, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiControlProfileGetFontSize(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFontSize(IntPtr controlProfile, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiControlProfileGetFontCharset(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFontCharset(IntPtr controlProfile, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetFontColors(IntPtr controlProfile, int index, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFontColors(IntPtr controlProfile, int index, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetFontColor(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFontColor(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetFontColorHL(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFontColorHL(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetFontColorNA(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFontColorNA(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetFontColorSEL(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFontColorSEL(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetFontColorLink(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFontColorLink(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetFontColorLinkHL(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetFontColorLinkHL(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiControlProfileGetJustify(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetJustify(IntPtr controlProfile, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiControlProfileGetTextOffset(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetTextOffset(IntPtr controlProfile, IntPtr value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiControlProfileGetAutoSizeWidth(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetAutoSizeWidth(IntPtr controlProfile, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiControlProfileGetAutoSizeHeight(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetAutoSizeHeight(IntPtr controlProfile, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiControlProfileGetReturnTab(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetReturnTab(IntPtr controlProfile, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiControlProfileGetNumbersOnly(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetNumbersOnly(IntPtr controlProfile, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileGetCursorColor(IntPtr controlProfile, out ColorI outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetCursorColor(IntPtr controlProfile, ColorI value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string GuiControlProfileGetBitmap(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetBitmap(IntPtr controlProfile, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiControlProfileGetSoundButtonDown(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetSoundButtonDown(IntPtr controlProfile, IntPtr value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiControlProfileGetSoundButtonOver(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetSoundButtonOver(IntPtr controlProfile, IntPtr value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiControlProfileGetProfileForChildren(IntPtr controlProfile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiControlProfileSetProfileForChildren(IntPtr controlProfile, IntPtr value);


      }
      #endregion

      #region Properties

      public bool Tab
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetTab(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetTab(ObjectPtr->ObjPtr, value);
         }
      }
      public bool CanKeyFocus
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetCanKeyFocus(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetCanKeyFocus(ObjectPtr->ObjPtr, value);
         }
      }
      public bool MouseOverSelected
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetMouseOverSelected(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetMouseOverSelected(ObjectPtr->ObjPtr, value);
         }
      }
      public bool Modal
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetModal(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetModal(ObjectPtr->ObjPtr, value);
         }
      }
      public bool Opaque
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetOpaque(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetOpaque(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI FillColor
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetFillColor(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFillColor(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI FillColorHL
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetFillColorHL(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFillColorHL(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI FillColorNA
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetFillColorNA(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFillColorNA(ObjectPtr->ObjPtr, value);
         }
      }
      public int Border
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetBorder(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetBorder(ObjectPtr->ObjPtr, value);
         }
      }
      public int BorderThickness
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetBorderThickness(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetBorderThickness(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI BorderColor
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetBorderColor(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetBorderColor(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI BorderColorHL
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetBorderColorHL(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetBorderColorHL(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI BorderColorNA
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetBorderColorNA(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetBorderColorNA(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI BevelColorHL
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetBevelColorHL(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetBevelColorHL(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI BevelColorLL
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetBevelColorLL(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetBevelColorLL(ObjectPtr->ObjPtr, value);
         }
      }
      public string FontType
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetFontType(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFontType(ObjectPtr->ObjPtr, value);
         }
      }
      public int FontSize
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetFontSize(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFontSize(ObjectPtr->ObjPtr, value);
         }
      }
      public int FontCharset
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetFontCharset(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFontCharset(ObjectPtr->ObjPtr, value);
         }
      }

      public FieldVector<ColorI> FontColors
      {
         get
         {
            return new FieldVector<ColorI>(this, 10, InternalUnsafeMethods.GuiControlProfileGetFontColors,
               InternalUnsafeMethods.GuiControlProfileSetFontColors);
         }
      }
      public ColorI FontColor
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetFontColor(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFontColor(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI FontColorHL
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetFontColorHL(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFontColorHL(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI FontColorNA
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetFontColorNA(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFontColorNA(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI FontColorSEL
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetFontColorSEL(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFontColorSEL(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI FontColorLink
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetFontColorLink(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFontColorLink(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI FontColorLinkHL
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetFontColorLinkHL(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetFontColorLinkHL(ObjectPtr->ObjPtr, value);
         }
      }
      public int Justify
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetJustify(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetJustify(ObjectPtr->ObjPtr, value);
         }
      }
      public IntPtr TextOffset
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetTextOffset(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetTextOffset(ObjectPtr->ObjPtr, value);
         }
      }
      public bool AutoSizeWidth
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetAutoSizeWidth(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetAutoSizeWidth(ObjectPtr->ObjPtr, value);
         }
      }
      public bool AutoSizeHeight
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetAutoSizeHeight(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetAutoSizeHeight(ObjectPtr->ObjPtr, value);
         }
      }
      public bool ReturnTab
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetReturnTab(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetReturnTab(ObjectPtr->ObjPtr, value);
         }
      }
      public bool NumbersOnly
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetNumbersOnly(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetNumbersOnly(ObjectPtr->ObjPtr, value);
         }
      }
      public ColorI CursorColor
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            ColorI outVal;
            InternalUnsafeMethods.GuiControlProfileGetCursorColor(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetCursorColor(ObjectPtr->ObjPtr, value);
         }
      }
      public string Bitmap
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetBitmap(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetBitmap(ObjectPtr->ObjPtr, value);
         }
      }
      public IntPtr SoundButtonDown
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetSoundButtonDown(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetSoundButtonDown(ObjectPtr->ObjPtr, value);
         }
      }
      public IntPtr SoundButtonOver
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetSoundButtonOver(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetSoundButtonOver(ObjectPtr->ObjPtr, value);
         }
      }
      public IntPtr ProfileForChildren
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiControlProfileGetProfileForChildren(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiControlProfileSetProfileForChildren(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion
      
      #region Methods

      #endregion
   }
}