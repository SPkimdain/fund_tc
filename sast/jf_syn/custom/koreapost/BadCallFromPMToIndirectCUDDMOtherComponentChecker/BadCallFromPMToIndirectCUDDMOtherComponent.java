package pobis.ttx.procs.biz;

import pobis.framework.base.ProcessUnit;


@BizUnit(value="기본거래PU", type="PU")
public class PXYZAA888 extends ProcessUnit {
    @BizMethod("기본이체의뢰등록처리")
    public IDataSet pXYZAA07888(IDataSet requestData, IOnlineContext onlineCtx) {
        //other component
        callSharedMethodByDirect("pobis.ttx.abcaa", "DTATHAA_INTCUSM_0.update", requestData, onlineCtx); // @violation

        callSharedMethodByDirect("pobis.ttx.abcxx", "DTATHAA_INTCUSM_1.register", requestData, onlineCtx); // @violation

        callSharedMethodByDirect("pobis.axx.abctt", "DTATHAA_INTCUSM_2.deleteSomething", requestData, onlineCtx); // @violation

        //other component / read
        callSharedMethodByDirect("pobis.axx.abctt", "DTATHAA_INTCUSM_2.inquire", requestData, onlineCtx); /* SAFE */

        //other component / fm
        callSharedMethodByDirect("pobis.axx.abctt", "FAcctHistMgr.deleteAcctHist", requestData, onlineCtx); /* SAFE */

        //same component
        callSharedMethodByDirect("pobis.ttx.procs", "DTADBLT_SALFSTP_2.update", requestData, onlineCtx); /* SAFE */

        return requestData;
    }

    private void doSomething(IDataSet requestData, IOnlineContext onlineCtx) {
        callSharedMethodByDirect("pobis.ttx.abcaa", "DTATHAA_INTCUSM_0.update", requestData, onlineCtx); // @violation
    }
}
