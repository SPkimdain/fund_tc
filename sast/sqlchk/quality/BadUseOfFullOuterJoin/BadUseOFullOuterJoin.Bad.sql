SELECT
  c1.field1, c2.field2
FROM
  table_a ta
FULL OUTER JOIN --@violation
  table_b tb
ON
  c1.id = c2.id