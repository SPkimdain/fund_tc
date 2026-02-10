package custom;

import pobis.framework.base.ProcessUnit;
import pobis.framework.base.POBISException;

public class WrongExceptionHandlingInPM {
    @BizUnit(value = "기본거래PU", type = "PU")
    public class PXYZAA361 extends ProcessUnit {
        @BizMethod("기본이체의뢰등록처리")
        public IDataSet pXYZAA04304(IDataSet requestData, IOnlineContext onlineCtx) {
            try { // @violation
                int x = 0;
                x++;

            } catch(Exception e) {
                e.printStackTrace();
            }

            return requestData;
        }

        @BizMethod("기본이체의뢰등록처리2")
        public IDataSet pXYZAA04305(IDataSet requestData, IOnlineContext onlineCtx) {
            try { /* SAFE */
                int x = 0;
                x++;

            } catch(POBISException pe) {
                throw pe;
            } catch(Exception e) {
                throw new POBISException("BEXYZ00000", e);
            }

            return requestData;
        }

        @BizMethod("기본이체의뢰등록처리3")
        public IDataSet pXYZAA04306(IDataSet requestData, IOnlineContext onlineCtx) {
            try { /* SAFE */
                int x = 0;
                x++;

            } catch(pobis.framework.base.POBISException pe) {
                throw pe;
            } catch(Exception e) {
                throw new POBISException("BEXYZ00000", e);
            }

            return requestData;
        }

        @BizMethod("기본이체의뢰등록처리4")
        public IDataSet pXYZAA04307(IDataSet requestData, IOnlineContext onlineCtx) {
            try { // @violation
                int x = 0;
                x++;

            } catch(DataException e) {
                throw e;
            } catch(Exception e) {
                throw e;
            }

            return requestData;
        }

        @BizMethod("기본이체의뢰등록처리5")
        public IDataSet pXYZAA04308(IDataSet requestData, IOnlineContext onlineCtx) {
            try { /* SAFE */
                int x = 0;
                x++;

            } catch(DataException e) {
                throw new POBISException("BEXYZ00000", e);
            } catch(Exception e) {
                throw new POBISException("BEXYZ00000", e);
            }

            return requestData;
        }
    }
}
