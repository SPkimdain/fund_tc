package findbugs;

public class FindBugs {
    // FORWARD_NULL
    int intra1(int level) {
        Object x = null;
        if (level > 0)
            x = new Object();
        if (level < /* > */ 4)
            return x.hashCode(); /* BUG */
        return 0;
    }
    // FORWARD_NULL
    int intra2(boolean b) {
        Object x = null;
        if (b)
            x = new Object();
        if (!b /* b */)
            return x.hashCode(); /* BUG */
        return 0;
    }
    // UNCHECKED_NULL
    int intra3(Object x) {
        Object y = null;
        if (x != null)
            y = new Object();
        if (y != null)
            return x.hashCode() + y.hashCode();
        else
            return x.hashCode() /* BUG */ ;
    }
    // FORWARD_NULL
    int intra4(boolean b) {
        Object x = null;
        Object y = null;
        if(b) x = "x";
        if(x != null) y = "y";
        if(y != null)
            return x.hashCode() + y.hashCode();
        else
            return x.hashCode() /* BUG */ ;
    }
    // UNCHECKED_NULL
    int intra5(Object x) {
        if (x == null) {
            return x.hashCode(); /* BUG */
        }
        return 0;
    }
    // UNCHECKED_NULL
    int intra6(Object x) {
        if (x == null) {
            Object y = x;
            return y.hashCode(); /* BUG */
        }
        return 0;
    }
    // FORWARD_NULL
    int inter1(boolean b) {
        Object x = null;
        if (b /* !b */ )
            x = new Object();
        return helper1(x,b); /* BUG */
    }
    // FORWARD_NULL
    int inter2() {
        return helper2(null); /* BUG */
    }
    // FORWARD_NULL
    int inter3(boolean b) {
        Object x = null;
        if(b)
            x = "x";
        return helper2(x); /* BUG */
    }

    private int helper1(Object x, boolean b) {
        if(b)
            return 0;
        return x.hashCode();
    }
    private int helper2(Object x) {
        return x.hashCode();
    }
}

