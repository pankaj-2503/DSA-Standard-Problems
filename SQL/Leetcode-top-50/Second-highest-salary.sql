

Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
Output:
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+

-- O(N^2)

select max(salary) as SecondHighestSalary
from employee
where salary<(
    select max(salary) from employee
)

-- O(NlogN)

select
(
    select salary
    from employee
    order by salary desc
    limit 1 offset 1
) as SecondHighestSalary

-- O(N)
SELECT MAX(salary) AS SecondHighestSalary
FROM (
    SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
    FROM Employee
) as ranked_table
WHERE rnk = 2;