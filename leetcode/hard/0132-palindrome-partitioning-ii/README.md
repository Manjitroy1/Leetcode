# Palindrome Partitioning II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string `s`, partition `s` such that every substring of the partition is a palindrome.

Return  *the  **minimum**  cuts needed for a palindrome partitioning of*  `s`.

 

 **Example 1:** 

```
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

```

 **Example 2:** 

```
Input: s = "a"
Output: 0

```

 **Example 3:** 

```
Input: s = "ab"
Output: 1

```

 

 **Constraints:** 

- 1 <= s.length <= 2000
- s consists of lowercase English letters only.

## Solution

**Language:** C++  
**Runtime:** 1788 ms (beats 6.96%)  
**Memory:** 63 MB (beats 6.72%)  
**Submitted:** 2026-08-01T17:40:55.761Z  

```cpp
class Solution {
public:
    bool ispalid(int l, int r, string& s){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int recc(int start,int end, string& s,vector<vector<int>>&dp){
        if(start>=s.size()) return 0;
        if(dp[start][end]!=-1) return dp[start][end];

        int ans=INT_MAX;
        int curr=0;
        for(int k=start;k<=end;k++){
            if(ispalid(start,k,s)){
                curr= 1 + recc(k+1,end,s,dp);
            }
            ans=min(ans,curr);
        }
        return dp[start][end] = ans;
    }
    int minCut(string s) {
        int n=s.size();
        int start=0;
        int end=n-1;

        vector<vector<int>>dp(n,vector<int>(n,-1));
        return recc(start,end,s,dp)-1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/palindrome-partitioning-ii/)