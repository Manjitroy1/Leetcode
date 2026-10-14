# Q1. Three Fibonacci Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer `n`.

The  **Fibonacci sequence**  starts with 0 and 1, and each subsequent number is the sum of the previous two numbers. Its first few terms are `0, 1, 1, 2, 3, 5, 8, 13,...`.

Return `true` if `n` can be expressed as the sum of  **three consecutive terms**  in the Fibonacci sequence, and `false` otherwise.

 

 **Example 1:** 

 **Input:**  n = 16

 **Output:**  true

 **Explanation:** 

The three consecutive terms 3, 5, and 8 have a sum of `3 + 5 + 8 = 16`.

 **Example 2:** 

 **Input:**  n = 8

 **Output:**  false

 **Explanation:** 

Although `1 + 2 + 5 = 8`, these terms are not consecutive in the Fibonacci sequence. No three consecutive terms have a sum of 8.

 **Example 3:** 

 **Input:**  n = 2

 **Output:**  true

 **Explanation:** 

The first three terms have a sum of `0 + 1 + 1 = 2`.

 

 **Constraints:** 

- 1 <= n <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 7.7 MB (beats 99.34%)  
**Submitted:** 2026-10-14T13:52:11.276Z  

```cpp
class Solution {
public:
    bool perfect(long long x){
        long long r = sqrt(x);

        return r*r == x;
    }
    bool solve(long long x){
        // i have to check if 5x^2 +-4 is perfect or not
        if(x<0) return false;
        long long val = 5LL * x* x;
        return perfect(val+4) || perfect(val-4);
    }
    bool threeFibonacciSum(int n) {
        if(n%2) return false;
        //if n/2 is a fibo num then it is true
        return solve(n/2);
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/three-fibonacci-sum/)