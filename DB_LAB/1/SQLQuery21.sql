use DBMS3522;
select 
	Country, 
	count(EmployeeId) As Numbers 
from Employee
group by Country;
