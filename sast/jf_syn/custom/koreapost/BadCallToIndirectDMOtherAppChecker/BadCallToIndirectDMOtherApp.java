package pobis.ttx.proct.biz;

import pobis.framework.base.ProcessUnit;

@BizUnit(value = "예금계좌거래내역조회PU", type = "PU")
public class PXYZAA818 extends ProcessUnit {
    @BizMethod("기본이체의뢰등록처리")
    public IDataSet pXYZAA07818(IDataSet requestData, IOnlineContext onlineCtx) {
        //other app
        callSharedMethodByDirect("pobis.ott.qqqaa", "DTATHAA_INTCUSM_0.inquireAccount", requestData, onlineCtx); // @violation

        callSharedMethodByDirect("pobis.ott.qqqaa", "FAcctHistMgr.inquireAcctHist", requestData, onlineCtx); /* SAFE */
    }

    private void doSomething(IDataSet requestData, IOnlineContext onlineCtx) {
        callSharedMethodByDirect("pobis.ott.qqqaa", "DTATHAA_INTCUSM_0.inquireAccount", requestData, onlineCtx); // @violation
    }

    private void process42101Ldgr(IDataSet requestData, IOnlineContext onlineCtx) {
        callSharedMethodByDirect("pobis.ath.athca", "DTATHCA_ACCTAAM_1.inquireBycstIntgHoldAcct", requestData, onlineCtx); // @violation
    }
}
