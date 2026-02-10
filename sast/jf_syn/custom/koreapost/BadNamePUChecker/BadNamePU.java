package pobis.aba.abadw.biz;

import pobis.framework.base.ProcessUnit;


@BizUnit(value="추가거래PU", type="PU")
public class WrongNamePU extends ProcessUnit { // @violation
    @BizMethod("추가이체의뢰등록처리")
    public IDataSet pXYZAA08133(IDataSet requestData, IOnlineContext onlineCtx) {
        // ...
        return requestData;
    }

    private void doSomething() {
    }
}
