SELECT s.id, s.name, s.old
FROM source_table s

SELECT s.id, s.name, a.old
FROM source_table s, another_table a

SELECT A.ID, A.NAME, B.ORDER_DATE
FROM USERS A
         JOIN ORDERS B ON A.ID = B.USER_ID
WHERE A.STATUS = 'ACTIVE';

SELECT A.ID, A.NAME, B.ORDER_DATE
FROM USERS A, ORDERS B
WHERE A.ID = B.USER_ID;

SELECT A.ID, A.NAME, A.EMAIL
FROM USERS A
WHERE A.STATUS = 'ACTIVE';

SELECT A.ID, A.NAME
FROM USERS A
WHERE EXISTS (
              SELECT B.USER_ID
              FROM ORDERS B
              WHERE B.USER_ID = A.ID
          );

INSERT INTO target_table (id, name, old)
SELECT s.id, s.name, s.old
FROM source_table s
         JOIN another_table a ON s.id = a.source_id
WHERE a.status = 'ACTIVE';

INSERT INTO target_table (id, name, old)
SELECT s.id, s.name, s.old
FROM source_table s, another_table a
WHERE s.id = a.source_id
  AND a.status = 'ACTIVE';

UPDATE target_table t
SET t.old = (SELECT s.old
             FROM source_table s, another_table a
             WHERE s.id = a.source_id
               AND a.status = 'ACTIVE'
               AND t.id = s.id)
WHERE EXISTS (
              SELECT 1 FROM source_table s, another_table a
              WHERE s.id = a.source_id
                AND a.status = 'ACTIVE'
                AND t.id = s.id
          );

DELETE FROM target_table t
WHERE t.id IN (
    SELECT s.id
    FROM source_table s, another_table a
    WHERE s.id = a.source_id
      AND a.status = 'INACTIVE'
);
