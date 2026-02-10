package custom;

import pobis.framework.base.ProcessUnit;
import pobis.framework.base.FunctionUnit;
import pobis.framework.base.DataUnit;

public class BadCallFromDMToAll {
    @BizUnit(value = "기본거래PU", type = "PU")
    public class PXYZAA519 extends ProcessUnit {
        @BizMethod("기본이체의뢰등록처리")
        public IDataSet pXYZAA07600(IDataSet requestData, IOnlineContext onlineCtx) {
            // ...
            return null;
        }
    }

    @BizUnit(value="샘플) 계좌이력관리FU", type="FU")
    public class FAcctHistMgr4 extends FunctionUnit {
        @BizMethod("계좌2 검사")
        public IDataSet checkAccount2(IDataSet requestData, IOnlineContext onlineCtx) {
            //...
            return requestData;
        }
    }

    @BizUnit(value="샘플) 급여이체부가서비스3DU", type="DU")
    public class DTADBLT_SLAFSTP_3 extends DataUnit {
        @BizMethod("급여 조회")
        public IDataSet inquireAccount(IDataSet requestData, IOnlineContext onlineCtx) {
            PXYZAA519 obj = new PXYZAA519();
            obj.pXYZAA07600(requestData, onlineCtx); // @violation

            FAcctHistMgr4 fobj = new FAcctHistMgr4();
            fobj.checkAccount2(requestData, onlineCtx); // @violation

            deleteAccount(requestData, onlineCtx); // @violation

            return requestData;
        }

        @BizMethod("급여 삭제")
        public IDataSet deleteAccount(IDataSet requestData, IOnlineContext onlineCtx) {
            //...
            return requestData;
        }

        private void doSomething(IDataSet requestData, IOnlineContext onlineCtx) {
            deleteAccount(requestData, onlineCtx); // @violation
        }
    }
}
