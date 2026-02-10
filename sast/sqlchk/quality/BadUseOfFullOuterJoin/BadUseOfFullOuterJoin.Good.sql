SELECT
  a.field1, b.field2
FROM
  table_a a, table_b b
WHERE
  a.id = b.id(+)
UNION ALL
SELECT
  a.field1, b.field2
FROM
  table_a a, table b b
WHERE
  a.id(+) = b.id