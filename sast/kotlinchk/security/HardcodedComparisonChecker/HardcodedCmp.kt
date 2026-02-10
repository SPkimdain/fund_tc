package testcase.rule.security.HardcodedComparisonChecker

object TestCase {
    fun test(password: String, pin: Int) {
        if (password == "password@!") {         // @violation
            println("ok")
        }

        if ("password@!" == password) {         // @violation
            println("ok")
        }

        if (pin == 123456) {                    // @violation
            println("pass")
        }
        if (987654 == otp) {                    // @violation
            println("pass")
        }

        val passw0rd = someUnknownInputFunction()

        if ("password".equals(passw0rd)) { // @violation
            println("ok")
        }

        if (passw0rd.equals("PASSWORD", true)) {   // @violation
            println("ok")
        }

        val secret = otherUnknownInputFunction()

        if (secret.compareTo("68af40...") == 0) {       // @violation
            println("auth")
        }

        if ("68af40...".compareTo(secret) == 0) {       // @violation
            println("auth")
        }

        val p = "password@!"
        if (password == p) {                            // @violation
            println("ok")
        }
    }
}