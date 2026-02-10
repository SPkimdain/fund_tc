package toctou;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class SafeFileReadThread extends Thread {
    public synchronized void run() { // Caution: Actually TOCTOU is irrelevant to thread
        try {
            File f = new File("Test_367.txt");
            if (f.exists()) { // file exist check
                BufferedReader br = new BufferedReader(new FileReader(f));
                br.readLine(); /* SAFE */
                br.close();
            }
        } catch (IOException e) { }
    } /* BUG */ // resource leak
}
