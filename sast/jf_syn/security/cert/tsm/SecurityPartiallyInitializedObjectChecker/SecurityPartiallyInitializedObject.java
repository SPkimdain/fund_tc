package security;

public class SecurityPartiallyInitializedObject {
    public class Helper {
        private int n;

        public Helper(int n) {
            this.n = n;
        }
        // ...
    }

    class DangerousFoo {
        private Helper helper;

        public Helper getHelper() {
            return helper;
        }

        public void initialize() { // @violation
            helper = new Helper(42);
        }
    }
}