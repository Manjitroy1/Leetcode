# Write your MySQL query statement below
select product_id,year as first_year,quantity,price
from Sales as s
where (product_id,year) in(
    select product_id,min(year)
    from Sales
    group by product_id
);
-- limit 1
-- group by product id 
-- order by asc year
-- limit 1

