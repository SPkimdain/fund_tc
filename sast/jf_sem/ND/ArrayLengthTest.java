package nd;

public class ArrayLengthTest {
    String str = "top";
    void arrayLengthAux() {
        if(str == null) {
            arrayLengthNonZero();
        }
    }
    void arrayLengthNonZero() {
        String[] nonZeroArray = new String[] {"a","b","c"};
        for(int i = 0; i < nonZeroArray.length; i++) {
            str = nonZeroArray[i];
        }
        str.toUpperCase();
    }
    void lengthOnNull() {
        String[] ary = null;
        if(ary.length > 0) { /* BUG */
            System.out.println("length > 0");
        } else {
            System.out.println("length <= 0");
        }
    }
}
