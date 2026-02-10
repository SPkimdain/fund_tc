package nd;

public class MethodOverloading {
    public int overloaded1(String s, int x, int y) {
        return x;
    }
    public int overloaded1(char c, int x, int y) {
        return y;
    }
    void test1() {
        String x = null;
        int result = overloaded1("1",4,2);
        if(result == 4) {
            x = "not null";
        }
        x.toUpperCase();

        x = null;
        result = overloaded1('2',3,1);
        if(result == 1) {
            x = "not null";
        }
        x.toUpperCase();
    }
}