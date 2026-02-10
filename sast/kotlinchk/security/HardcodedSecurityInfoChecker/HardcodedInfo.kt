package testcase.rule.security.HardcodedSecurityInfoChecker

object TestCase {
    fun test() {
        var password = "password@!"             // @violation

        var pin = 123456                        // @violation

        val passw0rd = someUnknownInputFunction()

        val secret = otherUnknownInputFunction()

        val p = "password@!"
        if (password == p) {
            println("ok")
        }
    }
}