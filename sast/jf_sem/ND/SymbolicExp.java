package nd;

public class SymbolicExp {
    String ifEqualReturnNull(int x, int y) {
        if(x == y) {
            return null;
        } else {
            return "not null";
        }
    }
    String ifEqualReturnNull(String x, String y) {
        if(x == y) {
            return null;
        } else {
            return "not null";
        }
    }
    int plusOne(int x) {
        return x+1;
    }
    int plusTwo(int x) {
        return plusOne(x) + 1;
    }
    void test(int n) {
        String x = null;
        if(plusOne(6) == plusTwo(5)) x = "not null";
        x.toUpperCase(); /* BUG */ //FORWARD_NULL

        x = ifEqualReturnNull(1,2);
        x.toUpperCase();

        x = ifEqualReturnNull(1,1);
        x.toUpperCase(); /* BUG */ //NULL_RETURN

        String a = new String("asdf");
        String b = new String("zxcv");
        String c = a;

        x = ifEqualReturnNull(a,b);
        x.toString();

        x = ifEqualReturnNull(a,c);
        x.toString(); /* BUG */ // NULL_RETURN
    }
}
