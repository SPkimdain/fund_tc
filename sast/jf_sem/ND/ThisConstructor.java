package nd;

public class ThisConstructor {

    private String ff = null;

    public ThisConstructor(String s) {
        ff="notnull";
    }

    public ThisConstructor(String s, int i) {
        this(s);
    }

    public int foo() {
        ThisConstructor tt = new ThisConstructor("a", 1);
        String s1 = tt.ff;
        int y = s1.length(); /* SAFE */
        return y;
    }
}