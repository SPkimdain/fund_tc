SELECT d.department_id, e.last_name
   FROM departments  LEFT OUTER JOIN employees --@violation 2
   ON d.department_id = e.department_id
   ORDER BY d.department_id, e.last_name