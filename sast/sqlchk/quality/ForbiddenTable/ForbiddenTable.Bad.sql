SELECT
  d.department_id, e.last_name
FROM
  FORBIDDEN_TABLE d --@violation
