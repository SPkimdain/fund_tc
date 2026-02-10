package custom;

import pobis.framework.base.ProcessUnit;

public class DoNotUseAnythingOtherThanPMRegularReturnValue {
    @BizUnit(value="기본거래PU", type="PU")
    public class PXYZAA010 extends ProcessUnit {
        @BizMethod("대량이체의뢰등록처리")
        public void pXYZAA07004(IDataSet requestData, IOnlineContext onlineCtx) {       // @violation
            // ...
        }

        @BizMethod("대량이체의뢰등록처리")
        public String pXYZAA07005(IDataSet requestData, IOnlineContext onlineCtx) {     // @violation
            // ...
            return null;
        }

        @BizMethod("대량이체의뢰등록처리")
        public IDataSet pXYZAA07006(IDataSet requestData, IOnlineContext onlineCtx) {   /* SAFE */
            // ...
            return null;
        }
    }
}
