# Second Highest Salary

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Table: `Employee`

```
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
id is the primary key (column with unique values) for this table.
Each row of this table contains information about the salary of an employee.

```

 

Write a solution to find the second highest  **distinct**  salary from the `Employee` table. If there is no second highest salary, return `null (return None in Pandas)`.

The result format is in the following example.

 

 **Example 1:** 

```
Input: 
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

```

 **Example 2:** 

```
Input: 
Employee table:
+----+--------+
| id | salary |
+----+--------+
| 1  | 100    |
+----+--------+
Output: 
+---------------------+
| SecondHighestSalary |
+---------------------+
| null                |
+---------------------+

```

## Solution

**Language:** SQL  
**Runtime:** 98 ms  
**Memory:** 0B  
**Submitted:** 2026-08-12T10:26:14.647Z  

```sql
# Write your MySQL query statement below
select ifnull(
    (select max(salary)
        from Employee as e
        where salary < (select max(salary) from Employee)
    ),null)  as SecondHighestSalary;

-- select ifnull((select e.salary 
--     from Employee as e
--     order by e.salary desc
--     limit 1 offset 1),null) as SecondHighestSalary


```

---

[View on LeetCode](https://leetcode.com/problems/second-highest-salary/)