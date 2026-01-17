-- =============================================
-- Create Tables
-- =============================================
-- Student Table
CREATE TABLE Student (
    StudentID INT IDENTITY (1, 1) PRIMARY KEY,
    StudentName NVARCHAR (30) NOT NULL,
    Department NVARCHAR (30) NOT NULL,
    AdmissionDate DATE NOT NULL,
    HomeDistrict NVARCHAR (10) NOT NULL
);

-- Course Table
CREATE TABLE Course (
    CourseID INT IDENTITY (1, 1) PRIMARY KEY,
    CourseName NVARCHAR (35) NOT NULL,
    CourseCredit INT NOT NULL
);

-- CourseRegistration Table
CREATE TABLE CourseRegistration (
    RegistrationID INT IDENTITY (1, 1) PRIMARY KEY,
    StudentID INT NOT NULL,
    CourseID INT NOT NULL,
    Semester NVARCHAR (20) NOT NULL,
    FOREIGN KEY (StudentID) REFERENCES Student (StudentID),
    FOREIGN KEY (CourseID) REFERENCES Course (CourseID)
);

GO
-- =============================================
-- Insert Sample Data
-- =============================================
-- Insert 100 Students
INSERT INTO Student (StudentName, Department, AdmissionDate, HomeDistrict)
VALUES
    ('Ahmed Rahman', 'Computer Science', '2023-01-15', 'Dhaka'),
    ('Fatima Khan', 'Electrical Engineering', '2023-01-20', 'Chittagong'),
    ('Mohammad Ali', 'Mechanical Engineering', '2023-02-01', 'Sylhet'),
    ('Rashida Begum', 'Civil Engineering', '2023-02-10', 'Rajshahi'),
    ('Karim Uddin', 'Computer Science', '2023-02-15', 'Khulna'),
    ('Nasreen Akter', 'Business Administration', '2023-03-01', 'Barisal'),
    ('Rafiq Hassan', 'Economics', '2023-03-05', 'Rangpur'),
    ('Salma Khatun', 'Mathematics', '2023-03-10', 'Mymensingh'),
    ('Habib Ullah', 'Physics', '2023-03-15', 'Comilla'),
    ('Ruma Parvin', 'Chemistry', '2023-03-20', 'Jessore'),
    ('Tariq Ahmed', 'Computer Science', '2023-04-01', 'Dhaka'),
    ('Shahana Begum', 'Electrical Engineering', '2023-04-05', 'Chittagong'),
    ('Mizanur Rahman', 'Mechanical Engineering', '2023-04-10', 'Sylhet'),
    ('Kulsum Akter', 'Civil Engineering', '2023-04-15', 'Rajshahi'),
    ('Jahangir Alam', 'Business Administration', '2023-04-20', 'Khulna'),
    ('Rehana Khatun', 'Economics', '2023-05-01', 'Barisal'),
    ('Shafiq Uddin', 'Mathematics', '2023-05-05', 'Rangpur'),
    ('Nasir Ahmed', 'Physics', '2023-05-10', 'Mymensingh'),
    ('Roksana Begum', 'Chemistry', '2023-05-15', 'Comilla'),
    ('Aminul Islam', 'Computer Science', '2023-05-20', 'Jessore'),
    ('Taslima Akter', 'Electrical Engineering', '2023-06-01', 'Dhaka'),
    ('Golam Mostafa', 'Mechanical Engineering', '2023-06-05', 'Chittagong'),
    ('Shireen Sultana', 'Civil Engineering', '2023-06-10', 'Sylhet'),
    ('Delwar Hossain', 'Business Administration', '2023-06-15', 'Rajshahi'),
    ('Rashida Khatun', 'Economics', '2023-06-20', 'Khulna'),
    ('Motiur Rahman', 'Mathematics', '2023-07-01', 'Barisal'),
    ('Farida Begum', 'Physics', '2023-07-05', 'Rangpur'),
    ('Anwar Hossain', 'Chemistry', '2023-07-10', 'Mymensingh'),
    ('Salina Akter', 'Computer Science', '2023-07-15', 'Comilla'),
    ('Rahim Uddin', 'Electrical Engineering', '2023-07-20', 'Jessore'),
    ('Nasreen Sultana', 'Mechanical Engineering', '2023-08-01', 'Dhaka'),
    ('Fazlul Karim', 'Civil Engineering', '2023-08-05', 'Chittagong'),
    ('Rahima Khatun', 'Business Administration', '2023-08-10', 'Sylhet'),
    ('Shahidul Islam', 'Economics', '2023-08-15', 'Rajshahi'),
    ('Morsheda Begum', 'Mathematics', '2023-08-20', 'Khulna'),
    ('Nurul Amin', 'Physics', '2023-09-01', 'Barisal'),
    ('Rashida Parvin', 'Chemistry', '2023-09-05', 'Rangpur'),
    ('Khalil Ahmed', 'Computer Science', '2023-09-10', 'Mymensingh'),
    ('Sultana Razia', 'Electrical Engineering', '2023-09-15', 'Comilla'),
    ('Abdur Rahman', 'Mechanical Engineering', '2023-09-20', 'Jessore'),
    ('Fatema Khatun', 'Civil Engineering', '2023-10-01', 'Dhaka'),
    ('Mosharraf Hossain', 'Business Administration', '2023-10-05', 'Chittagong'),
    ('Rahela Begum', 'Economics', '2023-10-10', 'Sylhet'),
    ('Shamsul Haque', 'Mathematics', '2023-10-15', 'Rajshahi'),
    ('Nasir Uddin', 'Physics', '2023-10-20', 'Khulna'),
    ('Rashida Sultana', 'Chemistry', '2023-11-01', 'Barisal'),
    ('Golam Rabbani', 'Computer Science', '2023-11-05', 'Rangpur'),
    ('Salma Begum', 'Electrical Engineering', '2023-11-10', 'Mymensingh'),
    ('Rafiqul Islam', 'Mechanical Engineering', '2023-11-15', 'Comilla'),
    ('Nasreen Parvin', 'Civil Engineering', '2023-11-20', 'Jessore'),
    ('Aminur Rahman', 'Business Administration', '2023-12-01', 'Dhaka'),
    ('Rashida Akter', 'Economics', '2023-12-05', 'Chittagong'),
    ('Shahjalal Ahmed', 'Mathematics', '2023-12-10', 'Sylhet'),
    ('Kulsum Begum', 'Physics', '2023-12-15', 'Rajshahi'),
    ('Delwar Hossain', 'Chemistry', '2023-12-20', 'Khulna'),
    ('Tahmina Akter', 'Computer Science', '2024-01-01', 'Barisal'),
    ('Golam Sarwar', 'Electrical Engineering', '2024-01-05', 'Rangpur'),
    ('Rashida Khanom', 'Mechanical Engineering', '2024-01-10', 'Mymensingh'),
    ('Nurul Huda', 'Civil Engineering', '2024-01-15', 'Comilla'),
    ('Salma Parvin', 'Business Administration', '2024-01-20', 'Jessore'),
    ('Rafiq Uddin', 'Economics', '2024-02-01', 'Dhaka'),
    ('Nasreen Begum', 'Mathematics', '2024-02-05', 'Chittagong'),
    ('Aminul Haque', 'Physics', '2024-02-10', 'Sylhet'),
    ('Rashida Rahman', 'Chemistry', '2024-02-15', 'Rajshahi'),
    ('Golam Kibria', 'Computer Science', '2024-02-20', 'Khulna'),
    ('Fatima Sultana', 'Electrical Engineering', '2024-03-01', 'Barisal'),
    ('Mohammad Hasan', 'Mechanical Engineering', '2024-03-05', 'Rangpur'),
    ('Rashida Nasreen', 'Civil Engineering', '2024-03-10', 'Mymensingh'),
    ('Karim Hassan', 'Business Administration', '2024-03-15', 'Comilla'),
    ('Salma Khanom', 'Economics', '2024-03-20', 'Jessore'),
    ('Habibur Rahman', 'Mathematics', '2024-04-01', 'Dhaka'),
    ('Ruma Sultana', 'Physics', '2024-04-05', 'Chittagong'),
    ('Tariqul Islam', 'Chemistry', '2024-04-10', 'Sylhet'),
    ('Shahana Parvin', 'Computer Science', '2024-04-15', 'Rajshahi'),
    ('Mizanul Haque', 'Electrical Engineering', '2024-04-20', 'Khulna'),
    ('Kulsum Parvin', 'Mechanical Engineering', '2024-05-01', 'Barisal'),
    ('Jahangir Hossain', 'Civil Engineering', '2024-05-05', 'Rangpur'),
    ('Rehana Sultana', 'Business Administration', '2024-05-10', 'Mymensingh'),
    ('Shafiqul Islam', 'Economics', '2024-05-15', 'Comilla'),
    ('Nasir Hossain', 'Mathematics', '2024-05-20', 'Jessore'),
    ('Roksana Parvin', 'Physics', '2024-06-01', 'Dhaka'),
    ('Aminul Rahman', 'Chemistry', '2024-06-05', 'Chittagong'),
    ('Taslima Khatun', 'Computer Science', '2024-06-10', 'Sylhet'),
    ('Golam Mostafa', 'Electrical Engineering', '2024-06-15', 'Rajshahi'),
    ('Shireen Akter', 'Mechanical Engineering', '2024-06-20', 'Khulna'),
    ('Delwar Rahman', 'Civil Engineering', '2024-07-01', 'Barisal'),
    ('Rashida Begum', 'Business Administration', '2024-07-05', 'Rangpur'),
    ('Motiur Hossain', 'Economics', '2024-07-10', 'Mymensingh'),
    ('Farida Khatun', 'Mathematics', '2024-07-15', 'Comilla'),
    ('Anwar Rahman', 'Physics', '2024-07-20', 'Jessore'),
    ('Salina Begum', 'Chemistry', '2024-08-01', 'Dhaka'),
    ('Rahim Hossain', 'Computer Science', '2024-08-05', 'Chittagong'),
    ('Nasreen Khatun', 'Electrical Engineering', '2024-08-10', 'Sylhet'),
    ('Fazlur Rahman', 'Mechanical Engineering', '2024-08-15', 'Rajshahi'),
    ('Rahima Sultana', 'Civil Engineering', '2024-08-20', 'Khulna'),
    ('Shahidul Haque', 'Business Administration', '2024-09-01', 'Barisal'),
    ('Morsheda Khatun', 'Economics', '2024-09-05', 'Rangpur'),
    ('Nurul Islam', 'Mathematics', '2024-09-10', 'Mymensingh'),
    ('Rashida Hossain', 'Physics', '2024-09-15', 'Comilla'),
    ('Khalilur Rahman', 'Chemistry', '2024-09-20', 'Jessore'),
    ('Sultana Begum', 'Computer Science', '2024-10-01', 'Dhaka'),
    ('Abdur Rahim', 'Electrical Engineering', '2024-10-05', 'Chittagong'),
    ('Fatema Sultana', 'Mechanical Engineering', '2024-10-10', 'Sylhet'),
    ('Mosharraf Uddin', 'Civil Engineering', '2024-10-15', 'Rajshahi'),
    ('Rahela Khatun', 'Business Administration', '2024-10-20', 'Khulna');

