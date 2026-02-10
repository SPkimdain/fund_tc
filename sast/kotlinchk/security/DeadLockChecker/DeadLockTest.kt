package testcase.rule.security.DeadLockChecker

import kotlinx.coroutines.*

object TestCase {
    class Account {
        fun transfer(dest: Account, amount: Int) {
            synchronized(this) {                    // @violation
                synchronized(dest) {
                    println("to $dest: $amount")
                }
            }
        }
    }

    fun blockUiThread() {
        runBlocking(Dispatchers.Main) {             // @violation
            delay(1000)
        }
    }
}