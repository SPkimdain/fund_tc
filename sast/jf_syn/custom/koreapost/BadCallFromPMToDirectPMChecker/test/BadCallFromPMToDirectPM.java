package pobis.aba.abadw.biz;

import pobis.framework.base.ProcessUnit;

@BizUnit(value="기본거래PU", type="PU")
public class PXYZAA511 extends ProcessUnit {
    @BizMethod("기본이체의뢰등록처리")
    public IDataSet pXYZAA07506(IDataSet requestData, IOnlineContext onlineCtx) {
        // ...
        return null;
    }
}

@BizUnit(value="추가거래PU", type="PU")
public class PXYZAA200 extends ProcessUnit {
    private FSalComMgr fsalComMgr;

    private PXYZAA511 pXYZAA511;

    @BizMethod("추가이체의뢰등록처리")
    public IDataSet pXYZAA08113(IDataSet requestData, IOnlineContext onlineCtx) {

        pXYZAA511.pXYZAA07506(requestData, onlineCtx); // @violation

        doSomething(); /* SAFE */

        fsalComMgr.processCvim(requestData, onlineCtx); /* SAFE */

        return requestData;
    }

    private void doSomething(IDataSet requestData, IOnlineContext onlineCtx) {
        pXYZAA511.pXYZAA07506(requestData, onlineCtx); // @violation

        fsalComMgr.processCvim(requestData, onlineCtx); /* SAFE */
    }
}

