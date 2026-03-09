Input:
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
Output:
+----+
| id |
+----+
| 2  |
| 4  |
+----+

-- Brute force -> O(N^2)
SELECT p1.id
FROM Weather p1, Weather p2
WHERE DATEDIFF(p1.recordDate, p2.recordDate) = 1
  AND p1.temperature > p2.temperature;


-- O(NlogN)
select w1.id
from Weather w1
where temperature > (
    select temperature
    from Weather w2
    where w2.recordDate=DATE_SUB(w1.recordDate,INTERVAL 1 DAY)
);


-- Most optimised solution ->O(N)

SELECT id
FROM (
    SELECT id, recordDate, temperature,
           LAG(temperature) OVER (ORDER BY recordDate) AS prev_temp,
           LAG(recordDate) OVER (ORDER BY recordDate) AS prev_date
    FROM Weather
) as temp_table
WHERE temperature > prev_temp
  AND DATEDIFF(recordDate, prev_date) = 1;
