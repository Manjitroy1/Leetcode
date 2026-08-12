# Managers with at Least 5 Direct Reports

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Table: `Employee`

```
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.

```

 

Write a solution to find managers with at least  **five direct reports**.

Return the result table in  **any order**.

The result format is in the following example.

 

 **Example 1:** 

```
Input: 
Employee table:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
Output: 
+------+
| name |
+------+
| John |
+------+

```

## Solution

**Language:** SQL  
**Runtime:** 499 ms (beats 10.78%)  
**Memory:** 0B (beats 100.00%)  
**Submitted:** 2026-08-12T13:05:24.822Z  

```sql
# Write your MySQL query statement below
select e1.name
from Employee  as e1
join
    (
        select managerId, count(*) as direct
        from  Employee 
        group by managerId
        having direct>=5
    )e2
    on e2.managerId = e1.id

```

---

[View on LeetCode](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/)