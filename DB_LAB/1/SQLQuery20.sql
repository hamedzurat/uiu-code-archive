use DBMS3522;

SELECT
    EmployeeID,
    EmployeeName,
    Max(AnnualIncome) AS MaxIncome
FROM
    Employee
GROUP BY
    EmployeeID,
    EmployeeName;

