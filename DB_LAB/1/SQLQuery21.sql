use DBMS3522;

SELECT
    Country,
    Count(EmployeeId) AS Numbers
FROM
    Employee
GROUP BY
    Country;

