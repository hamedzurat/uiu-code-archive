use DBMS3522;

SELECT
    'Max' AS Total,
    Max(AnnualIncome) AS MaxIncome,
    Min(AnnualIncome) AS MinIncome
FROM
    Employee;

