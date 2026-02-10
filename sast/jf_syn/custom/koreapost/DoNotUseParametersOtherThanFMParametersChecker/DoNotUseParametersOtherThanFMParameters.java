package custom;

import pobis.framework.base.FunctionUnit;

public class DoNotUseParametersOtherThanFMParameters {
    @BizUnit(value="샘플) 계좌이력관리FU", type="FU")
    public class FAcctHistMgr extends FunctionUnit {
        @BizMethod("존재여부 검증")
        public IDataSet validateEistYn(String inputData) {                                  // @violation
            // ...
            return null;
        }

        @BizMethod("존재여부 검증")
        public IDataSet validateEistYn(IDataSet requestData, IOnlineContext onlineCtx) {    /* SAFE */
            // ...
            return null;
        }

        public IDataSet validateEistNn(String inputData) {                                  /* SAFE */
            // ...
            return null;
        }
    }
}
