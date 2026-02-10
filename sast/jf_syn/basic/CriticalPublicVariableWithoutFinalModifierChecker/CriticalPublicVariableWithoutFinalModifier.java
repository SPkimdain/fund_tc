package basic;

public class CriticalPublicVariableWithoutFinalModifier {
    public static float price=500; // @violation
    public static final float safe1=0;
    public final static float safe2=0;

    public static int intField=1; // @violation
    public static long longField=1; // @violation
    public static String stringField=""; // @violation
    public float floatField=500;

    public float getTotal(int count) {
        return price*count;
    }
}
