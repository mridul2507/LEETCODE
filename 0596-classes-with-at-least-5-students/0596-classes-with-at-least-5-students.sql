# Write your MySQL query statement below
SELECT class From Courses
GROUP BY class HAVING COUNT(student)>=5;