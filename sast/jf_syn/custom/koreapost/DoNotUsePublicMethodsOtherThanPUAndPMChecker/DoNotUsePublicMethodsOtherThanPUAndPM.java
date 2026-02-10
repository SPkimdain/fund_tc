package custom;

import pobis.framework.base.ProcessUnit;
import pobis.framework.base.IDataSet;
import pobis.framework.base.IOnlineContext;

public class DoNotUsePublicMethodsOtherThanPUAndPM {
    @BizUnit(value="기본거래PU", type="PU")
    public class PXYZAA010 extends ProcessUnit {
        public IDataSet getDataSet(IDataSet requestData, IOnlineContext onlineCtx) {        // @violation
            // ...
            return null;
        }

        public void print() {                                                               // @violation
            // ...
        }

        @BizMethod("대량이체의뢰등록처리")
        public IDataSet pXYZAA07004(IDataSet requestData, IOnlineContext onlineCtx) {       /* SAFE */
            // ...
            return null;
        }

        private IDataSet getData(IDataSet requestData, IOnlineContext onlineCtx) {          /* SAFE */
            // ...
            return null;
        }

        private void println() {                                                            /* SAFE */
            // ...
        }

        @BizMethod("제휴서비스요약목록조회")
        public IDataSet pMHBSI30201(IDataSet requestData, IOnlineContext onlineCtx) {       /* SAFE */
            // ...
            return null;
        }
    }
}
