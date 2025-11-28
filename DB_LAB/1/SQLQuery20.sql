use DBMS3522;
select 
	EmployeeID,
	EmployeeName,
	max(AnnualIncome) As MaxIncome 
from Employee 
group by EmployeeID, EmployeeName;
