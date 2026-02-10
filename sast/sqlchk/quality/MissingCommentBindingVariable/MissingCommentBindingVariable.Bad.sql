  SELECT
    column_sparrow
  FROM
    table_sparrow
  WHERE
    cond1_sparrow = :cond1_sparrow /* 주석1 */
    and cond2_sparrow = :cond2_sparrow and cond3_sparrow = cond3  --@violation
  ORDER BY
    cond1_sparrow
