package basic;

public class EqualsMethodIsOverloaded {
    public boolean equals(String a) {          // @violation
        return true;
    }

    public boolean equals(Object obj, Object a) {       /* Safe */
        return true;
    }
}