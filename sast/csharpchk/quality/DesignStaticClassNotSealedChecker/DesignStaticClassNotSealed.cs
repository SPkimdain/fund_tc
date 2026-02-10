using System;

namespace DesignLibrary
{
    public class StaticMembers // @violation
    {
        static int someField;

        public static int SomeProperty
        {
            get
            {
                return someField;
            }
            set
            {
                someField = value;
            }
        }

        StaticMembers() {}

        public static void SomeMethod() {}
    }
    public static class StaticMembersSafe
     {
         private static int someField;

         public static int SomeProperty
         {
             get { return someField; }
             set { someField = value; }
         }

         public static void SomeMethod()
         {
         }

         public static event SomeDelegate SomeEvent;
     }
}