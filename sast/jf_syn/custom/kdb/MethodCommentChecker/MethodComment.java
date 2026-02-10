package cc;
/**
 * COPYRIGHT ⓒ Korea Development Bank CO. LTD. All rights reserved.
 * KDB산업은행의 사전 승인 없이 본 내용의 전부 또는 일부에 대한 복사, 배포, 사용을 금합니다.
 *
 *  [프로그램 이력]
 *  2025-05-20 홍길동 최초 작성
 */

import java.math.BigDecimal;
import java.util.HashMap;
import java.util.Map;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.transaction.TransactionStatus;
import org.springframework.transaction.support.TransactionCallback;

import com.anyframe.online.runtime.ext.exception.BusinessException;
import com.anyframe.online.runtime.transaction.TransactionUtil;
import com.kdb.gsb.xi.wt.dao.dem.TGSBXIWT001CDEM;
import com.kdb.gsb.xi.wt.dao.vo.TGSBXIWT001CDVO;

/**
 * 공통유틸클래스
 * @author 김태호
 * @stereotype Generic
 * @name_ko 공통유틸클래스
 */
public class WTCoBIZUtil {


    /** //@violation
     * 부점코드로 해당 글로벌은행코드 제공
     * @author 김태호
     * @return_param java.lang.String
     * @name_ko 글로벌은행코드입수
     * @since 2025-01-21 09:27:08
     * param 값 누락 주석
     * @return 글로벌은행코드
     */
    public String getGblBnkC(String  gblBbrC) {
        WTCstInfBIZ wTCstInfBIZ = new WTCstInfBIZ();
        wTCstInfBIZ.Start();
        return BNK_C_MAP.get(gblBbrC);
    }

    public void foo(int a) { // @violation
        switch (a) {
            case 0:
            case 1: // Bad: break 없음
            case 2:
                System.out.println("Case 2 or fall-through from 0, 1");
                break;
            default:
                System.out.println("Default case");
                break;
        }
    }
    /** //@violation
     * 글로벌채번코드로 채번 정보 제공(트랜잭션분리)
     * @author KDB
     * @param gblGnoC 글로벌채번코드 글로벌채번코드
     * 리턴 param 누락 주석
     * @name_ko 채번일련번호트랜잭션분리입수
     * @since 2025-02-26 15:32:37
     * @return 채번값
     */
    public String getGnoSnoSrtTra(String  gblGnoC) {
        // FD {@name 트랜잭션 분리 호출} 트랜잭션 분리 호출 하는 것임
        String gblGnoVl = TransactionUtil.executeRequiresNew(new TransactionCallback<String>() {
            @Override
            // FD {@name 트랜잭션분리 실행} 트랜잭션분리 실행
            public String doInTransaction(TransactionStatus status) {
                logger.info("gblGnoC:" + gblGnoC );
                return actnGnoSno(gblGnoC);
            }
        });
        logger.info("gblGnoVl:" + gblGnoVl);
        return gblGnoVl;
    }

    /** //@violation
     * 글로벌채번코드로 채번 정보 제공(트랜잭션 미분리)
     * 필수주석 누락
     * @author 김태호
     * @param gblGnoC 글로벌채번코드 글로벌채번코드
     * @return_param java.lang.String
     * @name_ko 채번일련번호트랜잭션미분리입수
     * @return 채번값
     */
    public String getGnoSnoNsrtTra(String  gblGnoC) {
        // FD {@name 글로벌채번코드로 채번 정보 처리 호출} 글로벌채번코드로 채번 정보 처리 호출
        String gblGnoVl = actnGnoSno(gblGnoC);
        logger.info("gblGnoC:" + gblGnoC + ", gblGnoVl:" + gblGnoVl);
        return gblGnoVl;
    }

    /**
     * 글로벌채번코드로 채번 정보 처리
     * @author KDB
     * @param gblGnoC 글로벌채번코드 글로벌채번코드
     * @return_param java.lang.String
     * @since 2025-02-26 15:34:13
     * @name_ko 채번일련번호액션
     * @name_ko글로벌채번코드로 채번 정보 처리
     * @return 채번값
     */
    private String actnGnoSno(String  gblGnoC) {
        // FD {@name 채번정보 획득을 위한 DVO 생성} 채번정보 획득을 위한 DVO 생성
        TGSBXIWT001CDVO wt001c = new TGSBXIWT001CDVO();
        wt001c.setGblGnoC(gblGnoC);
        // FD {@name 현재채번번호 읽기 호출} 현재채번번호 읽기 호출
        BigDecimal lstGnoSno = TGSBXIWT001CDEM.getInstance().selectTgsbxiWt001c(wt001c);
        if(lstGnoSno==null){
            logger.warn("selectTgsbxiWt001c fail. wt001c:" + wt001c);
            throw new BusinessException("BEGSB00145");	//No Item has been selected.
        }
        // FD {@name 다음 채번번호 세팅} 다음 채번번호 세팅
        BigDecimal nextGnoSno = lstGnoSno.add(BigDecimal.ONE);
        wt001c.setLstGnoSno(nextGnoSno);
        // FD {@name 채번번호 업데이트 호출} 채번번호 업데이트 호출
        int ret = TGSBXIWT001CDEM.getInstance().updateTgsbxiWt001c(wt001c);
        if(ret!=1){
            logger.warn("updateTgsbxiWt001c fail. wt001c:" + wt001c);
            throw new BusinessException("BEGSB00166");	//No data has been modified.
        }
        return getGnoVl(gblGnoC, nextGnoSno);
    }

    /**
     * 글로벌채번코드별 룰처리
     * @author KDB
     * @param gblGnoC 글로벌채번코드 글로벌채번코드
     * @return_param java.lang.String
     * @name_ko 채번값입수
     * @since 2025-02-26 15:34:44
     * @param gnoIdx 채번인덱스 채번인덱스
     * @return 채번값
     */
    private String getGnoVl(String  gblGnoC, BigDecimal  gnoIdx) {
        switch (gblGnoC) {
            case "CNO":
                return String.format("C%07d", gnoIdx.intValue());
            default:
                break;
        }
        return gnoIdx.toPlainString();
    }

    /** //@violation
     * 글로벌채번코드별 룰처리
     * @author KDB
     * @param gblGnoC 글로벌채번코드 글로벌채번코드
     * @return_param java.lang.String
     * @name_ko 채번값입수
     * @since 2025-02-26 15:34:44
     * @return 채번값
     */
    public String getGnoVl2(String  gblGnoC, BigDecimal  gnoIdx) {
        switch (gblGnoC) {
            case "CNO":
                return String.format("C%07d", gnoIdx.intValue());
            default:
                break;
        }
        return gnoIdx.toPlainString();
    }

    public void test() { // @violation

    }

    public void start() { // @violation

    }
}