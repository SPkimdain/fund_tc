package nd;

class StaticVarTest {
    static String x;
    void assign() {
        if(x == null) {
            x = "not null";
        }
    }
    void notAssign() {
        if(x == null) {
            System.out.println("x is null!");
        }
    }
    void safeTest() {
        assign();
        x.toString();
        notAssign();
        x.toUpperCase();
    }
    void bugTest() {
        notAssign();
        x.toString(); /* BUG */
    }
}