INSERT INTO users (id, name, password, email)
VALUES (id, name, :password, email)

--EXCLUDE
SELECT id, name, password, email
FROM users
WHERE id = #{userID}

UPDATE users
SET name = name,
    password = :password,
    email = email
WHERE id = #{inputID}

DELETE FROM users
WHERE id = :userID