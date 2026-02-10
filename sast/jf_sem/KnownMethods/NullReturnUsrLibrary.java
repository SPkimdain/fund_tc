package knownMethods;

import java.util.Random;

public class NullReturnUsrLibrary {
    /**
     * Get string method
     * Below javadoc Tag, '@javafinch return=USR_NULL' indicate this method is user implemented not standard library.
     * And it might return null literal. You can also use '@return' javadoc tag with 'null' string.
     * When you pass the option such as -javadoc_dir with appropriate directory name,
     * Java analyzer reads the directory including subdirectories and parses the javadoc in the source files.
     * After parsing the javadoc, it inputs the semantics of each methods to the Java analyzer.
     * @javafinch return=USR_NULL
     */
    public static String getString() {
        int random = new Random().nextInt(10) + 1; // random number between 1 and 10
        if (random > 5) {
            return "abcdefg";
        } else {
            return null;
        }
    }
}