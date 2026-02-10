package pobis.aba.abadw.biz;

import pobis.framework.base.DataUnit;


@BizUnit(value="샘플) 급여이체부가서비스3DU", type="DU")
public class DTADBLT_SLAESTP_3 extends DataUnit {
    @BizMethod("급여2 제거") // @violation
    public IDataSet deleteBill(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }
}
