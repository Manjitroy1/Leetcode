# Distinct Subsequences II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string s, return  *the number of  **distinct non-empty subsequences**  of*  `s`. Since the answer may be very large, return it  **modulo**  `109 + 7`.

A  **subsequence**  of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not.

 

 **Example 1:** 

```
Input: s = "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

```

 **Example 2:** 

```
Input: s = "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".

```

 **Example 3:** 

```
Input: s = "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".

```

 

 **Constraints:** 

- 1 <= s.length <= 2000
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 49.08%)  
**Memory:** 8.7 MB (beats 90.96%)  
**Submitted:** 2026-09-07T09:30:14.232Z  

```cpp
class Solution {
public:
    const int mod= 1e9+7;
    int better(string s) {
        int n=s.size();
        vector<int>dp(n,1);
        int total =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(s[i]!=s[j]){
                    dp[i]= (dp[i] + dp[j]) % mod;
                }
            }
            total=(total + (dp[i])) % mod;
        }
        return total;
    }
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int>dp(26,0);
        int total =0;
        
        // dp[char]= number of disticnt subsequences ending with this char

        for(int i=0;i<n;i++){
            int c= s[i]-'a';
            int add= (total-dp[c]+ mod) %mod; //number of new distinct subseqeunces by subtracting that can cause duplicates
            dp[c]= (1+total)%mod; //total number of disticnt subsqquences ending with char c so far
            total = (total + 1 + add)%mod; // adding new subsequences to the previous total
        }
        
        return total;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/distinct-subsequences-ii/)