import java.lang.SecurityManager;

class SecurityCallSecurityCheck {
    Hashtable<Integer,String> ht = new Hashtable<Integer,String>();

    void removeEntry(Object key) {
        check("removeKeyPermission");                           /* Safe */
        ht.remove(key);
    }

    public void removeEntry(Object key, String name) {          // @violation
        ht.remove(key);
    }

    private void check(String directive) {
        SecurityManager sm = System.getSecurityManager();

        if (sm != null) {  // check whether file may be read
            sm.checkRead("/local/schema.dtd");                  // @violation
        }

        if (sm != null) {  //check whether file can be read or not
            DTDPermission perm = new DTDPermission("/local/",  "readDTD");
            sm.checkPermission(perm);                           /* Safe */
        }
    }
}