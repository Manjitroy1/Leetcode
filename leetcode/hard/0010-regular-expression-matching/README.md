# Regular Expression Matching

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:

- '.' Matches any single character.​​​​
- '*' Matches zero or more of the preceding element.

Return a boolean indicating whether the matching covers the entire input string (not partial).

 

 **Example 1:** 

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

```

 **Example 2:** 

```
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

```

 **Example 3:** 

```
Input: s = "ab", p = ".*"
Output: true
Explanation: ". *" means "zero or more (*) of any character (.)".

```

 

 **Constraints:** 

- 1 <= s.length <= 20
- 1 <= p.length <= 20
- s contains only lowercase English letters.
- p contains only lowercase English letters, '.', and '*'.
- It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.6 MB (beats 23.93%)  
**Submitted:** 2026-08-06T18:10:12.270Z  

```cpp
class Solution {
public:
    bool recc(int i,int j,string& s,string& p,vector<vector<int>>&dp){
        if(j>=p.size()) return i>=s.size();

        if(dp[i][j]!=-1) return dp[i][j];

        bool firstmatch = (i<s.size() && (s[i]==p[j] || p[j]=='.'));

        if(j+1 < p.size() && p[j+1]=='*'){
            //match zero
            return dp[i][j]= (recc(i,j+2,s,p,dp) || (firstmatch && recc(i+1,j,s,p,dp)));
            //match one or more
        }
        return dp[i][j]= (firstmatch && recc(i+1,j+1,s,p,dp));
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+2,vector<int>(m+2,-1));
        return recc(0,0,s,p,dp);
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/regular-expression-matching/)