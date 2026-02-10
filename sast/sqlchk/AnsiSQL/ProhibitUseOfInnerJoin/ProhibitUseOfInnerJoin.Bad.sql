SELECT A.col1, A.col2, B,col3 --@violation
FROM TB_DUMMY A, TB_JOINNER B
WHERE A.col1 = B.col1