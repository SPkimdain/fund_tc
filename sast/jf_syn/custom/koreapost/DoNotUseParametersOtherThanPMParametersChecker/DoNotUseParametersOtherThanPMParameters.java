package custom;

import pobis.framework.base.ProcessUnit;

public class DoNotUseParametersOtherThanPMParameters {
    @BizUnit(value="기본거래PU", type="PU")
    public class PXYZAA010 extends ProcessUnit {
        @BizMethod("대량이체의뢰등록처리")
        public IDataSet pXYZAA07003(String inputData) {                                     // @violation
            // ...
            return null;
        }

        @BizMethod("대량이체의뢰등록처리")
        public IDataSet pXYZAA07004(IDataSet requestData, IOnlineContext onlineCtx) {       /* SAFE */
            // ...
            return null;
        }

        public IDataSet pXYZAA07005(String inputData) {                                     /* SAFE */
            // ...
            return null;
        }
    }
}
