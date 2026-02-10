SELECT *     --@violation
FROM employees
WHERE ROWNUM <= 10
ORDER BY salary DESC;

SELECT *        --@violation
FROM (
         SELECT *
         FROM employees
         ORDER BY salary DESC
     )
WHERE ROWNUM <= 10;