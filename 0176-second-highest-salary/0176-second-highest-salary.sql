# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary FROM Employee where Employee.salary < (SELECT MAX(salary) FROM Employee);