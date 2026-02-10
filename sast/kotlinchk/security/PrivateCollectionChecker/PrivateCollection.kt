package testcase.rule.security.PrivateCollectionChecker

object TestCase {
	/**
	 * Check 'private'
	 */
	class PrivateViolation1 {
		private val colors : Array<String> = arrayOf("red", "orange", "black", "white", "blue")

		fun getColors(): Array<String> {
			return colors;																					// @violation
		}
	}
	fun privateViolationTest1() {
		val color = PrivateViolation1()
		println(color.getColors().contentToString())														// [red, orange, black, white, blue]
		val data: Array<String> = color.getColors()
		data[0] = "none"
		println(color.getColors().contentToString())														// [none, orange, black, white, blue]
	}

	class PrivateViolation2 {
		private val colors = mutableListOf("red", "orange", "black", "white", "blue")

		public fun getColors(): MutableList<String> {
			return colors;																					// @violation
		}
	}
	fun privateViolationTest2() {
		val color = PrivateViolation2()
		println(color.getColors())																			// [red, orange, black, white, blue]
		val data: MutableList<String> = color.getColors()
		data[0] = "none"
		println(color.getColors())																			// [none, orange, black, white, blue]
	}

	class PrivateViolation3 {
		private val colors = mutableSetOf("red", "orange", "black", "white", "blue")

		fun getColors(): MutableSet<String> {
			return colors;																					// @violation
		}
	}
	fun privateViolationTest3() {
		val color = PrivateViolation3()
		println(color.getColors())																			// [red, orange, black, white, blue]
		val data: MutableSet<String> = color.getColors()
		data.remove("red")
		data.add("none")
		println(color.getColors())																			// [orange, black, white, blue, none]
	}

	class PrivateViolation4 {
		private val colors = mutableMapOf(1 to "red", 2 to "orange", 3 to "black", 4 to "white", 5 to "blue")

		fun getColors(): MutableMap<Int, String> {
			return colors;																					// @violation
		}
	}
	fun privateViolationTest4() {
		val color = PrivateViolation4()
		println(color.getColors())																			// {1=red, 2=orange, 3=black, 4=white, 5=blue}
		val data: MutableMap<Int, String> = color.getColors()
		data[1] = "none"
		println(color.getColors())																			// {1=none, 2=orange, 3=black, 4=white, 5=blue}
	}

	/**
	 *	Check 'val'
	 */
	class ValViolation1 {
		val colors : Array<String> = arrayOf("red", "orange", "black", "white", "blue")						// @violation
	}
	fun valViolationTest1() {
		val color = ValViolation1()
		println(color.colors.contentToString())																// [red, orange, black, white, blue]
		val data: Array<String> = color.colors
		data[0] = "none"
		println(color.colors.contentToString())																// [none, orange, black, white, blue]
	}

	class ValViolation2 {
		val colors = mutableListOf("red", "orange", "black", "white", "blue")								// @violation
	}
	fun valViolationTest2() {
		val color = ValViolation2()
		println(color.colors)																				// [red, orange, black, white, blue]
		val data: MutableList<String> = color.colors
		data[0] = "none"
		println(color.colors)																				// [none, orange, black, white, blue]
	}

	class ValViolation3 {
		val colors = mutableSetOf("red", "orange", "black", "white", "blue")								// @violation
	}
	fun valViolationTest3() {
		val color = ValViolation3()
		println(color.colors)																				// [red, orange, black, white, blue]
		val data: MutableSet<String> = color.colors
		data.remove("red")
		data.add("none")
		println(color.colors)																				// [orange, black, white, blue, none]
	}

	class ValViolation4 {
		val colors = mutableMapOf(1 to "red", 2 to "orange", 3 to "black", 4 to "white", 5 to "blue")		// @violation
	}
	fun valViolationTest4() {
		val color = ValViolation4()
		println(color.colors)																				// {1=red, 2=orange, 3=black, 4=white, 5=blue}
		val data: MutableMap<Int, String> = color.colors
		data[1] = "none"
		println(color.colors)																				// {1=none, 2=orange, 3=black, 4=white, 5=blue}
	}

	/**
	 * Check 'private'
	 */
	class PrivateGood1() {
		private val colors : Array<String> = arrayOf("red", "orange", "black", "white", "blue")

