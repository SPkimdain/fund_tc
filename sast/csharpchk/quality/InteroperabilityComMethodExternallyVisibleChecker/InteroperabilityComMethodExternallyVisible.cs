using System;
using System.Runtime.InteropServices;

[assembly: ComVisible(true)]
namespace InteroperabilityLibrary
{
    public class ComRegistration
    {
        [ComRegisterFunction] // @violation
        public static void RegisterFunction(Type typeToRegister) {}

        [ComUnregisterFunction] // @violation
        public static void UnregisterFunction(Type typeToRegister) {}
    }

    public class ClassToRegister
    {
        [ComRegisterFunction] // @safe
        internal static void RegisterFunction(Type typeToRegister) {}

        [ComUnregisterFunction] // @safe
        private static void UnregisterFunction(Type typeToRegister) {}
    }
}
