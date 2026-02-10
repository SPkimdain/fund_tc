package security;

public class MissingPasswordRecoveryControl {

    private void recoverPassword() {
        for(int i=0; i<10; i++) {
            // Recover password here ...
        }
    }

    private void anotherrecoverPassword() {
        int i;
        while(i < 10) {
            // Recover password here ...
        }
    }

    private void another2recoverPassword() {
        int i;
        do {
            // Recover password here ...
        } while(i < 10);
    }

    private void another3recoverPassword() {
        for(;;) { // @violation
            // Recover password here ...
        }
    }

    private void another4recoverPassword() {
        int i;
        while(((true))) { // @violation
            // Recover password here ...
            i++;
        }
    }

    public void func1() {
        recoverPassword(); // @violation
    }

    public void func2() {
        for(int i=0; i<10; i++) {
            recoverPassword();
        }
    }

    public void func3() {
        int i;
        while(i < 10) {
            recoverPassword();
            i++;
        }
    }

    public void func4() {
        for(int i=0; true; i++) {
            recoverPassword(); // @violation
        }
    }

    public void func5() {
        int i;
        while(((true))) {
            recoverPassword(); // @violation
            i++;
        }
    }

    public void func6() {
        do {
            recoverPassword(); // @violation
        } while(true);
    }
}
