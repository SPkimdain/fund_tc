package toctou;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class SafeFileReadThread2 extends Thread {
    private static final Object countLock = new Object();
    public void run(String file) { // Caution: Actually TOCTOU is irrelevant to thread
        try {
            synchronized (countLock) { /* BUG */ // resource leak
                File f = new File(file);
                if (!f.exists()) { // file exist check
                    return;
                }
                BufferedReader br = new BufferedReader(new FileReader(f));
                br.readLine(); /* SAFE */
                br.close();
            }
        } catch (IOException e) { }
    }
}
