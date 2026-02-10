INSERT /*+ append */ INTO --@violation
    employees
VALUES
    (207, 'Gregory', 'pgregory@fasoo.com', sysdate, 'PU_CLERK', 1.2E3, NULL);