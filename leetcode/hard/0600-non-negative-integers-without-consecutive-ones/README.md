# Non-negative Integers without Consecutive Ones

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a positive integer `n`, return the number of the integers in the range `[0, n]` whose binary representations  **do not**  contain consecutive ones.

 

 **Example 1:** 

```
Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 

```

 **Example 2:** 

```
Input: n = 1
Output: 2

```

 **Example 3:** 

```
Input: n = 2
Output: 3

```

 

 **Constraints:** 

- 1 <= n <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.7 MB (beats 33.80%)  
**Submitted:** 2026-08-18T14:29:58.276Z  

```cpp
class Solution {
public:
    int dp[32][2][2];
    int unique(int pos,int prevone,int tight,vector<int>&bits){
        if(pos==bits.size()) return 1;

        if(dp[pos][prevone][tight]!=-1) return dp[pos][prevone][tight];

        int res=0;
        int limit = tight? bits[pos] : 1;

        for(int b=0;b<=limit;b++){
            if(b==1 && prevone) continue;
            int newprevone = (b==1);
            int newtight = tight && bits[pos]==b;

            res+=unique(pos+1,newprevone,newtight,bits);
        }
        return dp[pos][prevone][tight]=res;
    }
    
    int findIntegers(int n) {
        vector<int>bits;
        for(int i=30;i>=0;i--){
            bits.push_back((n>>i) & 1);
        }
        memset(dp,-1,sizeof(dp));
        return unique(0,0,1,bits);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)