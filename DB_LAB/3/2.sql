use Johir_PetCare
select * from Student order by StudentID desc
select * from Course
select * from Enrollment
select * from Student where District='dhaka'

select 
	count(*) as count, 
	count(distinct(District)) as districts
from Student

select 
	District, 
	count(*) As Numbers
from Student
group by District;

select 
	StudentId as ID,
	StudentName as Name,
	District,
	Address
from Student
