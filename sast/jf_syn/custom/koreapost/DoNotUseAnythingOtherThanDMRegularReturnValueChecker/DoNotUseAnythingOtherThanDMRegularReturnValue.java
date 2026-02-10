package custom;

import pobis.framework.base.DataUnit;

public class DoNotUseAnythingOtherThanDMRegularReturnValue {
    @BizUnit(value="샘플 - 계좌 원장_1DU", type="DU")
    public class DTB_XYZ_ACCT_M_1 extends DataUnit {
        @BizMethod("샘플 - 계좌 이력 목록조회")
        public void listPageNo1(IDataSet requestData, IOnlineContext onlineCtx) {            // @violation
            // ...
        }

        @BizMethod("샘플 - 계좌 이력 목록조회")
        public String listPageNo2(IDataSet requestData, IOnlineContext onlineCtx) {          // @violation
            // ...
            return null;
        }

        @BizMethod("샘플 - 계좌 이력 목록조회")
        public IDataSet listPageNo3(IDataSet requestData, IOnlineContext onlineCtx) {        /* SAFE */
            // ...
            return null;
        }
    }
}
