package custom;

public class UnusedLocalVariable {
    public static void violation(String[] args) {
        int a = 1;
        int b = 2;
        int c = 3;
        int safeD = 10;             // @safe
        int d = 4;                  // @violation
        int i = TestMethod(a,b,c);  // @violation
    }

    public void good1() {
        long sleepCnt = requestData.getLong("TMPSP_NOCS", 0);

        if(sleepCnt > 0) {
            log.debug("", sleepCnt);

            for(int i=0, j=0; i<sleepCnt; i++) {
                try {
                    Threadd.sleep(1000);
                } catch (InterruptedException e) {
                    // Do Nothing
                }
            }
        }
    }

    public void good2() {
        String actno = inquireRes.getString("ACTNO");
        boolean existActnpYn = actno != null && actno.trim().length() > 0;
        responseData.put("EXIST_YN", existActnpYn ? "Y" : "N");
    }

    public void good3() {
        IRecordSet recordSet = requestData.getRecordSet("PUSH_MSG_RCPTN_TRGT_DATAGRID");
        for(IRecord record: recordSet) {
            oh.addPushRcvr(record.getString("PUSH_MSG_RCPTN_TRGT_VAL"));
        }
    }

    public void good4() {
        boolean isTimerRemoved = removeDelayAsyncService(timerTxKey, onlineCtx);

        if(isTimerRemoved) {
            log.debug("타이머거래 취소 성공. {0}", timerTxKey);
        }
    }

    public void good5() {
        IRecord record = r5.newRecord(3);

        record.set(0, "소계");
        for(int i=1; i<7; i++) {
            record.set(i, "record1.get");
        }

        IRecord SumRecord = r5.newRecord(6);
        log.debug("[PATAJD202]", SumRecord);
        SumRecord.set(0, "합계");
        for(int i=1; i<7; i++) {
            SumRecord.set(i, "record.getBigDecimal(i)");
        }
    }

    public void good6(IDataSet requestData, IOnlineContext onlineCtx) {
        CommonArea ca = getCommonArea(onlineCtx);
        IDataSet commonData = ca.getIdivJowsInfo(AtajdConst.COMM_AFFR_ELBK_CMNW);

        commonData.put("", "");
    }
}
