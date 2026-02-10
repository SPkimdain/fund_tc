package cc;

public class BadIfBooleanVariableCondition {
    public BadIfBooleanVariableCondition() {

    }

    private boolean b1;
    public static boolean b2;

    public boolean test(boolean b3) {
        boolean b4;

        if (b1) { // @violation
            if (b2) { // @violation

            }
        } else if (!b3) { // @violation

        } else {
            if (b4) { // @violation

            }
        }

        if (b1 == true) { // good
            if (b4) { // @violation

            }
        }

        if (b2 == false) { // good

        }

        if (b3 && b4) { // good

        }

        switch (b1) {
            case true:
                break;
            case false:
                break;
        }

    }

    private boolean test2(boolean b5) {
        return b5 && true;
    }
}