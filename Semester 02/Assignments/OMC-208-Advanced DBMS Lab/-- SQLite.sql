-- SQLite
SELECT * FROM Candidate

-- Create table
CREATE TABLE Student (
    Name VARCHAR2(50),
    Roll_No NUMBER,
    Course VARCHAR2(50),
    Date_Of_Admn DATE
);

-- Insert data
INSERT INTO Student VALUES ('Amit', 1, 'BCA', TO_DATE('12/July/19', 'DD/MON/YY'));
INSERT INTO Student VALUES ('Sumit', 2, NULL, TO_DATE('13/June/19', 'DD/MON/YY'));
INSERT INTO Student VALUES ('Raghav', 3, NULL, NULL);
INSERT INTO Student VALUES ('Suman', 4, 'BCA', NULL);

-- Query a) Retrieve data of all students
SELECT * FROM Student;

-- Query b) Retrieve data of students whose course is null
SELECT * FROM Student WHERE Course IS NULL;

-- Query c) Find the name of student whose roll number is 2
SELECT Name FROM Student WHERE Roll_No = 2;

-- Query d) Delete all data
DELETE FROM Student;
