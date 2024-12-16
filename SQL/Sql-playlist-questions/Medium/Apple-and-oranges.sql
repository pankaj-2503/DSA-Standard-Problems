


with cte as 
(
    select * from Sales
    order by sale_date,fruit
),
with cte2 as
(
    select *,lead(sold_num,1) over (partition by sale_date) as orange_num
    from cte
)

select sale_date,(sold_num-orange_num) as diff
from cte2 
where orange_num is not null
order by sale_date