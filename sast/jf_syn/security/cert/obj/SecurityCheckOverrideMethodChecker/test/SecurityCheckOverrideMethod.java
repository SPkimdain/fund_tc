package security;

import java.io.*;

public class SecurityCheckOverrideMethod extends SecurityCheckOverrideMethodParent { // @violation
    // Subclass handles authentication
    // NOTE: unchanged from previous version
    // NOTE: lacks override of overdraft method
}