package ti;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

class USE_A_SUBSET_OF_ASCII_FOR_FILE_AND_PATH_NAMES_TestCase {
    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
            // Handle error
        }
        String filename = args[0];

        Pattern pattern =
                Pattern.compile("[^A-Za-z0-9%&+,.:=_]");
        Matcher matcher = pattern.matcher(filename);
        if (matcher.find()) {
            // File name contains bad chars; handle error
        }
        File f = new File(filename);
        OutputStream out = new FileOutputStream(f);
        out.close();
        // ...

        String filename2 = args[1];
        File f2 = new File(filename2);
        OutputStream out2 = new FileOutputStream(f2); /* BUG */
        out2.close();
    }

    OutputStream testSafe() throws Exception {
        File f = new File("name.ext");
        OutputStream out = new FileOutputStream(f);
        return out;
    }

    OutputStream test() throws Exception {
        File f = new File("A\uD8AB");
        OutputStream out = new FileOutputStream(f); /* BUG */
        return out;
    }
}