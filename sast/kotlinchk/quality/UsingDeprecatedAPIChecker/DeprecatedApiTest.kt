package testcase.rule.quality.UsingDeprecatedAPIChecker

import android.content.Context
import android.hardware.Camera
import android.os.Environment
import java.lang.Thread
import java.util.Date

class TestThread: Thread {

}

object TestCase {
    fun violation() {
        val t = TestThread()
        t.resume()              // @violation

        val i = java.lang.Integer(10)       // @violation

        val d = Date(2025, 1, 1)  // @violation
    }

    fun violationAndroid() {
        val d = Environment.getExternalStorageDirectory()           // @violation
        val d2 = Environment.getExternalStoragePublicDirectory()    // @violation

        val c = Camera.open()                                       // @violation
        val c1 = Camera.open(1)                                     // @violation

        val i = Context.MODE_WORLD_READABLE                         // @violation
        val i2 = Context.MODE_WORLD_WRITEABLE                       // @violation
    }
}