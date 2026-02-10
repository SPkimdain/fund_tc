INSERT INTO employees --@violation
(employee_id, last_name, email, hire_date, job_id, salary)
VALUES
(employees_seq.nextval, 'Doe', 'john.doe@fasoo.com',
 SYSDATE, 'SH_CLERK')