package custom;

import pobis.framework.base.DataUnit;

public class DoNotUseParametersOtherThanDMParameters {
    @BizUnit(value="샘플 - 계좌 원장_1DU", type="DU")
    public class DTB_XYZ_ACCT_M_1 extends DataUnit {
        @BizMethod("샘플 - 계좌 이력 목록조회")
        public IDataSet listPageNo(String condition) {                                      // @violation
            // ...
            return null;
        }

        @BizMethod("샘플 - 계좌 이력 목록조회")
        public IDataSet listPageNo(IDataSet requestData, IOnlineContext onlineCtx) {        /* SAFE */
            // ...
            return null;
        }

        public IDataSet listPageNNNo(String inputData) {                                    /* SAFE */
            // ...
            return null;
        }
    }
}
