use zurat_petcare
create table Pets(
	pet_id INT IDENTITY(1,1) PRIMARY KEY,
	name VARCHAR(50),
	species VARCHAR(50),
	age INT,
	owner_name VARCHAR(100),
	last_visit DATE
);
