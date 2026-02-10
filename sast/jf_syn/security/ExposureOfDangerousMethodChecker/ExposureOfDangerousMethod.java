package security;

public class ExposureOfDangerousMethod {

    public void dangerousMethod() { // @violation
        // Do something dangerous things ...
    }

    private void privateCall() {
        // ...
        dangerousMethod();
    }

    public void publicCall() {
        // ...
        dangerousMethod(); // @violation
    }
}
