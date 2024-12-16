
Input: 
MyNumbers table:
+-----+
| num |
+-----+
| 8   |
| 8   |
| 3   |
| 3   |
| 1   |
| 4   |
| 5   |
| 6   |
+-----+
Output: 
+-----+
| num |
+-----+
| 6   |
+-----+

# Write your MySQL query statement below

with cte as 
(
select num
from MyNumbers
group by num
having count(num)=1
)
select case when count(*)>0 then max(num)
else null end as num
from cte
