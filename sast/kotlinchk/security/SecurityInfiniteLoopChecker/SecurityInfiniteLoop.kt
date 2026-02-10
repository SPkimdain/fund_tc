package testcase.rule.security.SecurityInfiniteLoopChecker

object TestCase {
	fun violation1() {
		while(true) {					// @violation
			println("Hello World")
		}
	}

	fun violation2() {
		do {
			println("Hello World")
		}
		while(true)						// @violation
	}

	fun violation3() {
		val flag = true
		while(flag) {					// @violation
			println("Hello World")
		}
	}

	fun violation4() {
		val flag = true
		do {
			println("Hello World")
		}
		while(flag)						// @violation
	}

	fun violation5() {
		while(true) {					// @violation
			while(true) {				// @violation
				println("Hello World")
			}
		}
	}

	fun violation6(n: Int) {
		var index = n
		while(true) {					// @violation
			while(true) {
				if(index <= 10) {
					break				// good
					break				// nop
				}
				println("Hello World")
				index--
			}
		}
	}

	fun violation7(n: Int) {
		var index = n
		while(true) {					// @violation
			while(index < 10) {
				println("Hello World")
				index++
			}
		}
	}

    fun violation8() {
        var index = 0
        while(true) {                       // @violation
            while(true) {                   // @violation
                here@ while(index < 10) {
                    while(true) {
                        while(true) {
                            break@here
                        }
                    }
                    ++index;
                }
            }
        }
    }

    fun violation9() {
        for (i in generateSequence(0) { it + 1 }) {     // @violation
            println(i)
        }
    }

    fun violation10() {
        generateSequence(0) { it + 1 }                  // @violation
            .forEach { println(it) }
    }

    fun good1(n: Int) {
		var index = n
		while(true) {
			if(n <= 10) {
				break					// good
			}
			println("Hello World")
			index--
		}
	}

	fun good2() {
		while(true) {
			println("Hello World")
			break						// good
		}
	}

	fun good3(n: Int) {
		var index = n
		do {
			if(index <= 10) {
				break					// good
			}
			println("Hello World")
			index--
		}
		while(true)
	}

	fun good4() {
		do {
			println("Hello World")
			break						// good
		}
		while(true)
	}

	fun good5() {
		while(true) {
			println("Hello World")
			Thread.sleep(1000)			// good
		}
	}

    fun good6() {
        generateSequence(0) { it + 1 }  // good
            .take(5)
            .forEach { println(it) }
    }

    fun good7() {
        for (i in generateSequence(0) { it + 1 }) {     // good
            println(i)
            if (i >= 10) break
        }
    }

    class CustomThread : Thread() {
		var flag = false

		override fun run() {
			while(true) {
				if(flag) {
					println("Custom Thread is working..")
				}
				else {
					Thread.yield()		// good
				}
			}
		}
	}
}