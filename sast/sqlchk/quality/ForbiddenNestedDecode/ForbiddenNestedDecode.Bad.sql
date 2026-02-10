SELECT
      t1.tx_code, t1.ap_log_process,
      t2.inst_no, /* 기관코드 */
      t1.svc_name, /* 서비스명 */
      decode(DECODE(t1.log_type, 'E', 'Error', 'All'), 'Error', 'E', 'All') log_type, --@violation
      to_char(sysdate, 'YYYYMMDD') syst_date /* 시스템일자 */
FROM  pfm_svc t1, PFM_SVC_EXT t2
WHERE t1.tx_code = t2.tx_code
AND   t1.log_type NOT IN ('EW', 'EWD')