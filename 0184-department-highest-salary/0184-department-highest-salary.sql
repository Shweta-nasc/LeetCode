# Write your MySQL query statement below
SELECT      
    D.name AS Department ,
    E.name AS Employee ,
    E.salary AS Salary
FROM Employee E
JOIN Department D
    ON D.id=E.departmentId
WHERE E.salary=(
    SELECT MAX(E2.salary)
    FROM Employee E2
    WHERE E2.departmentId=E.departmentId
)
