Input:
Person table:
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
Output:
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+


-- O(N^2)
delete p1
from person p1,person p2
where p1.id>p2.id and p1.email=p2.email;

-- O(NlogN)

delete
from person
where id not in (
    select min_id from
        (
        select min(id) as min_id
        from person
        group by email;
        )
)

-- O(N)


with cte as (
    select id,
    row_number() over (partition by email order by id) as rn
    from person
)
delete from person
where id in (select id from cte where rn>1);
