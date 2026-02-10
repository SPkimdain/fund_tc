class BadCallRuntimeProcess {
    public void violation(Runtime runtime) {
        runtime.process();                  // @violation
    }

    public void good(Runtime runtime) {
        // runtime.process();               /* SAFE */
    }
}