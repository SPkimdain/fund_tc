INSERT INTO users (id, name, password, email) --@violation
VALUES (#{userID}, name, :password, email)

SELECT id, name, password, email    --@violation
FROM users
WHERE id = #{userID}

UPDATE users    --@violation
SET name = name,
    password = :password,
    email = email
WHERE id = #{userID}

DELETE FROM users   --@violation
WHERE id = :orderID