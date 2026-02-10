package testcase.rule.quality.TrivialDeadCodeChecker

import kotlin.system.exitProcess

object TestCase {
    private fun imDead() {                  // @violation
        println("testament")
    }

    private fun notDead(s: String) {
        println("dying message: " + s)
    }

    private fun halt(): Nothing {
        throw RuntimeException("halt")
    }

    fun violation() {
        return
        println("deadcode")     // @violation
    }

    fun violation2(b: Boolean) {
        for (i in 1 .. 10) {
            if (i == 4) {
                break
                println(4)      // @violation
            }
            println("not dead")
        }
        println("not dead")
        for (i in 1 .. 10) {
            if (i == 4) {
                continue
                println(4)      // @violation
            }
        }

        if (b) {
            halt()
            println("dead")         // @violation
        }

        notDead("test")
    }

    fun violation3(b: Boolean, c: Boolean) {
        if (b) {
            error("Boom")
            println("dead")         // @violation
        } else {
            if (c) {
                TODO("todo")
                println("dead")     // @violation
            }
        }
        exitProcess(0)
        println("daed")     // @violation
    }
}