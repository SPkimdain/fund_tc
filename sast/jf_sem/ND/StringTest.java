package nd;

class StringTest {
    /* Code from DRMONEBL package */
    String returnStringOver10(int i) {
        String x = "i'm string";
        String y = null;
        if(i > 10) return x;
        else return y;
    }
    void equalsSemantics(Double d) {
        String x = null;
        if(d == null) {
            x = "NULL";
        } else {
            x = "NONNULL";
        }
        if(x.equals("NONNULL")) {
            d.toString();
        }
    }
    void stringConShouldntNull() {
        String x = returnStringOver10(11);
        if(x == null) {
            System.out.println("this is invalid path");
        }
        x.toUpperCase();
        String y = returnStringOver10(9);
        if(y != null) {
            System.out.println("this is invalid path");
        }
        y.toUpperCase(); /* BUG */
    }
}