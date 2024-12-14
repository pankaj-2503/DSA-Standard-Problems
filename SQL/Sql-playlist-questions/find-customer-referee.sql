
Input: 
Customer table:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+
Output: 
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+


// approach 1

select name
from Customer
where referee_id!=2 or referee_id is null

// approach 2
SELECT name  
FROM Customers  
WHERE id IS NOT NULL AND NOT IN (  
  SELECT referee_id  
  FROM Customers  
  WHERE id = 2  
);  