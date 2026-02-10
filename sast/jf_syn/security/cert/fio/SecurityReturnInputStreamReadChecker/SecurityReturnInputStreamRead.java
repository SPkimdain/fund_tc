public class SecurityReturnInputstreamRead {
    public void test() {
        FileInputStreamReader in;
        // initialize stream
        byte data;
        while ((data = (byte) in.read()) != -1) {           // @violation
            // ...
        }
    }

    public void test2() {
        FileInputStream in;
        // initialize stream
        int inbuff;
        byte data;
        while ((inbuff = in.read()) != -1) {                /* Safe */
            data = (byte) inbuff;
            // ...
        }
    }

    public void test3() {
        FileReader in;
        // initialize stream
        char data;
        while ((data = (char) in.read()) != -1) {           // @violation
            // ...
        }
    }

    public void test4() {
        FileReader in;
        // initialize stream
        int inbuff;
        char data;
        while ((inbuff = in.read()) != -1) {                /* Safe */
            data = (char) inbuff;
            // ...
        }
    }

    public void test5() {
        FileReader in;
        // initialize stream
        int inbuff;
        char data;
        while (((inbuff = in.read()) != -1) && ((data = (char) in.read()) != -1)) {                // @violation
            data = (char) inbuff;
            // ...
        }

        while (((inbuff = in.read())) && ((data = (char) in.read()) != 2)) {                /* Safe */
            data = (char) inbuff;
            // ...
        }
    }
}