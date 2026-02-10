public class SecurityCompareClassName {

    public BadCompareClassName() {
        // Determine whether object auth has required/expected class object
        if (auth.getClass().getName().equals(                               // @violation
                "com.application.auth.DefaultAuthenticationHandler")) {
            // ...
        }

        // Determine whether object auth has required/expected class name
        if (auth.getClass() == com.application.auth.DefaultAuthenticationHandler.class) {   /* Safe */
            // ...
        }
    }

    public void getTest() {
        // Determine whether object auth has required/expected class object
        if (auth.getClass().getName().equals(                               // @violation
                "com.application.auth.DefaultAuthenticationHandler")) {
            // ...
        }

        // Determine whether object auth has required/expected class name
        if (auth.getClass() == com.application.auth.DefaultAuthenticationHandler.class) {   /* Safe */
            // ...
        }
    }
}