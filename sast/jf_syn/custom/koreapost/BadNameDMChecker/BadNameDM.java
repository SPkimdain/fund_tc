package pobis.aba.abadw.biz;

import pobis.framework.base.DataUnit;

@BizUnit(value="샘플) 급여이체부가서비스2DU", type="DU")
public class DTADBLT_SLAESTP_2 extends DataUnit {
    @BizMethod("급여2 삭제")
    public IDataSet delPay(IDataSet requestData, IOnlineContext onlineCtx) { // @violation
        //...
        return requestData;
    }

    @BizMethod("급여2 삭제")
    public IDataSet wrongVerbPay(IDataSet requestData, IOnlineContext onlineCtx) { // @violation
        //...
        return requestData;
    }

    @BizMethod("공동인증서최대등록건수조회")
    public IDataSet inquireCllbAcertGrstRegNocs(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }

    @BizMethod("요구불예금 해당 일자 최종 거래 번호 조회")
    public IDataSet inquireDmdRlvtYmdLastDlngNo(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }

    @BizMethod("요구불예금 거래 상태 수정")
    public IDataSet updateDmdpDlngStat(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }

    @BizMethod("마감예외정보목록조회")
    public IDataSet listDbInExctInfo(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }

    @BizMethod("테스트Lock조회")
    public IDataSet inquireforlockExctInfo(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }

    @BizMethod("테스트2lock조회")
    public IDataSet inquireForLockExctInfo(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }

    @BizMethod("테스트삭제")
    public IDataSet deleteExctInfoMng(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }

    @BizMethod("테스트등록")
    public IDataSet register(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
        //...
        return requestData;
    }

    @BizMethod("고객상품수익성목록조회")
    public IDataSet listCustGdsPrfbl(IDataSet requestData, IOnlineContext onlineCtx) { /* SAFE */
    }
}
