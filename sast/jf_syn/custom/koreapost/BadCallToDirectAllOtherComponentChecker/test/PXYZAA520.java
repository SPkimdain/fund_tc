package pobis.aba.caller.biz;

import pobis.framework.base.ProcessUnit;
import pobis.framework.base.FunctionUnit;
import pobis.framework.base.DataUnit;

import pobis.aba.abadw.biz.PXYZAA112;
import pobis.aba.abadw.biz.FSalComMgr;
import pobis.aba.abadw.biz.DTADBLT_SLAFSTP_7;


@BizUnit(value = "기본거래PU", type = "PU")
public class PXYZAA520 extends ProcessUnit {
    private PXYZAA112 pXYZAA112;
    private FSalComMgr fSalComMgr;
    private DTADBLT_SLAFSTP_7 dTADBLT_SLAFSTP_7;

    private DTADACB_HTCHPMM_0 dTADACB_HTCHPMM_0;

    private DTADACB_BKOLCHP_1 dTADACB_BKOLCHP_1;

    @BizMethod("기본이체의뢰등록처리")
    public IDataSet pXYZAA07601(IDataSet requestData, IOnlineContext onlineCtx) {
        pXYZAA112.pXYZAA08132(requestData, onlineCtx); // @violation

        fSalComMgr.checkBill(requestData, onlineCtx); // @violation

        dTADBLT_SLAFSTP_7.inquireAccount(requestData, onlineCtx); // @violation

        dTADACB_HTCHPMM_0.inquire(requestData, onlineCtx); /* SAFE */

        doSomething(); /* SAFE */

        dTADACB_BKOLCHP_1.listPblcnBrnCd(requestData, onlineCtx); /* SAFE */
        return null;
    }

    private void doSomething2(IDataSet requestData, IOnlineContext onlineCtx) {

        dTADBLT_SLAFSTP_7.inquireAccount(requestData, onlineCtx); // @violation
    }
}
