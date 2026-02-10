package custom;

import pobis.framework.base.FunctionUnit;

public class DoNotUseAnythingOtherThanFMRegularReturnValue {
    @BizUnit(value="샘플) 계좌이력관리FU", type="FU")
    public class FAcctHistMgr extends FunctionUnit {
        @BizMethod("존재여부 검증")
        public void validateEistYn2(IDataSet requestData, IOnlineContext onlineCtx) {           // @violation
            // ...
        }

        @BizMethod("존재여부 검증")
        public String validateEistYn1(IDataSet requestData, IOnlineContext onlineCtx) {         // @violation
            // ...
            return null;
        }

        @BizMethod("존재여부 검증")
        public IDataSet validateEistYn3(IDataSet requestData, IOnlineContext onlineCtx) {       /* SAFE */
            // ...
            return null;
        }
    }
}
