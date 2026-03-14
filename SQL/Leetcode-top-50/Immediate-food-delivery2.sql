Input:
Delivery table:
+-------------+-------------+------------+-----------------------------+
| delivery_id | customer_id | order_date | customer_pref_delivery_date |
+-------------+-------------+------------+-----------------------------+
| 1           | 1           | 2019-08-01 | 2019-08-02                  |
| 2           | 2           | 2019-08-02 | 2019-08-02                  |
| 3           | 1           | 2019-08-11 | 2019-08-12                  |
| 4           | 3           | 2019-08-24 | 2019-08-24                  |
| 5           | 3           | 2019-08-21 | 2019-08-22                  |
| 6           | 2           | 2019-08-11 | 2019-08-13                  |
| 7           | 4           | 2019-08-09 | 2019-08-09                  |
+-------------+-------------+------------+-----------------------------+
Output:
+----------------------+
| immediate_percentage |
+----------------------+
| 50.00                |
+----------------------+


-- TC -> (N*M)
select round(avg(order_date=customer_pref_delivery_date)*100,2) as immediate_percentage
from delivery where (customer_id,order_date) in
(
select customer_id,min(order_date) as first_order
from delivery
group by customer_id
)

TC -> O(NlogN)
-- or
# Write your MySQL query statement below

with firstorders as (
    select order_date,customer_pref_delivery_date,rank() over (partition by customer_id order by order_date) as rnk
    from delivery
)
select round(avg(if(order_date=customer_pref_delivery_date,1,0))*100,2) as  immediate_percentage
from firstorders
where rnk=1;