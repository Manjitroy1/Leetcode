# Write your MySQL query statement below
-- order by desc or turn
select person_name 
from (
    select person_name,
    sum(weight) over (order by turn) as running_sum
    from Queue
) sumtable
where running_sum<=1000
order by running_sum desc
limit 1;