# Consecutive Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Table: `Logs`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
In SQL, id is the primary key for this table.
id is an autoincrement column starting from 1.

```

 

Find all numbers that appear at least three times consecutively.

Return the result table in  **any order**.

The result format is in the following example.

 

 **Example 1:** 

```
Input: 
Logs table:
+----+-----+
| id | num |
+----+-----+
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |
+----+-----+
Output: 
+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+
Explanation: 1 is the only number that appears consecutively for at least three times.

```

## Solution

**Language:** SQL  
**Runtime:** 633 ms (beats 37.23%)  
**Memory:** 0B (beats 100.00%)  
**Submitted:** 2026-08-12T11:44:00.585Z  

```sql
# Write your MySQL query statement below
-- select distinct l1.num as ConsecutiveNums
-- from Logs as l1
-- join Logs as l2
--     on l2.id = l1.id + 1
-- join Logs as l3
--     on l3.id = l2.id + 1
-- where l1.num = l2.num and l2.num = l3.num

select distinct l1.num as ConsecutiveNums
from Logs as l1, Logs as l2, Logs as l3
where l1.id+1 = l2.id and l2.id+1 =l3.id and l1.num = l2.num and l2.num = l3.num
```

---

[View on LeetCode](https://leetcode.com/problems/consecutive-numbers/)