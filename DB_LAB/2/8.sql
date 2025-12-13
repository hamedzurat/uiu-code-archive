use Johir_PetCare;

SELECT
    *
FROM
    Pets
WHERE
    age > 6;

SELECT
    *
FROM
    Pets
WHERE
    age BETWEEN 6 AND 7;

SELECT
    count(*)
FROM
    Pets
WHERE
    age BETWEEN 6 AND 7;

SELECT
    count(*) AS COUNT,
    avg(age) AS AVG,
    sum(age) AS SUM
FROM
    Pets;

SELECT
    max(age) AS MAX,
    min(age) AS MIN
FROM
    Pets;

SELECT
    count(DISTINCT (age)) AS SETS
FROM
    Pets;

