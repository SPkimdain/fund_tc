package testcase.rule.security.AndroidFDToImplicitBroadcastChecker

import android.app.Activity
import android.content.Intent
import android.os.ParcelFileDescriptor

object FileDescriptorBroadcast {
    class MyActivity: Activity {
        fun explicit() {
            val pfd = ParcelFileDescriptor.open(
                File(context.filesDir, "secret.txt"),
                ParcelFileDescriptor.MODE_READ_ONLY)

            val intent: Intent = Intent(this, AnotherActivity::class.java)  // explicit intent
            intent.putExtra("secret", pfd)          // propagated
            sendBroadcast(intent)                   // broadcast but ok
        }

        fun explicit2() {
            val pfd = ParcelFileDescriptor.open(
                File(context.filesDir, "secret.txt"),
                ParcelFileDescriptor.MODE_READ_ONLY)

            val intent: Intent = Intent("com.example.ACTION_UPDATE")        // implicit intent
            intent.setClass(this, AnotherActivity::class.java)              // turn to explicit intent
            intent.putExtra("secret", pfd)                                  // not propagated
            sendBroadcast(intent)
        }

        fun explicit3() {
            val pfd = ParcelFileDescriptor.open(
                File(context.filesDir, "secret.txt"),
                ParcelFileDescriptor.MODE_READ_ONLY)

            val intent: Intent = Intent("com.example.ACTION_UPDATE")        // implicit intent
            intent.putExtra("secret", pfd)                                  // propagated
            intent.setClass("test.package.name", "AnotherActivity")         // filtered: turn to explicit intent
            sendBroadcast(intent)
        }

        fun implicit() {
            val pfd = ParcelFileDescriptor.open(
                File(context.filesDir, "secret.txt"),
                ParcelFileDescriptor.MODE_READ_ONLY)

            val intent: Intent = Intent("com.example.ACTION_UPDATE")        // implicit intent
            intent.putExtra("secret", pfd)          // propagated
            sendBroadcast(intent)                   // @violation
        }

        fun implicit2() {
            val pfd = ParcelFileDescriptor.open(
                File(context.filesDir, "secret.txt"),
                ParcelFileDescriptor.MODE_READ_ONLY)

            val intent: Intent = Intent(Intent.ACTION_VIEW, Uri.parse("https://sparrow.im/"))   // implicit intent
            intent.putExtra("secret", pfd)          // propagated
            sendBroadcast(intent)                   // @violation
        }
    }

    class AnotherActivity: Activity {

    }
}