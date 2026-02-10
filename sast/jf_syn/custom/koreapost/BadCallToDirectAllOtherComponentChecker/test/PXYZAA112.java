package pobis.aba.abadw.biz;

import pobis.framework.base.ProcessUnit;


@BizUnit(value="추가거래PU", type="PU")
public class PXYZAA112 extends ProcessUnit {
    @BizMethod("추가이체의뢰등록처리")
    public IDataSet pXYZAA08132(IDataSet requestData, IOnlineContext onlineCtx) {
        // ...
        return requestData;
    }

    private void doSomething() {
    }
}
