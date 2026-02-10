package nd;

public class SuppressFollowersTest {
    String g = "unknown";
    void foo() {
        String x = null;
        if(g != null) { System.out.println("dummy"); }
        System.out.println("dummy");

        x.toUpperCase(); /* BUG */
        x.toUpperCase();
        g.toUpperCase(); /* BUG */
        x.toUpperCase();
        g.toUpperCase();
        g.toUpperCase();
    }
    void bar() {
        String x = returnNull();
        assumeNull(g);

        g.toLowerCase(); /* BUG */
        g.toLowerCase();
        x.toLowerCase(); /* BUG */
        x.toLowerCase();
        nullTrigger(x);
    }
    String returnNull() {
        return null;
    }
    void assumeNull(String x) {
        if(x != null) { System.out.println("dummy"); }
    }
    void nullTrigger(String x) {
        x.toUpperCase();
    }
}
