package cc;

public class DoNotUseHardCodingNumber {
    private final int RADIUS = 10; /* SAFE since it is a final variable initialization */
    private final int APPROXIMATED_PI = 3; /* SAFE since it is a final variable initialization */

    private int badCircle = 10 * 10 * 3; // @violation 3
    private int goodCircle = RADIUS * RADIUS * APPROXIMATED_PI;

    private String[] array = new String[10];                // @violation
    private String[] array2 = new String[RADIUS];           /* Safe */

    public int func(int x) {
        if(x > 0) {
            return -1; /* SAFE since it is excluded */
        } else {
            return 17; // @violation
        }

        for(int b = 2; b < c; b++) {}                   /* Safe */
        for(int i = 2; i < 20; i++) {}                  // @violation
    }
}
