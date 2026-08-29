# Write your MySQL query statement below
Select eu.unique_id AS unique_id ,e.name AS name
FROM Employees e
LEFT JOIN EmployeeUNI eu
ON e.id=eu.id