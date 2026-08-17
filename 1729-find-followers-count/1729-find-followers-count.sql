# Write your MySQL query statement below
SELECT user_id
    ,count(*) as followers_count from followers
GROUP BY user_id
ORDER BY user_id