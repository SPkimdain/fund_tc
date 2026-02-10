package custom;

import pobis.framework.base.FunctionUnit;

public class DoNotUseFUWithoutFunctionUnitInheritance {
    @BizUnit(value="샘플) 계좌이력관리FU", type="FU")
    public class FAcctHistMgr1 extends TestUnit {                           // @violation
        // ...
    }

    @BizUnit(value="샘플) 계좌이력관리FU", type="FU")
    public class FAcctHistMgr2 extends pobis.framework.base.FunctionUnit {  /* SAFE */
        // ...
    }

    @BizUnit(value="샘플) 계좌이력관리FU", type="FU")
    public class FAcctHistMgr3 extends FunctionUnit {                       /* SAFE */
        // ...
    }

    public class FAcctHistMgr4 extends TestUnit {                           /* SAFE */
        // ...
    }

    @BizUnit(value="샘플) 계좌이력관리FU", type="FF")
    public class FAcctHistMgr5 extends TestUnit {                           /* SAFE */
        // ...
    }

    @BizUnit(value="샘플) 계좌이력관리FU", type="FU")
    public class AAcctHistMgr6 extends TestUnit {                           /* SAFE */
        // ...
    }
}
