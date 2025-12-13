use Johir_PetCare;

SELECT
    *
FROM
    Student
ORDER BY
    StudentID DESC;

SELECT
    *
FROM
    Course;

SELECT
    *
FROM
    Enrollment;

SELECT
    *
FROM
    Student
WHERE
    District = 'dhaka';

SELECT
    count(*) AS count,
    count(DISTINCT (District)) AS districts
FROM
    Student;

SELECT
    District,
    count(*) AS Numbers
FROM
    Student
GROUP BY
    District;

SELECT
    StudentId AS ID,
    StudentName AS Name,
    District,
    Address
FROM
    Student;

