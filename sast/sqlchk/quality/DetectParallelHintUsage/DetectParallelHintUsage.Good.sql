INSERT
INTO employees
VALUES
    (207, 'Gregory', 'pgregory@fasoo.com', sysdate, 'PU_CLERK', 1.2E3, NULL);

SELECT
    id, name, salary
FROM employees
WHERE department = 'Sales';

SELECT
    column_sparrow, column_sparrow1
FROM
    table_sparrow

UPDATE
    employees
SET salary = salary * 1.1
WHERE department = 'Sales';

DELETE
FROM employees
WHERE status = 'INACTIVE';