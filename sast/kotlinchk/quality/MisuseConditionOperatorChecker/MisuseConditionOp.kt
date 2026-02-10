package testcase.rule.quality.MisuseConditionOperatorChecker

object TestCase {
    enum class Role {
        ADMIN, EDITOR, VIEWER
    }

    fun comparisionTest(s: String, role: Role, i: Int) {
        if (s === "admin") { // @violation
            println("auth")
        } else if (s !== "guest") { // @violation
            println("bye")
        }

        if (i === 1) {  // @violation
            println("one")
        }

        if (role === Role.ADMIN) { // good
            println("enum admin")
        }

        if (role === null) { // good
            println("null")
        }
    }

    fun containsTest(t: String) {
        val s = "superadmin"

        if ("admin" in s) { // @violation
            println("1")
        }

        if (s in t) {       // good
            println("2")
        }
    }
}