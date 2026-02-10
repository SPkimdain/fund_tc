using System;
using System.Runtime.InteropServices;

[assembly: ComVisible(true)]
namespace InteroperabilityLibrary
{
    [ClassInterface(ClassInterfaceType.AutoDual)] // @violation
    public class DualInterface
    {
        public void SomeMethod() {}
    }

    public interface IExplicitInterface
    {
        void SomeMethod();
    }

    [ClassInterface(ClassInterfaceType.None)]
    public class ExplicitInterface : IExplicitInterface
    {
        public void SomeMethod() {}
    }
}