import java.io.*;

class DoNotUseIOWithoutBufferProcessing {
    public void violation() {
        try {
            File file1 = new File("D:\\text1.txt");
            File file2 = new File("D:\\text2.txt");

            FileInputStream input = new FileInputStream(file1);
            FileOutputStream output = new FileOutputStream(file2);

            int readBuffer = 0;
            byte [] buffer = new byte[512];
            while((readBuffer = input.read(buffer)) != -1) {        // @violation
                output.write(buffer, 0, readBuffer);                // @violation
            }
        } catch (IOException e) {
        }
    }

    public void good() {
        try {
            File file1 = new File("D:\\text1.txt");
            File file2 = new File("D:\\text2.txt");

            FileInputStream fis = new FileInputStream(file1);
            BufferedInputStream input = new BufferedInputStream(fis);
            FileOutputStream fos = new FileOutputStream(file2);
            BufferedOutputStream output = new BufferedOutputStream(fos);

            int readBuffer = 0;
            byte [] buffer = new byte[512];
            while((readBuffer = input.read(buffer)) != -1) {        /* SAFE */
                output.write(buffer, 0, readBuffer);                /* SAFE */
            }
        } catch (IOException e) {
        }
    }
}