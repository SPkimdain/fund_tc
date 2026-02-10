package hanaw.AB.CDEF.GH.dao;

public class AMA1001_sp0000 {               // @violation
    // ...
}

public class AMA1001_ps0000 {               // safe
    private AA_Common aa_Common;            // @violation
    private AA_Common aa_common;            // safe

    public void run() {
        AA_Common aa_Common = null;         // @violation
        AA_Common aa_common = null;         // safe
    }
}

public class AMA1001_vi0000 {               // safe
    private OAA0000Q11_in mAA0000Q11_in;    // @violation
    private OAA0000Q11_in maa0000q11_in;    // safe

    public void run() {
        OAA0000Q11_in mAA0000Q11_in = null; // @violation
        OAA0000Q11_in maa0000q11_in = null; // safe
    }
}