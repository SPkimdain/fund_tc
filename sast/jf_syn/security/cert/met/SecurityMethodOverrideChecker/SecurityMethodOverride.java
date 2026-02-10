public class SecurityMethodOverride {
    public void readSensitiveFile() {   // @violation
        try {
            SecurityManager sm = System.getSecurityManager();
            if (sm != null) {
                sm.checkRead("/temp/tempFile");
            }
        } catch (SecurityException se) {
        }
    }
}