package pobis.aba.abadw.biz;

import pobis.framework.base.FunctionUnit;

@BizUnit(value="샘플) 이력관리FU", type="FU")
public class FSalComMgr extends FunctionUnit {
    @BizMethod("샘플 검사")
    public IDataSet checkBill(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }

    @BizMethod("샘플 처리")
    public IDataSet processCvim(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }
}
