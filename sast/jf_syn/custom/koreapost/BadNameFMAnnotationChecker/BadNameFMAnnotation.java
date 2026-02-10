package pobis.aba.abadw.biz;

import pobis.framework.base.FunctionUnit;

@BizUnit(value="샘플) 이력관리FU", type="FU")
public class FSalAptMgr extends FunctionUnit {
    @BizMethod("샘플 체크") // @violation
    public IDataSet checkMessage(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }
}
