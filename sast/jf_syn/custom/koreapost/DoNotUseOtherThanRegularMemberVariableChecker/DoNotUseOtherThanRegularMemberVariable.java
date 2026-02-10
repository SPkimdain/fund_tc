package custom;

import pobis.framework.base.ProcessUnit;
import pobis.framework.base.BizUnit;
import pobis.framework.base.BizUnitBind;
import pobis.framework.base.FAcctMgr;
import pobis.framework.base.DTB_XYZ_ACCT_M_1;

public class DoNotUseOtherThanRegularMemberVariable {
    @BizUnit(value="기본거래PU", type="PU")
    public class PXYZAA020 extends ProcessUnit {
        //클래스 멤버변수 선언 금지
        private String str;                             // @violation
        @BizUnitBind
        private FAcctMgr fAcctMgr;                      /* SAFE */
        @BizUnitBind
        private DTB_XYZ_ACCT_M_1 dTB_XYZ_ACCT_M_1;      /* SAFE */
    }
}
