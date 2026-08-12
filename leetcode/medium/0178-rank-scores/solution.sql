# Write your MySQL query statement below
select score,
        dense_rank() over (order by s.score desc) as `rank`
    from Scores as s;