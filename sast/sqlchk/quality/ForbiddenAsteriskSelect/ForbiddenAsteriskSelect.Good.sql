SELECT
  last_name, job_id, salary, department_id
FROM
  employees
WHERE
  department_id = 30
ORDER BY
  last_name