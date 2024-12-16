Input: 
Customers table:
+----+-------+
| id | name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Orders table:
+----+------------+
| id | customerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
Output: 
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |


// Approach 1

select c.name as Customers 
from Customers c left join Orders o
on c.id=o.customerId where o.id is null


// Another approach

select c.name as "Customers"
from Customers c
where c.id not in
(
select c.id as Customers 
from Customers c inner join Orders o
on c.id=o.customerId
)

