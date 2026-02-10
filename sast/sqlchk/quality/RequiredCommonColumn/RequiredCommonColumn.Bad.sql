INSERT INTO users (id, name, password, email) --@violation
VALUES (id, name, :password, email)

SELECT id, name, password, email    --@violation
FROM users
WHERE id = #{userID}

UPDATE users    --@violation
SET name = name,
    password = :password,
    email = email
    --,orderid = :orderID
WHERE id = #{userID}

DELETE FROM users   --@violation
WHERE id = :notid