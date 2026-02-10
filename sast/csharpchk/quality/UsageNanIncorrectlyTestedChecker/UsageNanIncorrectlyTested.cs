using System;

namespace UsageLibrary
{
   class NaNTests
   {
      static double zero;

      static void Main()
      {
         Console.WriteLine( 0/zero == double.NaN ); // @violation
         Console.WriteLine( 0/zero != double.NaN ); // @violation
         Console.WriteLine( double.IsNaN(0/zero) );
      }
   }
}