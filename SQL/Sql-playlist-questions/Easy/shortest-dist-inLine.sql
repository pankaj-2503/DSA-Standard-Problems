
-- Input:
-- Point
-- | x   |
-- |-----|
-- | -1  |
-- | 0   |
-- | 2   |

-- output:
-- | shortest|
-- |---------|
-- | 1       |


//approach 1 : but time consuming

select min(abs(p1.x-p2.x)) as shortest
from point p1
cross join point p2
where p1.x<>p2.x

// approach 2:

select min(abs(p1.x-p2.x)) as shortest
from point p1
inner join point p2
where p1.x<p2.x