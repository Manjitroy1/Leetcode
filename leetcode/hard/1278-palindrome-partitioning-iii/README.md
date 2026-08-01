# Palindrome Partitioning III

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `s` containing lowercase letters and an integer `k`. You need to :

- First, change some characters of s to other lowercase English letters.
- Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.

Return  *the minimal number of characters that you need to change to divide the string*.

 

 **Example 1:** 

```
Input: s = "abc", k = 2
Output: 1
Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.

```

 **Example 2:** 

```
Input: s = "aabbc", k = 3
Output: 0
Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.
```

 **Example 3:** 

```
Input: s = "leetcode", k = 8
Output: 0

```

 

 **Constraints:** 

- 1 <= k <= s.length <= 100.
- s only contains lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.4 MB  
**Submitted:** 2026-08-01T18:59:10.682Z  

```cpp
class Solution {
public:
    int dp[101][101];
    int recc(int start, string& s, int k,vector<vector<int>>&palind){
        int n=s.size();

        if (start == n)
            return (k == 0) ? 0 : 1e9;

        if (k == 0)
            return 1e9;

        if (k > n - start)
            return 1e9;

        if(dp[start][k]!=-1) return dp[start][k];

        int ans=INT_MAX;
        for(int c=start;c<=n-k;c++){
            ans = min(ans, palind[start][c] + recc(c+1,s,k-1,palind) );
        }
        return dp[start][k] = ans;
    }
    int palindromePartition(string s, int k) {

        int n=s.size();
        vector<vector<int>>palind(n,vector<int>(n));  //count of char req to make it palind if 0 then it is a p
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(j-i<=1){
                    palind[i][j] = s[i]==s[j] ? 0:1;
                }
                else{
                    palind[i][j] = palind[i+1][j-1];
                    if(s[i]!=s[j]){
                        palind[i][j]+=1;
                    }
                }
            }
        }
        int start=0;
        memset(dp,-1,sizeof(dp));
        return recc(start,s,k,palind);


    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/palindrome-partitioning-iii/)