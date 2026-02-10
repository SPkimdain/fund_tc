package pobis.tta.abadw.biz;

import pobis.framework.base.ProcessUnit;


@BizUnit(value="추가거래DU", type="PU") // @violation
public class PTTAAA922 extends ProcessUnit {
    @BizMethod("추가이체의뢰등록처리")
    public IDataSet pTTAAA23132(IDataSet requestData, IOnlineContext onlineCtx) {
        // ...
        return requestData;
    }

    private void doSomething() {
    }
}
