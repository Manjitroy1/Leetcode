# Q1. Count Valid Prefixes

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given a binary string `s`.

A prefix of `s` is considered  **valid**  if its characters can be rearranged to form an  **alternating**  string.

Return the number of valid prefixes of `s`.

A string is considered  **alternating**  if no two adjacent characters are equal.

 

 **Example 1:** 

 **Input:**  s = "00101"

 **Output:**  3

 **Explanation:** 

The valid prefixes are:

- "0": It is already an alternating string.
- "001": It can be rearranged into "010", which is an alternating string.
- "00101": It can be rearranged into "01010", which is an alternating string.

Thus, the answer is 3.

 **Example 2:** 

 **Input:**  s = "101"

 **Output:**  3

 **Explanation:** 

All prefixes of `s = "101"` are already alternating strings. Thus, the answer is 3.

 

 **Constraints:** 

- 1 <= s.length <= 100
- s consists only of '0' and '1'.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.5 MB (beats 22.41%)  
**Submitted:** 2026-08-13T08:28:13.848Z  

```cpp
class Solution {
public:
    int countValidPrefixes(string s) {
        int n=s.size();
        int count=0;
        int zero=0;
        int one =0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero++;
            }else{
                one++;
            }
            if( abs(zero-one)<=1) count++;
        }
        return count;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-valid-prefixes/)