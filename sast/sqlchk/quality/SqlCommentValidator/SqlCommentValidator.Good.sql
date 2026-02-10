/* Namespace: com.kdbc.cor.buc.cm.dat.CustomerDao | ID: selectCustomerList */
/*******************************************************
     @업무코드     : CM
     @쿼리이름     : CustomerDao.selectCustomerList
     @쿼리설명     : 기간별 가입 고객 목록 조회
     @최종변경일자 : 2026-01-02
*******************************************************/
SELECT CUST_NO                      AS CUST_NO       /* 고객번호 */
     , CUST_NM                      AS CUST_NM       /* 고객명 */
     , BIRTH_DT                     AS BIRTH_DT      /* 생년월일 */
     , PHONE_NO                     AS PHONE_NO      /* 전화번호 */
FROM TCMCUSTBAS
WHERE USE_YN = 'Y'                                  /* 사용여부 */
  AND REG_DT >= #{startDate}                        /* 가입일자 시작일 */