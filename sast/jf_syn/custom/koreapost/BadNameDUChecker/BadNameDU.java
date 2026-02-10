package pobis.aba.abadw.biz;

import pobis.framework.base.DataUnit;


@BizUnit(value="샘플) 급여이체부가서비스7DU", type="DU")
public class TADBLT_SLAFSTP_1 extends DataUnit { // @violation
    @BizMethod("급여7 조회")
    public IDataSet inquireAccount4(IDataSet requestData, IOnlineContext onlineCtx) {

        return requestData;
    }
}
