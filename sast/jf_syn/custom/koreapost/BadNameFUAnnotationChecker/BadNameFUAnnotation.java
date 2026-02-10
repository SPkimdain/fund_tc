package pobis.aba.abadw.biz;

import pobis.framework.base.FunctionUnit;

@BizUnit(value="샘플) 이력관리PU", type="FU") // @violation
public class FTesComMgr extends FunctionUnit {
    @BizMethod("샘플 검사")
    public IDataSet checkSomething(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }
}
