# Count Palindromic Subsequences

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string  **s**, you have to find the number of palindromic subsequences (need not necessarily be distinct) present in the string s. 

 **Examples:** 

```
Input: s = "abcd"
Output: 4
Explanation: palindromic subsequence are : 'a','b', 'c','d'
```

```
Input: s = "aab"
Output: 4
Explanation: palindromic subsequence are : 'a', 'a', 'b', 'aa'

```

```
Input: s = "b"
Output: 1
Explanation: palindromic subsequence are : 'b'
```

 **Constraints:** 
1<= s.size() <=30

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-23T09:36:29.886Z  

```cpp
class Solution {
  public:
    /*You are required to complete below method */
    int countPS(string &s) {
        // Your code here
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){//i is the start and j is the end
                if(s[i]==s[j]){
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
                }
                else{
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                }
            }
        }
        return dp[0][n-1];
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1)