
public class Filter {
    private static boolean keysEqual(Key key1, Key key2) {
        if (key1.equals(key2)) {            // @violation
            return true;
        }
        return false;
    }
}

public class Filter2 {
    private static boolean keysEqual(Key key1, Key key2) {
        if (key1.equals(key2)) {                            /* Safe */
            return true;
        }

        if (Arrays.equals(key1.getEncoded(), key2.getEncoded())) {
            return true;
        }

        // More code for different types of keys here.
        // For example, the following code can check if
        // an RSAPrivateKey and an RSAPrivateCrtKey are equal:
        if ((key1 instanceof RSAPrivateKey) &&
                (key2 instanceof RSAPrivateKey)) {

            if ((((RSAKey)key1).getModulus().equals(
                    ((RSAKey)key2).getModulus())) &&
                    (((RSAPrivateKey) key1).getPrivateExponent().equals(
                            ((RSAPrivateKey) key2).getPrivateExponent()))) {
                return true;
            }
        }
        return false;
    }
}