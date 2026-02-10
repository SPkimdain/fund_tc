SELECT id, name, old
FROM source_table --@violation

SELECT s.id, s.name, s.old
FROM source_table s, another_table a    --@violation

SELECT A.ID, A.NAME, ORDERS.ORDER_DATE
FROM USERS A
         JOIN ORDERS ON A.ID = ORDERS.USER_ID    --@violation
WHERE A.STATUS = 'ACTIVE';

SELECT USERS.ID, USERS.NAME, o.ORDER_DATE
FROM USERS, ORDERS o   --@violation
WHERE USERS.ID = o.USER_ID;

SELECT ID, NAME, EMAIL
FROM USERS   --@violation
WHERE STATUS = 'ACTIVE';

SELECT ID, NAME
FROM USERS  --@violation
WHERE EXISTS (
              SELECT B.USER_ID
              FROM ORDERS B
              WHERE B.USER_ID = ID
          );

SELECT A.ID, A.NAME
FROM USERS A
WHERE EXISTS (
              SELECT USER_ID
              FROM ORDERS    --@violation
              WHERE USER_ID = A.ID
          );

INSERT INTO target_table (id, name, old)
SELECT id, name, old
FROM source_table    --@violation
         JOIN another_table a ON id = a.source_id
WHERE a.status = 'ACTIVE';

INSERT INTO target_table (id, name, old)
SELECT s.id, s.name, s.old
FROM source_table s, another_table   --@violation
WHERE s.id = another_table.source_id
  AND another_table.status = 'ACTIVE';

-- update 암시적 join
UPDATE target_table t
SET t.old = (SELECT old
             FROM source_table, another_table a --@violation
             WHERE id = a.source_id
               AND a.status = 'ACTIVE'
               AND t.id = id)
WHERE EXISTS (
              SELECT 1 FROM coffee c, another_table   --@violation
              WHERE c.id = source_id
                AND status = 'ACTIVE'
                AND t.id = c.id
          );

-- delete 암시적 join
DELETE FROM target_table    --@violation
WHERE id IN (
    SELECT s.id
    FROM source_table s, another_table a
    WHERE s.id = a.source_id
      AND a.status = 'INACTIVE'
);
