INSERT /*+ PARALLEL(4) */ --@violation
INTO employees
VALUES
(207, 'Gregory', 'pgregory@fasoo.com', sysdate, 'PU_CLERK', 1.2E3, NULL);

SELECT /*+ PARALLEL */  --@violation
    id, name, salary
FROM employees
WHERE department = 'Sales';

SELECT  /*+ PARALLEL(DEFAULT) */    --@violation
    column_sparrow, column_sparrow1
FROM
    table_sparrow

UPDATE /*+ PARALLEL(AUTO) */    --@violation
    employees
SET salary = salary * 1.1
WHERE department = 'Sales';

DELETE /*+ PARALLEL(employees 4) */  --@violation
FROM employees
WHERE status = 'INACTIVE';