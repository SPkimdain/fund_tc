SELECT
  employee_id, last_name, manager_id, 0 mgrLevel, salary, 0 cnt_employees
FROM
  employees
UNION ALL
SELECT
  e.employee_id, e.last_name, e.manager_id,  r.mgrLevel+1 mgrLevel, e.salary, 1 cnt_employees
FROM
  emp_count r, employees e