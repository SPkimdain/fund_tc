  SELECT
    hire_date
  FROM
    employees
  WHERE
    SYSDATE - hire_date  > 365 --@violation