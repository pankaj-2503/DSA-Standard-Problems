Input:
Users table:
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | aLice |
| 2       | bOB   |
+---------+-------+
Output:
+---------+-------+
| user_id | name  |
+---------+-------+
| 1       | Alice |
| 2       | Bob   |
+---------+-------+

select user_id,
    concat(
        upper(left(name,1)),
        lower(substring(name,2))
    ) as name
from users
order by user_id;