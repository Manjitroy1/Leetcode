# Q4. Count Good Strings

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer `n`.

A string is considered  **good**  if it consists only of the characters `'a'` and `'b'`, and one of the following holds:

- It contains exactly one distinct character, and its length is odd.
- It can be written as s = s1 + s2, where s1 and s2 are non-empty good strings, and the last character of s1 is different from the first character of s2.

Return the number of  **good**  strings of length `n`, modulo `109 + 7`.

Here, `+` denotes string concatenation.

 

 **Example 1:** 

 **Input:**  n = 4

 **Output:**  6

 **Explanation:** 

- The good strings are "aaab", "abbb", "baaa", "bbba", "abab", and "baba".
- For example, "aaab" = "aaa" + "b". Both parts are good because each contains one distinct character and has odd length, and their characters at the boundary are different.
- Also, "ab" = "a" + "b" is good, so "abab" = "ab" + "ab" is good because the boundary characters are different.
- Thus, the answer is 6.

 **Example 2:** 

 **Input:**  n = 3

 **Output:**  4

 **Explanation:** 

The good strings are `"aaa"`, `"bbb"`, `"aba"`, and `"bab"`. Thus, the answer is 4.

 **Example 3:** 

 **Input:**  n = 2

 **Output:**  2

 **Explanation:** 

The good strings are `"ab"` and `"ba"`. Thus, the answer is 2.

 

 **Constraints:** 

- 1 <= n <= 1015

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8 MB  
**Submitted:** 2026-10-14T10:33:16.297Z  

```cpp
class Solution {
public:
    const long long mod = 1e9+7;
    int countGoodStrings(long long n) {

        long long pprev=0;
        long long prev=1;
        for(long long i=2;i<=n;i++){
           long long curr = ((prev+ pprev))%mod;
            pprev=prev;
            prev=curr;
        }
        return (2*prev)%mod;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-good-strings/)