		fun getColors(): Array<String> {
			return colors.clone()																			// good
		}
	}
	fun privateGoodTest1() {
		val color = PrivateGood1()
		println(color.getColors().contentToString())														// [red, orange, black, white, blue]
		val data: Array<String> = color.getColors()
		data[0] = "none"
		println(color.getColors().contentToString())														// [red, orange, black, white, blue]
	}

	class PrivateGood2() {
		private val colors : MutableList<String> = mutableListOf("red", "orange", "black", "white", "blue")

		fun getColors(): MutableList<String> {
			return this.colors.toMutableList()																// good
		}
	}
	fun privateGoodTest2() {
		val color = PrivateGood2()
		println(color.getColors())																			// [red, orange, black, white, blue]
		val data: MutableList<String> = color.getColors()
		data.remove("red")
		data.add("none")
		println(color.getColors())																			// [red, orange, black, white, blue]
	}

	class PrivateGood3 {
		private val colors = mutableSetOf("red", "orange", "black", "white", "blue")

		fun getColors(): MutableSet<String> {
			return this.colors.toMutableSet()																// good
		}
	}
	fun privateGoodTest3() {
		val color = PrivateGood3()
		println(color.getColors())																			// [red, orange, black, white, blue]
		val data: MutableSet<String> = color.getColors()
		data.remove("red")
		data.add("none")
		println(color.getColors())																			// [red, orange, black, white, blue]
	}

	class PrivateGood4 {
		private val colors = mutableMapOf(1 to "red", 2 to "orange", 3 to "black", 4 to "white", 5 to "blue")

		fun getColors(): MutableMap<Int, String> {
			return this.colors.toMutableMap()																// good
		}
	}
	fun privateGoodTest4() {
		val color = PrivateGood4()
		println(color.getColors())																			// {1=red, 2=orange, 3=black, 4=white, 5=blue}
		val data: MutableMap<Int, String> = color.getColors()
		data[1] = "none"
		println(color.getColors())																			// {1=red, 2=orange, 3=black, 4=white, 5=blue}
	}

	class PrivateGood5 {
		private val colors : Array<String> = arrayOf("red", "orange", "black", "white", "blue")

		private fun getColors1(): Array<String> {
			return colors;																					// good
		}

		protected fun getColors2(): Array<String> {
			return colors;																					// good
		}
	}
	
	/**
	 * Check 'val'
	 */
	class ValGood1() {
		val colors : Array<String> = arrayOf("red", "orange", "black", "white", "blue")
			get() {
				return field.clone()																		// good
			}
	}
	fun valGoodTest1() {
		val color = ValGood1()
		println(color.colors.contentToString())																// [red, orange, black, white, blue]
		val data: Array<String> = color.colors
		data[0] = "none"
		println(color.colors.contentToString())																// [red, orange, black, white, blue]
	}

	class ValGood2() {
		val colors : MutableList<String> = mutableListOf("red", "orange", "black", "white", "blue")
			get() = field.toMutableList()																	// good
	}
	fun valGoodTest2() {
		val color = ValGood2()
		println(color.colors)																				// [red, orange, black, white, blue]
		val data: MutableList<String> = color.colors
		data.remove("red")
		data.add("none")
		println(color.colors)																				// [red, orange, black, white, blue]
	}

	class ValGood3 {
		val colors = mutableSetOf("red", "orange", "black", "white", "blue")
			get() {
				return field.toMutableSet()																	// good
			}
	}
	fun valGoodTest3() {
		val color = ValGood3()
		println(color.colors)																				// [red, orange, black, white, blue]
		val data: MutableSet<String> = color.colors
		data.remove("red")
		data.add("none")
		println(color.colors)																				// [red, orange, black, white, blue]
	}

	class ValGood4 {
		val colors = mutableMapOf(1 to "red", 2 to "orange", 3 to "black", 4 to "white", 5 to "blue")
			get() = field.toMutableMap()																	// good
	}
	fun valGoodTest4() {
		val color = ValGood4()
		println(color.colors)																				// {1=red, 2=orange, 3=black, 4=white, 5=blue}
		val data: MutableMap<Int, String> = color.colors
		data[1] = "none"
		println(color.colors)																				// {1=red, 2=orange, 3=black, 4=white, 5=blue}
	}
}