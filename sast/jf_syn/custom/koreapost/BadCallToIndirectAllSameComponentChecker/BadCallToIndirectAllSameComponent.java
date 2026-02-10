package pobis.aba.abadx.biz;

import pobis.framework.base.FunctionUnit;

@BizUnit(value="샘플) 이력관리FU", type="FU")
public class FTestComMgr extends FunctionUnit {
    @BizMethod("샘플 검사")
    public IDataSet checkTest(IDataSet requestData, IOnlineContext onlineCtx) {
        callSharedMethodByDirect("pobis.aba.abadx", "FTestcomMgr.insertAcctHist", requestData, onlineCtx); // @violation

        callSharedMethodByDirect("pobis.ttt.testx", "DTATHAA_INTCUSM_0.insert", requestData, onlineCtx); /* SAFE */

        return requestData;
    }

    @BizMethod("샘플 검사")
    public IDataSet insertAcctHist(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }

    private void doSomething(IDataSet requestData, IOnlineContext onlineCtx) {
        callSharedMethodByDirect("pobis.aba.abadx", "FTestcomMgr.insertAcctHist", requestData, onlineCtx); // @violation
    }
}
