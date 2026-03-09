Products table:
+------------+-----------+-------------+
| product_id | new_price | change_date |
+------------+-----------+-------------+
| 1          | 20        | 2019-08-14  |
| 2          | 50        | 2019-08-14  |
| 1          | 30        | 2019-08-15  |
| 1          | 35        | 2019-08-16  |
| 2          | 65        | 2019-08-17  |
| 3          | 20        | 2019-08-18  |
+------------+-----------+-------------+
Output:
+------------+-------+
| product_id | price |
+------------+-------+
| 2          | 50    |
| 1          | 35    |
| 3          | 10    |
+------------+-------+

# Write your MySQL query statement below
select product_id,price
from(
    select product_id,new_price as price,rank() over (partition by product_id order by  change_date desc) as rnk
    from products
    where change_date<='2019-08-16'
) t
where rnk=1
union

select distinct product_id,10 as price
from products
group by product_id
having min(change_date)>'2019-08-16';