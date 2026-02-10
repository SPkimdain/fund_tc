package pobis.aba.caller.biz;

import pobis.framework.base.DataUnit;

@BizUnit(value="샘플) 급여이체부가서비스7DU", type="DU")
public class DTADACB_HTCHPMM_0 extends DataUnit {
    @BizMethod("급여33 조회")
    public IDataSet inquireAccount(IDataSet requestData, IOnlineContext onlineCtx) {

        return requestData;
    }
}
