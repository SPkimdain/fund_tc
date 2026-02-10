SELECT *
FROM employees
WHERE ROWNUM <= 10;

SELECT *
FROM employees
ORDER BY salary DESC;

/* excludeRownumOrderBySubquery == true
SELECT *
FROM (
         SELECT *
         FROM employees
         ORDER BY salary DESC
     )
WHERE ROWNUM <= 10;
*/