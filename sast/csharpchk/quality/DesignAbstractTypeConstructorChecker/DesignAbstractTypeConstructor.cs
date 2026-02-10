using System;

namespace Samples
{
    // Violates this rule
    public abstract class Book
    {
        public Book()               // @violation
        {
        }
    }

     public abstract class BookByBook
     {
         protected BookByBook()     // @safe
         {
         }
     }

}