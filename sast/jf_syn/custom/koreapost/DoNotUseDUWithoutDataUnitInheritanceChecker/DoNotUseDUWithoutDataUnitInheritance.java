package custom;

import pobis.framework.base.DataUnit;

public class DoNotUseDUWithoutDataUnitInheritance {
    @BizUnit(value="샘플 - 계좌 원장_1DU", type="DU")
    public class DTB_XYZ_ACCT_M_1 extends TestUnit {                            // @violation
        // ...
    }

    @BizUnit(value="샘플 - 계좌 원장_1DU", type="DU")
    public class DTB_XYZ_ACCT_M_2 extends pobis.framework.base.DataUnit {       /* SAFE */
        // ...
    }

    @BizUnit(value="샘플 - 계좌 원장_1DU", type="DU")
    public class DTB_XYZ_ACCT_M_3 extends DataUnit {                            /* SAFE */
        // ...
    }

    public class DTB_XYZ_ACCT_M_4 extends TestUnit {                            /* SAFE */
        // ...
    }

    @BizUnit(value="샘플 - 계좌 원장_1DU", type="DD")
    public class DTB_XYZ_ACCT_M_5 extends TestUnit {                            /* SAFE */
        // ...
    }

    @BizUnit(value="샘플 - 계좌 원장_1DU", type="DU")
    public class ATB_XYZ_ACCT_M_6 extends TestUnit {                            /* SAFE */
        // ...
    }
}
