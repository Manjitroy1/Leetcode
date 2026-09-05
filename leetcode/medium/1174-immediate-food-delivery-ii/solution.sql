# Write your MySQL query statement below
-- //we have to count total number of row
-- //total number where order=pref date
select round(avg(order_date=customer_pref_delivery_date)*100,2) as immediate_percentage
from delivery as d
where order_date=(
    select min(order_date)
    from delivery 
    where customer_id = d.customer_id
)