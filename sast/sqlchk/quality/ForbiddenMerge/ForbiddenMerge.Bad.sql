MERGE INTO employeese --@violation
    USING hr_records
    ON (id = emp_id)
  WHEN MATCHED THEN
    UPDATE SET eaddress = address
  WHEN NOT MATCHED THEN
    INSERT (id, address)
    VALUES (DEFAULT)