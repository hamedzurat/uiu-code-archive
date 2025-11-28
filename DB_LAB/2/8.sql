use Johir_PetCare
select * from Pets where age>6
select * from Pets where age between 6 and 7
select count(*) from Pets where age between 6 and 7
select 
	count(*) as COUNT,
	avg(age) as AVG,
	sum(age) as SUM 
from Pets
select 
	max(age) as MAX, 
	min(age) as MIN 
from Pets
select
	count(distinct(age)) as SETS
from Pets
