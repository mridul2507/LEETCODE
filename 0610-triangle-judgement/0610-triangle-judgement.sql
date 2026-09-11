# Write your MySQL query statement below
SELECT x, y, z,
CASE
    When x+y>z AND x+z>y AND y+z>x THEN 'Yes'
    Else 'No'
END AS triangle
FROM Triangle;
