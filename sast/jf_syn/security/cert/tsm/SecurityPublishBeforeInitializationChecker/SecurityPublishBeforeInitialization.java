final class SecurityPublishBeforeInitialization {
    public static Publisher published;
    public static volatile Publisher published2;
    int num;
    String str;

    SecurityPublishBeforeInitialization(int number, String str) {
        // Initialization
        this.num = number;
        // ...
        published = this;

        published2 = this;
        // Initialization
        this.str = str;                             // @violation
    }
}