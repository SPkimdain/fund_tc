import java.net.URLClassLoader;

public class SecurityMethodOverrideGetpermissions1 extends URLClassLoader {
    protected PermissionCollection getPermissions(CodeSource cs) {
        PermissionCollection pc = new Permissions();                    // @violation
        // allow exit from the VM anytime
        pc.add(new RuntimePermission("exitVM"));
        return pc;
    }
}

public class SecurityMethodOverrideGetpermissions2 extends URLClassLoader {
    protected PermissionCollection getPermissions(CodeSource cs) {
        PermissionCollection pc = super.getPermissions(cs);             /* Safe */
        // allow exit from the VM anytime
        pc.add(new RuntimePermission("exitVM"));
        return pc;
    }
}