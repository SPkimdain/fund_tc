package pobis.xyz.abadw.biz;

import pobis.framework.base.ProcessUnit;
import pobis.framework.base.POBISException;


@BizUnit(value="추가거래PU", type="PU")
public class PXYZAA333 extends ProcessUnit {
    @BizMethod("추가이체의뢰등록처리")
    public IDataSet pXYZAA08139(IDataSet requestData, IOnlineContext onlineCtx) {
        Exception e = new Exception();
        throw new POBISException("BEADA00000", new Object[]{}, e); // @violation

        return requestData;
    }

    private void doSomething(int flag) {
        if(flag > 10) {
            throw new POBISException("BEXYZ00000", new Object[]{}, e); /* SAFE */
        }
        else if(flag == 5) {
            throw new POBISException("BEZZZ00000", new Object[]{}, e); /* SAFE */
        } else {
            /* is it safe? */
            throw new POBISException("CNXYZ00000", new Object[]{}, e); /* SAFE */
        }
    }
}
