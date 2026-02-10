/* QRY_001
   test
   */
SELECT * --@violation
FROM employees
WHERE department = 'Sales';

-- Sales 부서에서 급여가 50000 이상인 직원 조회
INSERT INTO --@violation
    employees
VALUES
    (207, 'Gregory', 'pgregory@fasoo.com', sysdate, 'PU_CLERK', 1.2E3, NULL);

-- 부서별 평균 급여 조회
UPDATE employees --@violation
SET salary = salary * 1.1
WHERE department = 'Sales' AND salary >= 50000;

DELETE FROM employees --@violation
WHERE department = 'Sales' AND salary <= 30000;

SELECT COUNT(*)   AS TOT_CNT  --@violation        /* 전체건수 */
FROM GSBOWN.TGSBXL_LN010M A  /* 여신계약기본 */
   , (SELECT GBL_BNK_C
           , GBL_LN_MCTC_NO
           , MIN(DECODE(GBL_LD_BD_OPT_CLSF_TC, '20', OPX_DT )) AS PTO_EXCS_DT  /* 풋옵션행사일자 */
           , MIN(DECODE(GBL_LD_BD_OPT_CLSF_TC, '10', OPX_DT )) AS CLO_EXCS_DT  /* 콜옵션행사일자 */
      FROM GSBOWN.TGSBXL_LN013D   /* 여신계약옵션상세 */
      WHERE GBL_BNK_C     = #{gblBnkC}
		            AND GBL_LDG_STS_C = '50'
		            AND OPX_DT     >=
		    		     #{bseDt}        /* Asis경우 현재기준일(Business Date) */
      GROUP BY GBL_BNK_C
              , GBL_LN_MCTC_NO) B
   , GSBOWN.TGSBXC_CI100M C  /* 고객기본 */
WHERE A.GBL_BNK_C        = B.GBL_BNK_C(+)
  AND A.GBL_BNK_C        = C.GBL_BNK_C
  AND A.GBL_LN_MCTC_NO   = B.GBL_LN_MCTC_NO(+)
  AND A.CNO              = C.CNO
  AND A.GBL_LDG_STS_C    = '50'       /* 상태코드는 '50'(Normal)로 고정 */
  AND A.SYND_TBN_PTP_TC  = 'Y'
  AND A.GBL_LN_PRD_KD_TC = '10'
  AND A.GBL_BNK_C        = #{gblBnkC}

		    AND A.GBL_PRD_C        = #{gblPrdC}

		    		    AND EXISTS (SELECT 1
		                        FROM GSBOWN.TGSBXL_LN020M    /* 여신계좌기본 */
		                       WHERE GBL_BNK_C      = A.GBL_BNK_C
		         				   AND GBL_LN_MCTC_NO = A.GBL_LN_MCTC_NO
		         				   AND GBL_LDG_STS_C  = '50');

SELECT GBL_BNK_C --@violation
     , CNO
     , GBL_BBR_C
     , SNO
FROM GSBOWN.TGSBXC_CI170P
WHERE #{inqTgtDttS1} = '1'
		   AND GBL_BNK_C     = #{gblBnkC}
		   AND CNO           = #{cno}
		   AND GBL_BBR_C     = #{gblBbrC}
		   AND GBL_LDG_STS_C = #{gblLdgStsC}
UNION ALL
SELECT GBL_BNK_C
     , CNO
     , GBL_BBR_C
     , SNO
FROM GSBOWN.TGSBXC_CI190P
WHERE #{inqTgtDttS1} = '2'
		   AND GBL_BNK_C = #{gblBnkC}
		   AND CNO       = #{cno}
		   AND GBL_BBR_C = #{gblBbrC}
		   AND GBL_LDG_STS_C = #{gblLdgStsC};