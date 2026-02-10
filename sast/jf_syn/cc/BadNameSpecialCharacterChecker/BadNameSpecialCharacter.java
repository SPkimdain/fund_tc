package cc;

public class BadNameSpecialCharacter {
    public int good_name;
    public int bad$name; // @violation

    public int good_method() {
        return 0;
    }

    public int bad$method() { // @violation
        return 0;
    }

    public int bad_param_method(int bad$param) { // @violation
        return 0;
    }

    public int func() {
        int good_local;
        int bad$local; // @violation
    }

    private class bad$class { // @violation
        // Something in here ...
    };
}
