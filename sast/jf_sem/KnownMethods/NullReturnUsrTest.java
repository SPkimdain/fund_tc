package knownMethods;

public class NullReturnUsrTest {
    public void test() {
        String str = NullReturnUsrLibrary.getString();
        // Below code may cause null dereference exception. (NULL_RETURN_USR)
        str.toUpperCase(); /* BUG */
    }

}
