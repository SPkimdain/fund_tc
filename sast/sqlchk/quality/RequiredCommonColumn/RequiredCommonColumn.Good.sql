--EXCLUDE
INSERT INTO users (id, name, password, email)
VALUES (id, name, :password, email)

SELECT id, name, orderid, email
FROM users
WHERE id = #{userID}
AND orderid = :orderID

UPDATE users
SET name = name,
    password = :password,
    email = email,
    id = :orderID
WHERE id = #{userID}

--ALLOW
DELETE FROM users
WHERE id = :notid