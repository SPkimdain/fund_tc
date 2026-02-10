public class SecurityCallSystemGetenv {
    private String name;

    public ForbiddenCallSystemGetenv() {
        this.name = System.getenv("USER");            // @violation
    }

    public void test() {
        String username = System.getenv("USER");            // @violation
    }
}