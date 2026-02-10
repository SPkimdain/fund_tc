package toctou;

import java.io.File;

public class SafeFileDeleteThread extends Thread {
    public synchronized void run() { // Caution: Actually TOCTOU is irrelevant to thread
        File f = new File("Test_367.txt");
        if (f.exists()) { // file exist check
            f.delete(); /* SAFE */ // file delete
        }
    }
}

