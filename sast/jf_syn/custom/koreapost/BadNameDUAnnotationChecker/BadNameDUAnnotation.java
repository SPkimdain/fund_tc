package pobis.aba.abadw.biz;

import pobis.framework.base.DataUnit;


@BizUnit(value="샘플) 급여이체부가서비스7FU", type="DU") // @violation
public class DTADBLT_SLAFSTP_1 extends DataUnit {
    @BizMethod("급여7 조회")
    public IDataSet inquirePay(IDataSet requestData, IOnlineContext onlineCtx) {

        return requestData;
    }
}
