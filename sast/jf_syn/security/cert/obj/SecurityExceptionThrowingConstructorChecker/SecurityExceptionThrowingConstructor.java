public class SecurityExceptionThrowingConstructor {
    class DangerousBankOperations1 {
        public DangerousBankOperations() {
            if (!performSSNVerification()) {
                throw new SecurityException("Access Denied!"); // @violation
            }
        }

        private boolean performSSNVerification() {
            return false; // Returns true if data entered is valid, else false. Assume that the attacker always enters an invalid SSN.
        }

        public void greet() {
            System.out.println("Welcome user! You may now use all the features.");
        }
    }

    class DangerousBankOperations2 {
        public DangerousBankOperations() {
            if (!performSSNVerification()) { // @violation
                // Do something
            }
        }

        private boolean performSSNVerification() {
            if(verify()) {
                return true;
            } else {
                throw new SecurityException("Access Denied!");
            }
        }

        private boolean verify() {
            return false; // Returns true if data entered is valid, else false. Assume that the attacker always enters an invalid SSN.
        }

        public void greet() {
            System.out.println("Welcome user! You may now use all the features.");
        }
    }

    final class SafeBankOperations1 { // Safe since the class is final
        public SafeBankOperations1() {
            if (!performSSNVerification()) {
                throw new SecurityException("Access Denied!");
            }
        }

        private boolean performSSNVerification() {
            return false; // Returns true if data entered is valid, else false. Assume that the attacker always enters an invalid SSN.
        }

        public void greet() {
            System.out.println("Welcome user! You may now use all the features.");
        }
    }

    class SafeBankOperations2 {
        public SafeBankOperations2() { // Safe since the constructor is private
            if (!performSSNVerification()) {
                throw new SecurityException("Access Denied!");
            }
        }

        private boolean performSSNVerification() {
            return false; // Returns true if data entered is valid, else false. Assume that the attacker always enters an invalid SSN.
        }

        public void greet() {
            System.out.println("Welcome user! You may now use all the features.");
        }

        public final void finalize() {
            // do nothing
        }
    }

    class SafeBankOperations3 {
        public SafeBankOperations3() {
            this(performSSNVerification());
        }

        private SafeBankOperations(boolean secure) {
            // secure is always true
            // constructor without any security checks
        }

        private static boolean performSSNVerification() {
            // Returns true if data entered is valid, else throws a SecurityException
            // Assume that the attacker just enters invalid SSN; so this method always throws the exception
            throw new SecurityException("Invalid SSN!");
        }

        // ...remainder of BankOperations class definition
    }

    class SafeBankOperations4 {
        private volatile boolean initialized = false;

        public SafeBankOperations4() {
            if (!performSSNVerification()) {
                throw new SecurityException("Access Denied!");
            }
            this.initialized = true; // object construction successful
        }

        private boolean performSSNVerification() {
            return false; // Returns true if data entered is valid, else false. Assume that the attacker always enters an invalid SSN.
        }

        public void greet() {
            System.out.println("Welcome user! You may now use all the features.");
        }
    }
}