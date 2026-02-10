package pobis.aba.abadw.biz;

import pobis.framework.base.ProcessUnit;


@BizUnit(value="추가거래PU", type="PU")
public class PABAAA333 extends ProcessUnit {
    @BizMethod("추가이체의뢰등록처리")
    public IDataSet XYZAA08522(IDataSet requestData, IOnlineContext onlineCtx) { // @violation
        // ...
        return requestData;
    }

    private void doSomething() {
    }
}
