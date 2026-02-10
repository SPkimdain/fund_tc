package cc;

public class LoadLibraryUsingAbsolutePath {
    public class LoadLibraryBad1 {
        private void func(String str) {
            String libName = "../abc/xyz/lib.jar";

            System.loadLibrary(libName);            // @violation
            System.loadLibrary("./test.dll");       // @violation
            System.loadLibrary("../test.dll");      // @violation
        }
    }
}