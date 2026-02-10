SELECT
 /*+ index(customer (FORBIDDEN_TABLE.FORBIDDEN_COLUMN))*/ --@violation
 employee_id, last_name, manager_id, 0 reportLevel
 FROM employees
 WHERE employee_id = 101