package ti;

import java.io.IOException;
import java.io.InputStream;

class DO_NOT_LET_EXTERNAL_PROCESSES_BLOCK_ON_IO_BUFFERS_TestCase {
    void test() throws IOException {
        Runtime rt = Runtime.getRuntime();
        Process proc = rt.exec("notemaker");
        int exitVal = proc.exitValue(); /* BUG */
    }

    void test2() throws IOException, InterruptedException {
        Runtime rt = Runtime.getRuntime();
        Process proc = rt.exec("notemaker");
        int exitVal = proc.waitFor(); /* BUG */
    }

    void test3() throws IOException, InterruptedException {
        ProcessBuilder pb = new ProcessBuilder("notemaker");
        Process proc = pb.start();
        int exitVal = proc.waitFor(); /* BUG */
    }

    void testSafe() throws IOException, InterruptedException {
        ProcessBuilder pb = new ProcessBuilder("notemaker");
        pb = pb.redirectErrorStream(true);
        Process proc = pb.start();
        InputStream is = proc.getInputStream();
        int c;
        while ((c = is.read()) != -1) {
            System.out.print((char) c);
        }
        int exitVal = proc.waitFor();
    }
}