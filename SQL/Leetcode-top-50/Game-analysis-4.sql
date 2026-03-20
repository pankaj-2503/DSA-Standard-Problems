
Input:
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-03-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
Output:
+-----------+
| fraction  |
+-----------+
| 0.33      |
+-----------+

-- O(N^2) solution

SELECT
  ROUND(COUNT(DISTINCT player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM
  Activity
WHERE
  (player_id, DATE_SUB(event_date, INTERVAL 1 DAY))
  IN (
    SELECT player_id, MIN(event_date) AS first_login FROM Activity GROUP BY player_id
  );

  -- O(Nlogn)


WITH FirstLogin AS (
    -- Step 1: Identify the first login date for every player
    SELECT
        player_id,
        MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
)
SELECT
    ROUND(
        COUNT(DISTINCT a.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM Activity a
JOIN FirstLogin f ON a.player_id = f.player_id
-- Step 2: Filter for logins that occurred exactly one day after the first login
WHERE a.event_date = DATE_ADD(f.first_date, INTERVAL 1 DAY);


-- O(N)

WITH PlayerLogins AS (
    SELECT
        player_id,
        event_date,
        -- Get the very first login date for this player across all their rows
        MIN(event_date) OVER(PARTITION BY player_id) AS first_login,
        -- Get the date of the "next" login in chronological order
        LEAD(event_date) OVER(PARTITION BY player_id ORDER BY event_date) AS next_login
    FROM Activity
)
SELECT
    ROUND(
        COUNT(DISTINCT CASE
            WHEN next_login = DATE_ADD(first_login, INTERVAL 1 DAY)
            THEN player_id
        END)
        / COUNT(DISTINCT player_id),
    2) AS fraction
FROM PlayerLogins;
