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

select MAX(num) as num
from (
    select num
    from MyNumbers
    group by num
    having count(num)=1
) as unique_numbers;