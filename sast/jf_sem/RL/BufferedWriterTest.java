package rl;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class BufferedWriterTest {
    public void test() {
        BufferedWriter out = null;
        try{
            out = new BufferedWriter(new FileWriter(new File("test.txt")));
            out.write("This is test.");
            out.newLine();
        } catch (IOException e) {
			// ...
        }
    } /* BUG */
}
