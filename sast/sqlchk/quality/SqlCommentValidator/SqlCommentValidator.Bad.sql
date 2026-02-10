/* Namespace: com.kdbc.cor.buc.cm.dat.TCMEMPINFOMHDao | ID: selectEncryptedPwd2 */
/**********************************
@업무코드 CM
@쿼리설명 현재 로그인 된 사용자 조회
@최종변경일자 2025-12-17
**********************************/
SELECT * FROM TCMEMPINFOMM WHERE USE_YN = 'Y'   --@violation
/* Namespace: com.kdbc.cor.buc.cm.dat.TCMEMPINFOMHDao | ID: selectEncryptedPwd3 */
/**********************************
@쿼리이름 TCMEMPINFOMHDao.selectEncryptedPwd3
@업무코드 CM
@쿼리설명 현재 로그인 된 사용자 조회
@최종변경일자 2025-12-17
**********************************/
SELECT * FROM TCMEMPINFOMM WHERE USE_YN = 'Y'   --@violation
/* Namespace: com.kdbc.cor.buc.cm.dat.TCMEMPINFOMHDao | ID: selectEncryptedPwd4 */
/**********************************
@업무코드 CM
@쿼리이름 com.kdbc.cor.buc.cm.dat.TCMEMPINFOMHDao.selectEncryptedPwd4
@쿼리설명 현재 로그인 된 사용자 조회
@최종변경일자 2025-12-17
**********************************/
SELECT * FROM TCMEMPINFOMM WHERE USE_YN = 'Y'   --@violation
/* Namespace: com.kdbc.cor.buc.cm.dat.TCMEMPINFOMHDao | ID: selectEncryptedPwd5 */
/**********************************
@업무코드 CMT
@쿼리이름 TCMEMPINFOMHDao.selectEncryptedPwd5
@쿼리설명 현재 로그인 된 사용자 조회
@최종변경일자 2025-12-17
**********************************/
SELECT * FROM TCMEMPINFOMM WHERE USE_YN = 'Y'   --@violation
/* Namespace: com.kdbc.cor.buc.cm.dat.TCMEMPINFOMHDao | ID: updatePassword */
/**********************************
@업무코드 CM
@쿼리이름 TCMEMPINFOMHDao.updatePassword
@쿼리설명 현재 로그인 된 사용자 조회
  테스트
@최종변경일자 2025.12.17
**********************************/
UPDATE TCMEMPINFOMM SET PWD = #{pwd} WHERE EMNO = #{emno}   --@violation