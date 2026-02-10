package cc;

public class Capital {
    public static final int GOOD;
    private static final int bad; // @violation
    public static final int GOOD_NUMBER1; /* SAFE */
    public static final int A1; /* SAFE */
}
