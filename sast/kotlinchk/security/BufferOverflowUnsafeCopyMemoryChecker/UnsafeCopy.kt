package testcase.rule.security.BufferOverflowUnsafeCopyMemoryChecker

import sun.misc.Unsafe

object TestCase {
    fun violation() {
        val U1 = Unsafe.getUnsafe()

        val src1 = U1.allocateMemory(200L)
        val dest1 = U1.allocateMemory(100L)

        U1.copyMemory(null, src1, null, dest1, 200L)      // @violation

        val U2: sun.misc.Unsafe = try {
            val unsafeClass = Class.forName("sun.misc.Unsafe")
            val theUnsafeField = unsafeClass.getDeclaredField("theUnsafe")
            theUnsafeField.isAccessible = true
            theUnsafeField.get(null) as sun.misc.Unsafe
        } catch (e: Exception) {
            throw RuntimeException("fail")
        }

        val src2 = U2.allocateMemory(300L)
        val dest2 = U2.allocateMemory(500L)

        U2.copyMemory(null, src2, null, dest2, 600L)     // @violation

        U2.copyMemory(null, src2, null, dest2, 500L)     // good
    }
}