package testcase.rule.security.StoreInClearTextToRegistryChecker

import com.sun.jna.platform.win32.Advapi32Util
import com.sun.jna.platform.win32.WinReg

object TestCase {
    fun violation() {
        val pwd = getUserInput()

        Advapi32Util.registryCreateKey(WinReg.HKEY_CURRENT_USER, "Software\\MyApp")
        Advapi32Util.registrySetIntValue(           // @violation
            WinReg.HKEY_CURRENT_USER,
            "Software\\MyApp",
            "password",
            pwd
        )
        println("Completed saving to registry")
    }

    fun violationHardcode() {
        Advapi32Util.registrySetStringValue(WinReg.HKEY_CURRENT_USER, "password", "admin123")                       // @violation
        Advapi32Util.registrySetIntValue(WinReg.HKEY_CURRENT_USER, "password", 1234)                                // @violation
        Advapi32Util.registrySetStringValue(WinReg.HKEY_CURRENT_USER, "Software\\MyApp", "password", "admin123")    // @violation
        Advapi32Util.registrySetIntValue(WinReg.HKEY_CURRENT_USER, "Software\\MyApp", "password", 1234)             // @violation
    }
}