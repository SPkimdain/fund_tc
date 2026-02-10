package cc;

public class ForbiddenOverridingFinalize {
    public class FinalizeBad1 {
        protected void finalize() throws Throwable {    // @violation
            // ...
        }
    }
}