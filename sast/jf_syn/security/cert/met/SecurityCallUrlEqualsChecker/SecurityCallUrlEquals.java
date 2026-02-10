public class Filter {
    public static void main(String[] args) throws MalformedURLException {
        final URL allowed = new URL("http://mailwebsite.com");
        if (!allowed.equals(new URL(args[0]))) {                // @violation
            throw new SecurityException("Access Denied");
        }
        // Else proceed
    }
}

public class Filter2 {
    public static void main(String[] args) throws MalformedURLException, URISyntaxException {
        final URL allowed = new URL("http://mailwebsite.com");
        if (!allowed.equals(new URL(args[0]))) {              /* Safe */
            throw new SecurityException("Access Denied");
        }
        // Else proceed
    }
}