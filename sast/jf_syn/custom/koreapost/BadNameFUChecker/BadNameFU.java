package pobis.aba.abadw.biz;

import pobis.framework.base.FunctionUnit;

@BizUnit(value="샘플) 이력관리FU", type="FU")
public class SalComMgr extends FunctionUnit { // @violation
    @BizMethod("샘플 검사")
    public IDataSet checkSample(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }
}
