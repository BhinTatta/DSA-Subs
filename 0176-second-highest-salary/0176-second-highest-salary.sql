# Write your MySQL query statement below
select max(e2.Salary) as SecondHighestSalary
from Employee e1 , Employee e2
where e1.Salary > e2.Salary

# select max(e2.Salary) as SecondHighestSalary
# from Employee e1, Employee e2
# where e1.Salary > e2.Salary