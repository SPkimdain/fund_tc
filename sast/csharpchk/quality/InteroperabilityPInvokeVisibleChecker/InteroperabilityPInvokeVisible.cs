using System;
using System.Runtime.InteropServices;

namespace InteroperabilityLibrary
{
    // Violates rule: PInvokesShouldNotBeVisible.
    public class ViolationNativeMethods
    {
        [DllImport("kernel32.dll", CharSet = CharSet.Unicode)] // @violation
        public static extern bool RemoveDirectory(string name);
    }

    private class GoodNativeMethods
    {
        [DllImport("kernel32.dll", CharSet = CharSet.Unicode)] // good
        public static extern bool RemoveDirectory(string name);
    }
}