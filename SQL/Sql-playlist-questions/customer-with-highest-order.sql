Input: 
Orders table:
+--------------+-----------------+
| order_number | customer_number |
+--------------+-----------------+
| 1            | 1               |
| 2            | 2               |
| 3            | 3               |
| 4            | 3               |
+--------------+-----------------+
Output: 
+-----------------+
| customer_number |
+-----------------+
| 3               |
+-----------------+

# Write your MySQL query statement below
with cte as (
    select customer_number,count(order_number) as NumOrder
    from Orders
    group by customer_number
)
select customer_number
from cte 
where NumOrder=(select max(NumOrder) from cte)


// Approach 2
select customer_number
from Orders 
group by customer_number 
order by count(customer_number)
desc limit 1;