package cc;

import java.lang.Exception;

public class MissingFinallyInTryCatch {
    public void func() {
        try {
            // Do something ...
        } // @violation

        try {
            // Do something ...
        } catch(Exception e) {
            // Do something ...
        } // @violation

        try {
            try {
                // Do something ...
            } catch(ArrayIndexOutOfBoundsException aibe) {
                // Do something ...
            } // @violation
        } catch(IOException ioe) {
            // Do something ...
        } finally {
            // Do something ...
        }

        try (Scanner scanner = new Scanner(new File("input.txt"))) {
            // Do something ...
        } catch (FileNotFoundException e) {
            // Do somthing ...
        } finally {

        }
    }
}
