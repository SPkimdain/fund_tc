class DoNotChangeOfLoopControlVariable {
    public void violation1() {
        for(int idx=0; idx<10; idx++) {
            idx = 10;           // @violation
            idx++;              // @violation
            idx--;              // @violation
        }
    }

    public void violation2() {
        for(int idx1=0, idx2=0; idx1<10 && idx2<10; idx1++, idx2++) {
            idx1++;             // @violation
            idx2++;             // @violation
        }
    }

    public void good() {
        for(int idx=0; idx<10; idx++) {
            // ...              /* SAFE */
        }
    }
}