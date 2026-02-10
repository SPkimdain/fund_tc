using System;
using System.Runtime.InteropServices;

[assembly: ComVisible(true)]
namespace InteroperabilityLibrary
{
    public class ComRegistration // @violation
    {
        [ComRegisterFunction]
        internal static void RegisterFunction(Type typeToRegister) {}

//        [ComUnregisterFunction]
//        internal static void UnregisterFunction(Type typeToRegister) {}
    }

    public class ClassToRegister // @safe
    {
        [ComRegisterFunction]
        internal static void RegisterFunction(Type typeToRegister) {}

        [ComUnregisterFunction]
        internal static void UnregisterFunction(Type typeToRegister) {}
    }
}