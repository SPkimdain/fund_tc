package custom;

import pobis.framework.base.ProcessUnit;

public class DoNotUsePUWithoutProcessunitInheritance {
    @BizUnit(value="기본거래PU", type="PU")
    public class PXYZAA010 extends TestUnit {                           // @violation
        // ...
    }

    @BizUnit(value="기본거래PU", type="PU")
    public class PXYZAA011 extends pobis.framework.base.ProcessUnit {   /* SAFE */
        // ...
    }

    @BizUnit(value="기본거래PU", type="PU")
    public class PXYZAA012 extends ProcessUnit {                        /* SAFE */
        // ...
    }

    public class PXYZAA013 extends TestUnit {                           /* SAFE */
        // ...
    }

    @BizUnit(value="기본거래PU", type="PP")
    public class PXYZAA014 extends TestUnit {                           /* SAFE */
        // ...
    }

    @BizUnit(value="기본거래PU", type="PU")
    public class AXYZAA015 extends TestUnit {                           /* SAFE */
        // ...
    }

    @BizUnit(value="기본거래PU", type="PU")
    public class PXYZA015 extends TestUnit {                            /* SAFE */
        // ...
    }
}
