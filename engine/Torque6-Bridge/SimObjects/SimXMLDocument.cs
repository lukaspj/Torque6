using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class SimXMLDocument : SimObject
   {
      public SimXMLDocument()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.SimXMLDocumentCreateInstance());
      }

      public SimXMLDocument(uint pId) : base(pId)
      {
      }

      public SimXMLDocument(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public SimXMLDocument(string pName) : base(pName)
      {
      }

      public SimXMLDocument(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr SimXMLDocumentCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentReset(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimXMLDocumentLoadFile(IntPtr xmlDocument, string fileName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimXMLDocumentSaveFile(IntPtr xmlDocument, string fileName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimXMLDocumentParse(IntPtr xmlDocument, string textXML);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentClear(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimXMLDocumentGetErrorDesc(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentClearError(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimXMLDocumentPushFirstChildElement(IntPtr xmlDocument, string name);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimXMLDocumentPushChildElement(IntPtr xmlDocument, int index);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimXMLDocumentNextSiblingElement(IntPtr xmlDocument, string name);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimXMLDocumentElementValue(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentPopElement(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimXMLDocumentAttribute(IntPtr xmlDocument, string attribute);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern float SimXMLDocumentAttributeF32(IntPtr xmlDocument, string attribute);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int SimXMLDocumentAttributeS32(IntPtr xmlDocument, string attribute);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimXMLDocumentAttributeExists(IntPtr xmlDocument, string attribute);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimXMLDocumentFirstAttribute(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimXMLDocumentLastAttribute(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimXMLDocumentNextAttribute(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimXMLDocumentPrevAttribute(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentSetAttribute(IntPtr xmlDocument, string attribute, string attributeValue);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentSetObjectAttributes(IntPtr xmlDocument, string attributeValue);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentPushNewElement(IntPtr xmlDocument, string name);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentAddNewElement(IntPtr xmlDocument, string name);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentAddHeader(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentAddComment(IntPtr xmlDocument, string comment);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimXMLDocumentReadComment(IntPtr xmlDocument, int index);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentAddText(IntPtr xmlDocument, string text);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimXMLDocumentGetText(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentRemoveText(IntPtr xmlDocument);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimXMLDocumentAddData(IntPtr xmlDocument, string text);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimXMLDocumentGetData(IntPtr xmlDocument);
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      public void Reset()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentReset(ObjectPtr->ObjPtr);
      }

      public void LoadFile(string fileName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentLoadFile(ObjectPtr->ObjPtr, fileName);
      }

      public void SaveFile(string fileName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentSaveFile(ObjectPtr->ObjPtr, fileName);
      }

      public void Parse(string textXML)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentParse(ObjectPtr->ObjPtr, textXML);
      }

      public void Clear()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentClear(ObjectPtr->ObjPtr);
      }

      public void GetErrorDesc()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentGetErrorDesc(ObjectPtr->ObjPtr);
      }

      public void ClearError()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentClearError(ObjectPtr->ObjPtr);
      }

      public void PushFirstChildElement(string name)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentPushFirstChildElement(ObjectPtr->ObjPtr, name);
      }

      public void PushChildElement(int index)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentPushChildElement(ObjectPtr->ObjPtr, index);
      }

      public void NextSiblingElement(string name)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentNextSiblingElement(ObjectPtr->ObjPtr, name);
      }

      public void ElementValue()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentElementValue(ObjectPtr->ObjPtr);
      }

      public void PopElement()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentPopElement(ObjectPtr->ObjPtr);
      }

      public void Attribute(string attribute)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentAttribute(ObjectPtr->ObjPtr, attribute);
      }

      public void AttributeF32(string attribute)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentAttributeF32(ObjectPtr->ObjPtr, attribute);
      }

      public void AttributeS32(string attribute)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentAttributeS32(ObjectPtr->ObjPtr, attribute);
      }

      public void AttributeExists(string attribute)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentAttributeExists(ObjectPtr->ObjPtr, attribute);
      }

      public void FirstAttribute()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentFirstAttribute(ObjectPtr->ObjPtr);
      }

      public void LastAttribute()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentLastAttribute(ObjectPtr->ObjPtr);
      }

      public void NextAttribute()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentNextAttribute(ObjectPtr->ObjPtr);
      }

      public void PrevAttribute()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentPrevAttribute(ObjectPtr->ObjPtr);
      }

      public void SetAttribute(string attribute, string attributeValue)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentSetAttribute(ObjectPtr->ObjPtr, attribute, attributeValue);
      }

      public void SetObjectAttributes(string attributeValue)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentSetObjectAttributes(ObjectPtr->ObjPtr, attributeValue);
      }

      public void PushNewElement(string name)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentPushNewElement(ObjectPtr->ObjPtr, name);
      }

      public void AddNewElement(string name)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentAddNewElement(ObjectPtr->ObjPtr, name);
      }

      public void AddHeader()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentAddHeader(ObjectPtr->ObjPtr);
      }

      public void AddComment(string comment)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentAddComment(ObjectPtr->ObjPtr, comment);
      }

      public void ReadComment(int index)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentReadComment(ObjectPtr->ObjPtr, index);
      }

      public void AddText(string text)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentAddText(ObjectPtr->ObjPtr, text);
      }

      public void GetText()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentGetText(ObjectPtr->ObjPtr);
      }

      public void RemoveText()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentRemoveText(ObjectPtr->ObjPtr);
      }

      public void AddData(string text)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentAddData(ObjectPtr->ObjPtr, text);
      }

      public void GetData()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.SimXMLDocumentGetData(ObjectPtr->ObjPtr);
      }
      
      #endregion
   }
}