package cc;

public class CombinedIncrementAndDecrementOperator {

    private int func(int s) {
        return s++;
    }

    public void test(int v1, int v2) {
        int goodVal, badVal;
        ++v1;
        v2--;

        goodVal = v1 + v2;
        goodVal = func(++v1);

        badVal = ++v1 + v2--; // @violation 2
        badVal = func(++v2 + v1--); // @violation 2
    }
}