package ti;

import java.net.HttpCookie;
import java.util.ArrayList;
import java.util.List;

class DEFENSIVELY_COPY_MUTABLE_INPUTS_AND_MUTABLE_INTERNAL_COMPONENTS_TestCase {
    // java.net.HttpCookie is mutable
    public void useMutableInput(HttpCookie cookie) {
        if (cookie == null) {
            throw new NullPointerException();
        }

        // Check whether cookie has expired
        if (cookie.hasExpired()) { /* BUG */
            // Cookie is no longer valid, handle condition by throwing an exception
        }

        // Cookie may have expired since time of check
        doLogic(cookie);
    }

    // java.net.HttpCookie is mutable
    public void safelyUseMutableInput(HttpCookie cookie) {
        if (cookie == null) {
            throw new NullPointerException();
        }

        // Create copy
        cookie = (HttpCookie)cookie.clone();

        // Check whether cookie has expired
        if (cookie.hasExpired()) {
            // Cookie is no longer valid, handle condition by throwing an exception
        }

        doLogic(cookie);
    }

    private void doLogic(HttpCookie cookie) {
    }

    private static void copyInterfaceInput(ArrayList<String> collection) {
        // Convert input to trusted implementation
        collection.get(0);          /* BUG */

        collection = new ArrayList(collection);
        collection.get(0);
    }

    public static void main(String[] args) {
        copyInterfaceInput(new ArrayList<String>());
    }
}