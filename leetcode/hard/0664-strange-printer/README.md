# Strange Printer

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

There is a strange printer with the following two special properties:

- The printer can only print a sequence of the same character each time.
- At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.

Given a string `s`, return  *the minimum number of turns the printer needed to print it*.

 

 **Example 1:** 

```
Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

```

 **Example 2:** 

```
Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

```

 

 **Constraints:** 

- 1 <= s.length <= 100
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 18 ms (beats 51.82%)  
**Memory:** 12.4 MB (beats 37.95%)  
**Submitted:** 2026-08-01T17:14:51.528Z  

```cpp
class Solution {
public:
    int recc(int start, int end, string& s,vector<vector<int>>&dp){
        if(start>end) return 0;
        if(dp[start][end]<1e7) return dp[start][end];

        dp[start][end] = 1 + recc(start+1,end,s,dp);

        for(int k=start+1;k<=end;k++){
            if(s[start]==s[k]){
                dp[start][end] = min(dp[start][end], recc(start,k-1,s,dp) + recc(k+1,end,s,dp));
            }
        }
        return dp[start][end];
    }
    int strangePrinter(string s) {
        int n=s.size();
        int end= n-1;
        int start=0;
        vector<vector<int>>dp(n,vector<int>(n,1e7));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        return recc(start,end,s,dp);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/strange-printer/)