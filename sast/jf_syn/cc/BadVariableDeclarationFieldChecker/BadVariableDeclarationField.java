package cc;

import java.lang.String;

public class BadVariableDeclartionField {

    private static final int f_csp;
    private static final String f_csr;
    private final int f_cp;
    private final String f_cr;
    private static int f_sp;
    private static String f_sr;
    private int f_p;
    private String f_r;

    public class Inner1 {
        private int f_p;
        private String f_r;
        private final int f_cp; // @violation
    }

    public class Inner2 {
        private int f_p; // @violation
        private final int f_cp;
        private final String f_cr;
        private static int f_sp;
        private static String f_sr;
        private static final String f_csr; // @violation
    }

    public class Inner3 {
        private String f_r; // @violation
        private static final int f_csp;
        private static final String f_csr;
        private final int f_cp;
        private final String f_cr;
        private static int f_sp;
        private static String f_sr;
        private int f_p;
    }

    public class Inner4 {
        private static final String f_csr; // @violation
        private static final int f_csp;
        private final int f_cp;
        private final String f_cr;
    }

    public class Inner5 {
        private static final String f_csr;
        private final int f_cp;
        private static final int f_csp; // @violation
        private static int f_sp;
        private static String f_sr;
        private final String f_cr; // @violation
        private int f_p;
        private String f_r;
    }

    public class Inner6 {
        private String f_r; // @violation
        private int f_p;
    }

    public class Inner7 {
        private int f_p; // @violation
        public String f_r;
    }

    public class Inner8 {
        protected int f_p;
        private int f_p2; // @violation
        int f_p3;
    }
}
