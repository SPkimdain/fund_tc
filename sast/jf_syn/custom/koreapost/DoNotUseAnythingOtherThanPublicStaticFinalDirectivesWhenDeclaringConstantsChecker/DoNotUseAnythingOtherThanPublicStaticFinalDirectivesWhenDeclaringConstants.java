package custom;

public class DoNotUseAnythingOtherThanPublicStaticFinalDirectivesWhenDeclaringConstants {
    public int ON_FLAG_1 = 1;                   /* SAFE */
    public final int ON_FLAG_2 = 2;             /* SAFE */
    public static int ON_FLAG_3 = 3;            /* SAFE */
    private static final int ON_FLAG_4 = 4;     // @violation
    public static final int ON_FLAG_5 = 5;      /* SAFE */
    public final static int ON_FLAG_6 = 6;      /* SAFE */
    public int on_flag_7 = 1;                   /* SAFE */
    public final int On_flag_8 = 2;             /* SAFE */
    public static int on_flag_9 = 3;            /* SAFE */
    private static final int on_flag_10 = 4;    // @violation
    public static final int on_flag_11 = 5;     /* SAFE */
    public final static int on_flag_12 = 6;     /* SAFE */
}
