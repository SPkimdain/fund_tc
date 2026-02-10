package testcase.rule.security.AndroidSensitiveToImplicitBroadcastChecker

import android.app.Activity
import android.content.Intent

object SensitiveBroadcast {
    class MyActivity: Activity {
        fun explicit() {
            val password = getUserInput()

            val intent: Intent = Intent(this, AnotherActivity::class.java)  // explicit intent
            intent.putExtra("key", password)        // propagated
            sendBroadcast(intent)                   // broadcast but ok
        }

        fun explicit2() {
            val password = getUserInput()

            val intent: Intent = Intent("com.example.ACTION_UPDATE")        // implicit intent
            intent.setClass(this, AnotherActivity::class.java)              // turn to explicit intent
            intent.putExtra("key", password)                                // not propagated
            sendBroadcast(intent)
        }

        fun explicit3() {
            val password = getUserInput()

            val intent: Intent = Intent("com.example.ACTION_UPDATE")        // implicit intent
            intent.putExtra("key", password)                                // propagated
            intent.setClass("test.package.name", "AnotherActivity")         // filtered: turn to explicit intent
            sendBroadcast(intent)
        }

        fun implicit() {
            val password = getUserInput()

            val intent: Intent = Intent("com.example.ACTION_UPDATE")        // implicit intent
            intent.putExtra("key", password)        // propagated
            sendBroadcast(intent)                   // @violation
        }

        fun implicit2() {
            val password = getUserInput()

            val intent: Intent = Intent(Intent.ACTION_VIEW, Uri.parse("https://sparrow.im/"))   // implicit intent
            intent.putExtra("key", password)        // propagated
            sendBroadcast(intent)                   // @violation
        }
    }

    class AnotherActivity: Activity {

    }
}