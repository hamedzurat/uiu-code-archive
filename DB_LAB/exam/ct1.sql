create database CPT1_0112330113;

USE CPT1_0112330113;

CREATE TABLE Competition_Students(
	StudentID INT PRIMARY KEY,
	StudentName varchar(50) NOT NULL,
	Department VARCHAR(30) NOT NULL,
	Semester INT CHECK(Semester BETWEEN 1 AND 8),
	Score Numeric(5,2) CHECK (Score>=0),
	EventDate DATE
);

INSERT INTO Competition_Students (StudentID, StudentName, Department, Semester, Score, EventDate) VALUES 
(1,'A', 'dept1', 1, 2, '10/10/2025'),
(2,'B', 'dept1', 2, 6, '10/10/2025'),
(3,'C', 'dept1', 3, 7, '10/10/2025'),
(4,'D', 'dept2', 1, 8, '10/10/2025'),
(5,'E', 'dept2', 2, 1, '10/10/2025'),
(6,'F', 'dept2', 3, 2, '10/10/2025'),
(7,'G', 'dept3', 1, 3, '10/10/2025'),
(8,'H', 'dept3', 4, 0, '10/10/2025'),
(9,'I', 'dept3', 5, 0, '10/10/2025'),
(10,'J', 'dept1', 6, 2, '10/10/2025'),
(11,'K', 'dept1', 7, 4, '10/10/2025'),
(12,'L', 'dept2', 4, 5, '10/10/2025'),
(13,'M', 'dept2', 2, 6, '10/10/2025'),
(14,'O', 'dept3', 7, 3, '10/10/2025'),
(15,'P', 'dept3', 1, 1, '10/10/2025');

SELECT 
	COUNT(*) AS COUNT,
	AVG(Score) AS AVG,
	MAX(Score) AS MAX,
	MIN(Score) AS MIN
FROM Competition_Students;

SELECT 
	Department,
	COUNT(*) AS COUNT,
	AVG(Score) AS AVG
FROM Competition_Students
GROUP BY Department;

SELECT * FROM Competition_Students;
