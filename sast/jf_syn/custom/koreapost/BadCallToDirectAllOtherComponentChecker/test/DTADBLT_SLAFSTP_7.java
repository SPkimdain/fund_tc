package pobis.aba.abadw.biz;

import pobis.framework.base.DataUnit;


@BizUnit(value="샘플) 급여이체부가서비스7DU", type="DU")
public class DTADBLT_SLAFSTP_7 extends DataUnit {
    @BizMethod("급여7 조회")
    public IDataSet inquireAccount(IDataSet requestData, IOnlineContext onlineCtx) {

        return requestData;
    }

    @BizMethod("급여7 등록")
    public IDataSet registerAccount(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }

    @BizMethod("급여7 조회")
    public IDataSet updateAccount(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }

    @BizMethod("급여7 삭제")
    public IDataSet deleteAccount(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }

}
