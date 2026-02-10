package testcase.rule.security.PublicDataAssignedToPrivateArrayChecker

object TestCase {
	class Violation1 {
		private lateinit var colors : Array<String?>

		public fun getColors(): Array<String?> {
			return this.colors
		}
		public fun setColors(colors: Array<String?>) {
			this.colors = colors							// @violation
		}
	}
	fun violationTest1() {
		val data: Array<String?> = arrayOf("red", "orange", "black", "white", "blue")
		val color = Violation1()
		color.setColors(data)
		println(color.getColors().contentToString())		// [red, orange, black, white, blue]
		data[0] = "none"
		println(color.getColors().contentToString())		// [red, orange, black, white, blue]
	}

	class Violation2 {
		private lateinit var colors : MutableList<String?>

		fun getColors(): MutableList<String?> {
			return this.colors
		}
		fun setColors(colors1: MutableList<String?>) {
			this.colors = colors1							// @violation
		}
	}
	fun violationTest2() {
		val data: MutableList<String?> = mutableListOf("red", "orange", "black", "white", "blue")
		val color = Violation2()
		color.setColors(data)
		println(color.getColors())							// [red, orange, black, white, blue]
		data[0] = "none"
		println(color.getColors())							// [red, orange, black, white, blue]
	}

	class Violation3 {
		private var colors = mutableListOf<String?>()

		fun getColors(): MutableList<String?> {
			return this.colors
		}
		fun setColors(colors1: MutableList<String?>) {
			colors = colors1								// @violation
		}
	}
	fun violationTest3() {
		val data: MutableList<String?> = mutableListOf("red", "orange", "black", "white", "blue")
		val color = Violation3()
		color.setColors(data)
		println(color.getColors())							// [red, orange, black, white, blue]
		data[0] = "none"
		println(color.getColors())							// [red, orange, black, white, blue]
	}

	class Good1 {
		private var colors : Array<String?> = arrayOf()

		fun getColors(): Array<String?> {
			return this.colors
		}
		fun setColors(color: Array<String?>) {
			this.colors = color.clone()						// good
		}
	}
	fun goodTest() {
		val data: Array<String?> = arrayOf("red", "orange", "black", "white", "blue")
		val color = Good1()
		color.setColors(data)
		println(color.getColors().contentToString())		// [red, orange, black, white, blue]
		data[0] = "none"
		println(color.getColors().contentToString())		// [red, orange, black, white, blue]
	}

	class Good2 {
		private var colors = mutableListOf<String?>()

		fun getColors(): MutableList<String?> {
			return this.colors
		}
		fun setColors(color: MutableList<String?>) {
			this.colors = color.toMutableList()				// good
		}
	}
	fun goodTest2() {
		val data: MutableList<String?> = mutableListOf("red", "orange", "black", "white", "blue")
		val color = Good2()
		color.setColors(data)
		println(color.getColors())							// [red, orange, black, white, blue]
		data[0] = "none"
		println(color.getColors())							// [red, orange, black, white, blue]
	}

	class Good3 {
		private lateinit var colors : Array<String?>

		private fun getColors(): Array<String?> {
			return this.colors
		}
		private fun setColors(colors: Array<String?>) {
			this.colors = colors							// good
		}
	}

	class Good4 {
		private lateinit var colors : Array<String?>

		protected fun getColors(): Array<String?> {
			return this.colors
		}
		protected fun setColors(colors: Array<String?>) {
			this.colors = colors							// good
		}
	}
}