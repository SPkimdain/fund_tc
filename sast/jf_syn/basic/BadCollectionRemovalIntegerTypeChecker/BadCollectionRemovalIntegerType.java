package basic;

import java.util.HashSet;

public class BadCollectionRemovalIntegerType {

    public void badFunc() {
        HashSet set = new HashSet();
        short s = 10;
        set.add(s);
        set.remove(10); // @violation
        set.remove((s+1)-1); // @violation
        set.remove(s+s); /* SAFE */
    }

    public void goodFunc() {
        HashSet set = new HashSet();
        short s = 10;
        set.add(s);
        set.remove((short)10); /* SAFE */
    }
}