-- Insert 10 Courses
INSERT INTO Course (CourseName, CourseCredit)
VALUES
    ('Introduction to Programming', 3),
    ('Data Structures and Algorithms', 4),
    ('Database Management Systems', 3),
    ('Computer Networks', 3),
    ('Software Engineering', 4),
    ('Web Development', 3),
    ('Machine Learning', 4),
    ('Cybersecurity Fundamentals', 3),
    ('Mobile App Development', 3),
    ('Artificial Intelligence', 4);

-- Insert 25 Course Registrations
INSERT INTO CourseRegistration (StudentID, CourseID, Semester)
VALUES
    (1, 1, 'Spring 2024'),
    (1, 3, 'Spring 2024'),
    (2, 2, 'Spring 2024'),
    (2, 4, 'Spring 2024'),
    (3, 1, 'Fall 2023'),
    (3, 5, 'Fall 2023'),
    (4, 6, 'Spring 2024'),
    (4, 7, 'Spring 2024'),
    (5, 1, 'Fall 2023'),
    (5, 2, 'Spring 2024'),
    (6, 8, 'Spring 2024'),
    (7, 9, 'Fall 2023'),
    (8, 10, 'Spring 2024'),
    (9, 1, 'Fall 2023'),
    (10, 3, 'Spring 2024'),
    (11, 2, 'Fall 2023'),
    (12, 4, 'Spring 2024'),
    (13, 5, 'Fall 2023'),
    (14, 6, 'Spring 2024'),
    (15, 7, 'Fall 2023'),
    (16, 8, 'Spring 2024'),
    (17, 9, 'Fall 2023'),
    (18, 10, 'Spring 2024'),
    (19, 1, 'Fall 2023'),
    (20, 2, 'Spring 2024');

GO;

-- =============================================
-- Sample Queries to Test the Database
-- =============================================
-- View all students
SELECT
    *
FROM
    Student;

-- View all courses
SELECT
    *
FROM
    Course;

-- View all registrations with student and course details
SELECT
    s.StudentName,
    c.CourseName,
    cr.Semester
FROM
    CourseRegistration cr
    JOIN Student s ON cr.StudentID = s.StudentID
    JOIN Course c ON cr.CourseID = c.CourseID
ORDER BY
    s.StudentName;

-- Count students by department
SELECT
    Department,
    Count(*) AS StudentCount
FROM
    Student
GROUP BY
    Department
ORDER BY
    StudentCount DESC;

-- Count students by district
SELECT
    HomeDistrict,
    Count(*) AS StudentCount
FROM
    Student
GROUP BY
    HomeDistrict
ORDER BY
    StudentCount DESC;

GO;

