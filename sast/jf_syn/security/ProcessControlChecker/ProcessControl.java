public class ProcessControl {

    public void test () {
        System.loadLibrary("test.dll"); // @violation
    }

    public void test () {
        String libName = "test.dll";
        System.loadLibrary(libName); // @violation
    }
}
