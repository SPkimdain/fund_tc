SELECT
    column_sparrow, column_sparrow1 --@violation
  FROM
    table_sparrow
  WHERE
    cond1_sparrow = :cond1_sparrow
