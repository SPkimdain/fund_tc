package cc;

public class ForbiddenNullInSecurityManager {
    public class SecurityManagerBad1 {
        void func() {
            SecurityManager s = new SecurityManager();
            System.setSecurityManager(null);        // @violation
        }
    }

    public class SecurityManagerGood1 {
        void func() {
            SecurityManager s = new SecurityManager();
            System.setSecurityManager(s);           // good
        }
    }
}
