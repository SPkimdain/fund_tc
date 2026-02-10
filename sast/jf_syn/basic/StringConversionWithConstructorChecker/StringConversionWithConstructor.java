package basic;

public class StringConversionWithConstructor {

    public void func(int arg) {
        String badStr = new Integer(arg).toString(); // @violation
        String goodStr = Integer(arg).toString(); /* SAFE */
    }
}