CREATE TABLE Pets (
    pet_id INT IDENTITY (1, 1) PRIMARY KEY,
    name VARCHAR(50),
    species VARCHAR(50),
    age INT,
    owner_name VARCHAR(100),
    last_visit DATE
);

SELECT * FROM Pets;

INSERT INTO Pets (name, species, age, owner_name, last_visit)
VALUES
('Kirara', 'Demon Cat', 5, 'Kagome Higurashi', '2025-09-15'),
('Chibi', 'Spirit Dog', 2, 'Shoyo Hinata', '2025-10-05'),
('Nyanko-sensei', 'Spirit Cat', 7, 'Madara', '2025-11-15'),
('Makkuro', 'Black Spirit Cat', 3, 'Sailor Moon', '2025-08-20'),
('Baron', 'Cat Butler', 5, 'Satsuki', '2025-07-12'),
('Totoro', 'Forest Spirit', 100, 'Satsuki & Mei', '2025-07-01'),
('Puar', 'Talking Cat', 6, 'Yamcha', '2025-09-22');

SELECT * FROM Pets;

UPDATE Pets SET owner_name = 'eee'
WHERE pet_id = 4;

DELETE Pets
WHERE pet_id = 2;

SELECT * FROM Pets;

SELECT * FROM Pets
WHERE name LIKE 'm%';

SELECT * FROM Pets
WHERE name LIKE '%i%';

SELECT * FROM Pets
WHERE age > 6;

SELECT * FROM Pets
WHERE age BETWEEN 6 AND 7;

SELECT COUNT(*) AS C FROM Pets
WHERE age BETWEEN 6 AND 7;

SELECT
    COUNT(*) AS COUNT,
    AVG(age) AS AVG,
    SUM(age) AS SUM
FROM Pets;

SELECT
    MAX(age) AS MAX,
    MIN(age) AS MIN
FROM Pets;

SELECT COUNT(DISTINCT age) AS SETS
FROM Pets;
