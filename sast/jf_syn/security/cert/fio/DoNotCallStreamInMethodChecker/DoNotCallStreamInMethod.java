package security;

import java.util.*;
import java.io.*;

public final class DoNotCallStreamInMethod {
    public static char getChar() throws EOFException, IOException {
        BufferedInputStream in = new BufferedInputStream(System.in); // @violation
        int input = in .read();
        if (input == -1) {
            throw new EOFException();
        }
        return (char) input;
    }

    public static void getChar2() throws EOFException, IOException {
        Scanner sc = new Scanner(System.in); // @violation
        return;
    }
}