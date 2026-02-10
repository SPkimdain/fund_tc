package security;

public class UnsynchronizedStaticDateFormatter {
    public final class Helper {
        private final int n;

        public Helper(int n) {
            this.n = n;
        }
        // ...
    }

    final class DangerousFoo {
        private Helper helper;

        public Helper getHelper() {
            return helper;
        }

        public void setHelper(int num) { // @violation
            helper = new Helper(num);
        }
    }

    final class SafeFoo1 { // Safe since it uses synchronized methods
        private Helper helper;

        public synchronized Helper getHelper() {
            return helper;
        }

        public synchronized void setHelper(int num) {
            helper = new Helper(num);
        }
    }

    final class SafeFoo2 { // Safe since it uses volatile fields
        private volatile Helper helper;

        public Helper getHelper() {
            return helper;
        }

        public void setHelper(int num) {
            helper = new Helper(num);
        }
    }
}