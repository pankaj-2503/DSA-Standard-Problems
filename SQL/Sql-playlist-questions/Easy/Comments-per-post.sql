
Input: 
Submissions table:
+---------+------------+
| sub_id  | parent_id  |
+---------+------------+
| 1       | Null       |
| 2       | Null       |
| 1       | Null       |
| 12      | Null       |
| 3       | 1          |
| 5       | 2          |
| 3       | 1          |
| 4       | 1          |
| 9       | 1          |
| 10      | 2          |
| 6       | 7          |
+---------+------------+
Output: 
+---------+--------------------+
| post_id | number_of_comments |
+---------+--------------------+
| 1       | 3                  |
| 2       | 2                  |
| 12      | 0                  |
+---------+--------------------+

with posts as
(
    select distinct sub_id
    from Submissions
    where parent_id is null
),
com as
(
    select parent_id,count(distinct sub_id) as Num
    from Submissions 
    where
    parent_id is not null
    group by parent_id
)
select sub_id as post_id,case when Num is not null then
Num else 0 end as number_of_comments
from posts
left join com
on posts.sub_id=com.parent_id
order by post_id