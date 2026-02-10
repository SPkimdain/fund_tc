package pobis.aba.abadw.biz;

import pobis.framework.base.ProcessUnit;
import pobis.framework.base.FunctionUnit;

@BizUnit(value="기본거래PU", type="PU")
public class PXYZAA513 extends ProcessUnit {
    @BizMethod("기본이체의뢰등록처리")
    public IDataSet pXYZAA07505(IDataSet requestData, IOnlineContext onlineCtx) {
        // ...
        return null;
    }
}

@BizUnit(value="샘플) 계좌이력관리FU", type="FU")
public class FAcctHistMgr3 extends FunctionUnit {
    private FSalComMgr fSalComMgr;

    private FOtbcCvim fOtbcCvim;

    private PXYZAA513 pXYZAA513;

    @BizMethod("계좌 검사")
    public IDataSet checkAccount(IDataSet requestData, IOnlineContext onlineCtx) {
        pXYZAA513.pXYZAA07505(requestData, onlineCtx); // @violation

        fSalComMgr.processCvim(requestData, onlineCtx); /* SAFE */

        fSalComMgr.processCvim(requestData, onlineCtx); /* SAFE */

        fOtbcCvim.processCvim(requestData, onlineCtx); /* SAFE */

        return requestData;
    }

    private void doSomething(IDataSet requestData, IOnlineContext onlineCtx) {
        pXYZAA513.pXYZAA07505(requestData, onlineCtx); // @violation

        fSalComMgr.processCvim(requestData, onlineCtx); /* SAFE */

        fSalComMgr.processCvim(requestData, onlineCtx); /* SAFE */

        fOtbcCvim.processCvim(requestData, onlineCtx); /* SAFE */

        callService("ADGCC11911", requestData, onlineCtx); // @violation

        callServiceByRequiresNew("ADGCC11911", requestData, onlineCtx); // @violation

        callAsyncServiceAfterCommit("ADGCC11911", requestData, onlineCtx); // @violation

        callAsyncServiceNow("ADGCC11911", requestData, onlineCtx); // @violation
    }
}
