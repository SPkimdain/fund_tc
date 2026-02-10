class BadCallRuntimeGC {
    public void violation() {
        Runtime runtime = Runtime.getRuntime();

        runtime.gc();                       // @violation
    }

    public void good() {
        Runtime runtime = Runtime.getRuntime();

        // runtime.gc();                    /* SAFE */
    }
}