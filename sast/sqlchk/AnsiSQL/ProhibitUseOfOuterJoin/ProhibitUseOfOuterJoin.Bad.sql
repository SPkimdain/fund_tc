SELECT a.empno
     , a.ename
     , a.deptno
     , b.deptno
     , b.dname
FROM emp a
   , dept b
WHERE a.deptno(+) = b.deptno --@violation
  AND (a.job = 'MANAGER'
    OR a.job IS NULL)