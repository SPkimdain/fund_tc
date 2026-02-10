package basic;

import java.lang.Exception;

public class DoNotUseNestedTry {

    public void badFunc() {
        try {
            try { // @violation
                // Do something ...
            } catch(Exception e) {
            } finally {
            }
            // Do something ...
            {
                try { // @violation
                    // Do something ...
                } catch(Exception e) {
                }
            }
        } catch (Exception e) {
            try { /* SAFE */
                // Do something ...
            } catch(Exception e) {
                try { /* SAFE */
                    // Do something ...
                } catch(Exception e) {
                    try { /* SAFE */
                        // Do something ...
                    } catch(Exception e) {
                        try { /* SAFE */
                            // Do something ...
                        } catch(Exception e) {
                        } finally {
                            try { /* SAFE */
                                // Do something ...
                            } catch(Exception e) {
                            }
                        }
                    }
                }
            }
        }
    }

    public void goodFunc() {
        try {
            // Do something ...
        } catch (Exception e) {
        } finally {
        }
        try {
            // Do something ...
        } catch (Exception e) {
        } finally {
        }
    }

    public void badFunc1() {
        try (File file1 = new File()) {
            try (File file2 = new File()) { // @violation
                // Do something ...
            } catch(Exception e) {
            } finally {
            }
            // Do something ...
            {
                try (File file3 = new File()) { // @violation
                    // Do something ...
                } catch(Exception e) {
                }
            }
        } catch (Exception e) {
            try (File file5 = new File()) { /* SAFE */
                // Do something ...
            } catch(Exception e) {
                try (File file6 = new File()) { /* SAFE */
                    // Do something ...
                } catch(Exception e) {
                    try (File file7 = new File()) { /* SAFE */
                        // Do something ...
                    } catch(Exception e) {
                        try (File file8 = new File()) { /* SAFE */
                            // Do something ...
                        } catch(Exception e) {
                        } finally {
                            try (File file9 = new File()) { /* SAFE */
                                // Do something ...
                            } catch(Exception e) {
                            }
                        }
                    }
                }
            }
        }
    }
}