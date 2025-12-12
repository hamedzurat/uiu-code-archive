use zurat_petcare;

DROP TABLE Student;
DROP TABLE Department;

CREATE TABLE Department(
	DeptId INT PRIMARY KEY,
	DeptName VARCHAR(50) NOT NULL
);

CREATE TABLE Student (
	StdId INT PRIMARY KEY,
	StdName VARCHAR(50) NOT NULL,
	DeptId INT,
	FOREIGN KEY (DeptId) REFERENCES Department(DeptId)
);

INSERT INTO Department (DeptId, DeptName) VALUES
(101, 'CSE'),
(102, 'BBA');

INSERT INTO Student (StdId, StdName, DeptId) VALUES
(1, 'John', 101),
(2, 'Kim', 101),
(3, 'Jemes', 102),
(4, 'Bob', 101);

SELECT * FROM Department;
SELECT * FROM Student;

SELECT 
    Student.StdId,
    Student.StdName,
    Student.DeptId,
    Department.DeptName
FROM Student
JOIN Department
    ON Student.DeptId = Department.DeptId;
