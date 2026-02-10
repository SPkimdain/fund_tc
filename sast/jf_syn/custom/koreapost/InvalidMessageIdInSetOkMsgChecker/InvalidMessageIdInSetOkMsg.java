package pobis.xyz.abadw.biz;

import pobis.framework.base.ProcessUnit;


@BizUnit(value="추가거래PU", type="PU")
public class PXYZAA334 extends ProcessUnit {
    @BizMethod("추가이체의뢰등록처리")
    public IDataSet pXYZAA08141(IDataSet requestData, IOnlineContext onlineCtx) {
        setOkMsg("BNADA00000", onlineCtx); // @violation

        return requestData;
    }

    private void doSomething(int flag) {
        if(flag > 10) {
            setOkMsg("BNXYZ00000", onlineCtx);  /* SAFE */
        }
        else if(flag == 5) {
            setOkMsg("BNZZZ00000", onlineCtx);  /* SAFE */
        } else {
            /* is it safe? */
            setOkMsg("CIXYZ00000", onlineCtx);  /* SAFE */
        }
    }
}
