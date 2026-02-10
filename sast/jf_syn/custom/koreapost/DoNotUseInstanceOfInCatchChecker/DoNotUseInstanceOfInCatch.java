import java.io.*;

class DoNotUseIOWithoutBufferProcessing {
    public void violation() {
        try {
            File file1 = new File("D:\\text1.txt");
            FileInputStream input = new FileInputStream(file1);
            int i = input.read();
            // ...
        } catch (Exception e) {
            if(e instanceof FileNotFoundException) {    // @violation
                // ...
            }
            else if(e instanceof IOException) {         // @violation
                // ...
            }
        }
    }

    public void good() {
        try {
            File file1 = new File("D:\\text1.txt");
            FileInputStream input = new FileInputStream(file1);
            int i = input.read();
            // ...
        } catch (FileNotFoundException e) {             /* SAFE */
            // ...
        } catch (IOException e) {                       /* SAFE */
            // ...
        }
    }
}