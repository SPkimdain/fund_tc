REPORT ZX_DD.

" non-compliant codes
SELECT COUNT(*) FROM emp
  WHERE empno NOT IN ( SELECT mgr FROM emp ). "@violation

" compliant codes
SELECT COUNT(*) FROM emp T1
   WHERE NOT EXISTS ( SELECT NULL FROM emp T2 WHERE t2.mgr = t1.empno )