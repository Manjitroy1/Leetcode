# Write your MySQL query statement below
select ifnull(
    (select max(salary)
        from Employee as e
        where salary < (select max(salary) from Employee)
    ),null)  as SecondHighestSalary;

-- select ifnull((select e.salary 
--     from Employee as e
--     order by e.salary desc
--     limit 1 offset 1),null) as SecondHighestSalary

