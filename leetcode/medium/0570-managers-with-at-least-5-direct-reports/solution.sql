# Write your MySQL query statement below
select e1.name
from Employee  as e1
join
    (
        select managerId, count(*) as direct
        from  Employee 
        group by managerId
        having direct>=5
    )e2
    on e2.managerId = e1.id
