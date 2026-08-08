# Wildcard Matching

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'` where:

- '?' Matches any single character.
- '*' Matches any sequence of characters (including the empty sequence).

The matching should cover the  **entire**  input string (not partial).

 

 **Example 1:** 

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

```

 **Example 2:** 

```
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

```

 **Example 3:** 

```
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

```

 

 **Constraints:** 

- 0 <= s.length, p.length <= 2000
- s contains only lowercase English letters.
- p contains only lowercase English letters, '?' or '*'.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8 MB  
**Submitted:** 2026-08-08T06:40:03.360Z  

```cpp
class Solution {
public:
    bool solve(int i,int j, string& s, string& p, vector<vector<int>>&dp){
        if(j<0) return i<0;  // p gets over return s is over or not
        // if(i<0) return j<0;  // s is over case 1 p is not over case 2 p over
        if(i<0){
            if(j<0) return true;
            else{
                while(j>=0){
                    if(p[j]!='*') return false;
                    j--;
                }
                return true;
            }
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]= solve(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*'){
            return dp[i][j]= (solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp));
        } 
        return dp[i][j]= false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,s,p,dp);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/wildcard-matching/)