using System;

namespace DesignLibrary
{
   public sealed class SealedClass
   {
      // const
      protected const int x = 0; // @violation
      const int y = 0; // @safe

      // field
      int z = 0; // @safe
      protected int a = 0; // @violation
      public string name = ""; // @safe
      public int age = ""; // @safe
      private String[] arr = new String[100]; // @safe
      private String[] arr1 = new String[100];// @safe

      // constructor
      protected SealedClass() {}  // @violation
      public SealedClass(String s) {} // @safe

      // property
      protected string Name { // @violation
        get {
            return name;
        }
      }
      int Age {
        get {
            return age;
        }
      }

      // event
      public event EventHandler ShapeChanged; // @safe
      protected event EventHandler ShapeModified; // @violation

      // indexer
      public String this[int i] // @safe
      {
        get
        {
            return arr[i];
        }
        set
        {
            arr[i] = value;
        }
      }
      protected String this[int i] // @violation
      {
        get
        {
            return arr1[i];
        }
        set
        {
            arr1[i] = value;
        }
      }

      // method
      protected void ProtectedMethod(){}  // @violation
      void NonProtectedMethod(){}  // @safe
      protected virtual void Finalize() {} // @safe

      // type
      protected class NestedType // @violation
      {
            public NestedType()
            {
            }
      }
      class NestedType1 // @safe
      {
            public NestedType1()
            {
            }
      }

   }
}