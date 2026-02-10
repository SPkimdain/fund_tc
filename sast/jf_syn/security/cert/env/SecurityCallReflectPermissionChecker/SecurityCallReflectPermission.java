public class SecurityCallReflectPermission {
    protected PermissionCollection getPermissions(CodeSource cs) {
        PermissionCollection pc = super.getPermissions(cs);
        ReflectPermission reflect = new ReflectPermission("suppressAccessChecks");

        pc.add(new ReflectPermission("suppressAccessChecks"));              // @violation
        pc.add(reflect);                                                    // @violation

        return pc;
    }
}