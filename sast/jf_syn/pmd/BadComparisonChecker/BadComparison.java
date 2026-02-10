package src.test.java.pmd;

public class BadComparison {
    public void fun() {
        float x1 = 3.0f;
        boolean y1 = (x1 == Float.NaN); // @violation

        double x2 = 3.0;
        boolean y2 = (x2 == Double.NaN); // @violation

        int x3 = 3;
        boolean y3 = (x3 == x2);
    }
}