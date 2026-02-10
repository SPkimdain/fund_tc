using System;
namespace NamingLibrary
{
    public class Class1	// IdentifiersShouldDifferByMoreThanCase
    {
        protected string someProperty; // @violation

        public string SomeProperty
        {
            get { return someProperty; }
        }
    }
}