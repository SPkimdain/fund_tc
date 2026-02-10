package pobis.aba.abadw.biz;

import pobis.framework.base.FunctionUnit;

@BizUnit(value="샘플) 이력관리FU", type="FU")
public class FSalAppMgr extends FunctionUnit {
    @BizMethod("샘플 검사")
    public IDataSet validatMessage(IDataSet requestData, IOnlineContext onlineCtx) { // @violation
        //...
        return requestData;
    }

    @BizMethod("샘플 적용")
    public IDataSet wrongVerbSample(IDataSet requestData, IOnlineContext onlineCtx) { // @violation
        //...
        return requestData;
    }

    @BizMethod("테스트감시")
    public IDataSet monitorTest(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }

    @BizMethod("테스트반려검사")
    public IDataSet checkTestMng(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }

    @BizMethod("테스트반려Lock조회")
    public IDataSet inquireForLockMng(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }

    @BizMethod("테스트확인업로드")
    public IDataSet uploadCheck(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }
}
