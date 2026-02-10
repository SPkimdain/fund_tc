package basic;

import java.util.Collection;
import java.util.List;

/**
 * Rule: Forbidden Raw Type
 * @author Gyuhang Shim
 *
 * Raw Type들은 기술하지 않아야 한다.
 *
 */
public class NeverUseRawType {
    private List list;      // @violation
    private List<String> list2; /* not alarm */

    public void testLocalVariable() {
        Collection collection; // @violation
        Collection<String> collection2; /* not alarm */
    }

    public void testLoopVariable(List<String> [] lists) {
        for (List list1 : lists) { // @violation
            // do something
        }
        
        for (List<String> list2 : lists) { /* not alarm */
            // do something
        }
    }
}

/*  Good
    public class Foo {
        private List<String> list;
        // do something
    }
*/
