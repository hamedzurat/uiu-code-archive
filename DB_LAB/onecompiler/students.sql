-- 1. Create tables
CREATE TABLE Student (
    StudentID INT IDENTITY (1, 1) PRIMARY KEY,
    StudentName VARCHAR(16),
    FatherName VARCHAR(16),
    District VARCHAR(16),
    Address VARCHAR(16)
);

CREATE TABLE Course (
    CourseID INT IDENTITY (1, 1) PRIMARY KEY,
    CourseName VARCHAR(24),
    Credit INT
);

CREATE TABLE Enrollment (
    EnrollmentID INT IDENTITY (1, 1) PRIMARY KEY,
    StudentID INT NOT NULL,
    CourseID INT NOT NULL,
    Semester VARCHAR(20),
    Year INT,
    FOREIGN KEY (StudentID) REFERENCES Student (StudentID),
    FOREIGN KEY (CourseID) REFERENCES Course (CourseID)
);

-- 2. Insert sample data into Student
INSERT INTO Student (StudentName, FatherName, District, Address) VALUES
('Aminul Islam', 'Rahim Islam', 'Dhaka', 'Mirpur'),
('Shila Akter', 'Jamal Uddin', 'Chittagong', 'Pahartali'),
('Tanvir Hasan', 'Selim Hasan', 'Dhaka', 'Uttara'),
('Rafiul Karim', 'Karim Uddin', 'Rajshahi', 'Boalia'),
('Mim Chowdhury', 'Anis Chowdhury', 'Dhaka', 'Dhanmondi');

-- 3. Insert sample data into Course
INSERT INTO Course (CourseName, Credit) VALUES
('Database Systems', 3),
('Computer Networks', 3),
('Data Structures', 3),
('Operating Systems', 4);

-- 4. Insert sample data into Enrollment
INSERT INTO Enrollment (StudentID, CourseID, Semester, Year) VALUES
(1, 1, 'Spring', 2025),
(1, 2, 'Spring', 2025),
(2, 1, 'Spring', 2025),
(3, 3, 'Summer', 2025),
(4, 4, 'Fall', 2025),
(5, 2, 'Fall', 2025);

GO

-- 5. Create the view (must be in its own batch in SQL Server)
CREATE VIEW VwStudentEnroll
AS
SELECT
    s.StudentID,
    s.StudentName,
    s.FatherName,
    s.District,
    s.Address,
    c.Credit,
    c.CourseName,
    c.CourseID,
    e.EnrollmentID,
    e.Semester,
    e.Year,
    e.CourseID AS Expr1,
    e.StudentID AS Expr2
FROM Enrollment e
INNER JOIN Student s ON e.StudentID = s.StudentID
INNER JOIN Course c ON e.CourseID = c.CourseID;

GO

-- 6. Your queries

PRINT '===== DUMP =====';

-- SELECT * FROM Student;
SELECT * FROM Student
ORDER BY StudentID DESC;
SELECT * FROM Student
WHERE District = 'Dhaka';
SELECT * FROM Course;
SELECT * FROM Enrollment;

PRINT '===== COUNT =====';

SELECT COUNT(*) AS C FROM Student;

PRINT '===== DISTINCT =====';

SELECT DISTINCT District FROM Student;

SELECT
    District,
    COUNT(*) AS TotalStudent
FROM Student
GROUP BY District;

PRINT '===== Virtual Table =====';

SELECT * FROM VwStudentEnroll;
