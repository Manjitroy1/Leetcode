# Q1. Largest Integer With Given Digit Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given two non-negative integers `n` and `s`.

Return the  **largest**  integer that has  **at most**  `n` digits and whose sum of digits is `s`. If no such integer exists, return -1.

 

 **Example 1:** 

 **Input:**  n = 2, s = 9

 **Output:**  90

 **Explanation:** 

The largest integer with at most 2 digits that has a sum of digits of 9 is 90.

 **Example 2:** 

 **Input:**  n = 2, s = 19

 **Output:**  -1

 **Explanation:** 

There is no integer with at most 2 digits that has a sum of digits of 19, so the answer is -1.

 **Example 3:** 

 **Input:**  n = 5, s = 0

 **Output:**  0

 **Explanation:** 

The only non-negative integer whose digits sum to 0 is 0.

 

 **Constraints:** 

- 1 <= n <= 5
- 0 <= s <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.1 MB (beats 98.17%)  
**Submitted:** 2026-08-13T16:46:31.681Z  

```cpp
class Solution {
public:
    int largestInteger(int n, int s) {
        if(n*9<s) return -1;
        int num=0;
        while(n){
            num*=10;
            if(s<9){
                num+=s;
                s=0;
            }else{
                num+=9;
                s-=9;
            }
            n--;
        }
        return num;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/largest-integer-with-given-digit-sum/)