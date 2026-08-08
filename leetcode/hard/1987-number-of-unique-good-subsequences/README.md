# Number of Unique Good Subsequences

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a binary string `binary`. A  **subsequence**  of `binary` is considered  **good**  if it is  **not empty**  and has  **no leading zeros**  (with the exception of `"0"`).

Find the number of  **unique good subsequences**  of `binary`.

- For example, if binary = "001", then all the good subsequences are ["0", "0", "1"], so the unique good subsequences are "0" and "1". Note that subsequences "00", "01", and "001" are not good because they have leading zeros.

Return  *the number of  **unique good subsequences**  of* `binary`. Since the answer may be very large, return it  **modulo**  `109 + 7`.

A  **subsequence**  is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

 **Example 1:** 

```
Input: binary = "001"
Output: 2
Explanation: The good subsequences of binary are ["0", "0", "1"].
The unique good subsequences are "0" and "1".

```

 **Example 2:** 

```
Input: binary = "11"
Output: 2
Explanation: The good subsequences of binary are ["1", "1", "11"].
The unique good subsequences are "1" and "11".
```

 **Example 3:** 

```
Input: binary = "101"
Output: 5
Explanation: The good subsequences of binary are ["1", "0", "1", "10", "11", "101"]. 
The unique good subsequences are "0", "1", "10", "11", and "101".

```

 

 **Constraints:** 

- 1 <= binary.length <= 105
- binary consists of only '0's and '1's.

## Solution

**Language:** C++  
**Runtime:** 12 ms (beats 20.96%)  
**Memory:** 15.2 MB (beats 42.61%)  
**Submitted:** 2026-08-08T10:48:53.042Z  

```cpp
class Solution {
public:
    const int mod=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        bool zero=false;
        int n=binary.size();
        int end0=0;
        int end1=0;
        for(int i=0;i<n;i++){
            if(binary[i]=='0'){
                zero=true;
                end0 = (end0+end1)%mod;
            }else{
                end1 = (end0 + end1 + 1)% mod;
            }

        }
        int ans = (end0+end1)%mod;
        return zero? ans+1 : ans;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-unique-good-subsequences/)