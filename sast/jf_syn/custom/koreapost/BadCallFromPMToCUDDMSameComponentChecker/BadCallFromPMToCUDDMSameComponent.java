package pobis.mhb.mhbbi.biz;

import pobis.framework.base.ProcessUnit;
import pobis.framework.base.FunctionUnit;
import pobis.framework.base.DataUnit;

@BizUnit(value="샘플) 급여이체부가서비스5DU", type="DU")
public class DTADBLT_SLAFSTP_5 extends DataUnit {
    @BizMethod("급여5 조회")
    public IDataSet inquireAccount(IDataSet requestData, IOnlineContext onlineCtx) {

        return requestData;
    }

    @BizMethod("급여5 등록")
    public IDataSet registerAccount(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }

    @BizMethod("급여5 조회")
    public IDataSet updateAccount(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }

    @BizMethod("급여5 삭제")
    public IDataSet deleteAccount(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }

}

@BizUnit(value="샘플) 이력관리FU", type="FU")
public class FCprtBzmnSlctnEvlPfmcMng extends FunctionUnit {

    @BizMethod("샘플 처리")
    public IDataSet registerCprtBzmnSlctnEvlPfmc(IDataSet requestData, IOnlineContext onlineCtx) {
        //...
        return requestData;
    }
}

@BizUnit(value = "기본거래PU", type = "PU")
public class PXYZAA539 extends ProcessUnit {
    private DTADBLT_SLAFSTP_5 dTADBLT_SLAFSTP_5;
    private FCprtBzmnSlctnEvlPfmcMng fCprtBzmnSlctnEvlPfmcMng;
    @BizMethod("기본이체의뢰등록처리")
    public IDataSet pXYZAA07630(IDataSet requestData, IOnlineContext onlineCtx) {
        dTADBLT_SLAFSTP_5.registerAccount(requestData, onlineCtx); // @violation

        dTADBLT_SLAFSTP_5.updateAccount(requestData, onlineCtx); // @violation

        dTADBLT_SLAFSTP_5.deleteAccount(requestData, onlineCtx); // @violation

        dTADBLT_SLAFSTP_5.inquireAccount(requestData, onlineCtx); /* SAFE */

        fCprtBzmnSlctnEvlPfmcMng.registerCprtBzmnSlctnEvlPfmc(requestData, onlineCtx); /* SAFE */

        dTADBLT_SLAFSTP_5.register(requestData, onlineCtx); // @violation

        return requestData;
    }

    private void doSomething(IDataSet requestData, IOnlineContext onlineCtx) {
        dTADBLT_SLAFSTP_5.registerAccount(requestData, onlineCtx); // @violation

        dTADBLT_SLAFSTP_5.updateAccount(requestData, onlineCtx); // @violation

        dTADBLT_SLAFSTP_5.deleteAccount(requestData, onlineCtx); // @violation

        dTADBLT_SLAFSTP_5.inquireAccount(requestData, onlineCtx); /* SAFE */

        fCprtBzmnSlctnEvlPfmcMng.registerCprtBzmnSlctnEvlPfmc(requestData, onlineCtx); /* SAFE */
    }
}
