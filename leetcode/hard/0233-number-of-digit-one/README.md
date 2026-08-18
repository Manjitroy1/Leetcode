# Number of Digit One

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an integer `n`, count  *the total number of digit* `1` *appearing in all non-negative integers less than or equal to*  `n`.

 

 **Example 1:** 

```
Input: n = 13
Output: 6

```

 **Example 2:** 

```
Input: n = 0
Output: 0

```

 

 **Constraints:** 

- 0 <= n <= 109

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 4.58%)  
**Memory:** 8.1 MB (beats 18.13%)  
**Submitted:** 2026-08-18T11:49:30.614Z  

```cpp
class Solution {
public:
    int dp[20][20][2];
    int countone(int pos,int cnt,int tight,vector<int>&digits){
        if(pos==digits.size()) return cnt;

        if(dp[pos][cnt][tight]!=-1) return dp[pos][cnt][tight];
        int limit = tight? digits[pos] : 9;
        int res=0;

        for(int dig=0;dig<=limit;dig++){
            int newcount=cnt;

            if(dig==1){
                newcount++;
            }
            int newtight = tight && (digits[pos]==dig);
            res+=countone(pos+1,newcount,newtight,digits);
        }
        return dp[pos][cnt][tight]=res;
    }
    int solve(int n,vector<int>&digits){
        if(n<=0) return 0;

        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        reverse(digits.begin(),digits.end());
        return countone(0,0,1,digits);  //pos cnt tight

    }
    int countDigitOne(int n) {
        vector<int>digits;
        memset(dp,-1,sizeof(dp));
        return solve(n,digits);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-digit-one/)