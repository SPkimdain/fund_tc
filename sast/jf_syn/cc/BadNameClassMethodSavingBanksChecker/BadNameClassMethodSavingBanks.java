package fsb.test;

import fsb.base.ProcessUnit;

public class PD9M010x extends ProcessUnit { // invalid class name for PU // @violation
    public void pDPM01a01XI() { // invalid method name for PM // @violation
    }
    private void fail() { // invalid private method name in Unit // @violation
    }
}

public class PDPM0100 extends ProcessUnit { // valid class name for PU
    public void pDPM01001RI() { // valid method name for PM
    }
    private void _fail() { // valid private method name in Unit
    }
}