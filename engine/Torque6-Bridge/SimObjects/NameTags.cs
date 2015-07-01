using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class NameTags : SimSet
   {
      public NameTags()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.NameTagsCreateInstance());
      }

      public NameTags(uint pId) : base(pId)
      {
      }

      public NameTags(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public NameTags(string pName) : base(pName)
      {
      }

      public NameTags(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr NameTagsCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int NameTagsRenameTag(IntPtr nameTags, int tagId, string newTagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int NameTagsDeleteTag(IntPtr nameTags, int tagId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int NameTagsGetTagCount(IntPtr nameTags);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string NameTagsGetTagName(IntPtr nameTags, int tagId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int NameTagsGetTagId(IntPtr nameTags, string tagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string NameTagsGetAllTags(IntPtr nameTags);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool NameTagsTag(IntPtr nameTags, int objectId, int tagIdsC, int[] tagIdsV);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool NameTagsUntag(IntPtr nameTags, int objectId, int tagIdsC, int[] tagIdsV);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool NameTagsHasTags(IntPtr nameTags, int objectId, int tagIdsC, int[] tagIdsV);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string NameTagsQueryTags(IntPtr nameTags, int tagIdsC, int[] tagIdsV, bool excluded);


      }
      #endregion

      #region Properties


      #endregion
      
      #region Methods

      public void RenameTag(int tagId, string newTagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NameTagsRenameTag(ObjectPtr->ObjPtr, tagId, newTagName);
      }

      public void DeleteTag(int tagId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NameTagsDeleteTag(ObjectPtr->ObjPtr, tagId);
      }

      public void GetTagCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NameTagsGetTagCount(ObjectPtr->ObjPtr);
      }

      public void GetTagName(int tagId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NameTagsGetTagName(ObjectPtr->ObjPtr, tagId);
      }

      public void GetTagId(string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NameTagsGetTagId(ObjectPtr->ObjPtr, tagName);
      }

      public void GetAllTags()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NameTagsGetAllTags(ObjectPtr->ObjPtr);
      }

      public void Tag(int objectId, int tagIdsC, int[] tagIdsV)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NameTagsTag(ObjectPtr->ObjPtr, objectId, tagIdsC, tagIdsV);
      }

      public void Untag(int objectId, int tagIdsC, int[] tagIdsV)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NameTagsUntag(ObjectPtr->ObjPtr, objectId, tagIdsC, tagIdsV);
      }

      public void HasTags(int objectId, int tagIdsC, int[] tagIdsV)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NameTagsHasTags(ObjectPtr->ObjPtr, objectId, tagIdsC, tagIdsV);
      }

      public void QueryTags(int tagIdsC, int[] tagIdsV, bool excluded)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NameTagsQueryTags(ObjectPtr->ObjPtr, tagIdsC, tagIdsV, excluded);
      }

      #endregion
   }
}