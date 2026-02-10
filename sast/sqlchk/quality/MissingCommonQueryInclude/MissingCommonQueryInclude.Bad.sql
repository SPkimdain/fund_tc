INSERT INTO TALRCAGDEMTL
       (
         FEE_MODL_CD
       , TRGT_RCAG_CNT
       , SYS_REG_DTTM   --@violation
       , SYS_CHG_DTTM   --@violation
       , SYS_EDIR_EMNO  --@violation
       , SYS_RGSR_EMNO  --@violation
       , SYS_REG_PGM_ID --@violation
       , SYS_CHG_PGM_ID  )  --@violation
VALUES
       (
         #{FEE_MODL_CD}
       , #{TRGT_RCAG_CNT}
       , SYSDATE
       , SYSDATE
       , #{SYS_EDIR_EMNO}   --@violation
       , #{SYS_RGSR_EMNO}   --@violation
       , #{SYS_REG_PGM_ID}  --@violation
       , #{SYS_CHG_PGM_ID}  --@violation
       );

UPDATE TALRCAGDEMTL
SET FEE_MODL_CD    = #{FEE_MODL_CD}
    , TRGT_RCAG_CNT  = #{TRGT_RCAG_CNT}
    , SYS_CHG_DTTM   = SYSDATE  --@violation
    , TEST1  = #{SYS_EDIR_EMNO} --@violation
    , SYS_CHG_PGM_ID = #{TEST2}    --@violation
WHERE FEE_MODL_CD    = #{FEE_MODL_CD};