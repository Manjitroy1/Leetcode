# Write your MySQL query statement below
select u.user_id as buyer_id, u.join_date,count(o.order_id) as orders_in_2019
from Users as u
left join  
Orders as o
on o.buyer_id =u.user_id and year(order_date) = '2019'
group by u.user_id