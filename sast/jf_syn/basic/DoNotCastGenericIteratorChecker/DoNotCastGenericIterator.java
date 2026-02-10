package basic;

import java.util.Iterator;

public class DoNotCastGenericIterator {

    public void badFunc(List<String> values) {
        Iterator<String> iter = values.iterator();
        while (iter.hasNext()) {
            String s = (String)iter.next(); // @violation
            System.out.println(s);
        }
    }

    public void goodFunc(List<String> values) {
        Iterator<String> iter = values.iterator();
        Iterator iter2 = values.iterator();
        while (iter.hasNext()) {
            String s = iter.next(); /* SAFE */
            s = (String)iter2.next(); /* SAFE */
            System.out.println(s);
        }
    }
}