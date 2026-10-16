# Dice Roll Simulation

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

A die simulator generates a random number from `1` to `6` for each roll. You introduced a constraint to the generator such that it cannot roll the number `i` more than `rollMax[i]` (**1-indexed**) consecutive times.

Given an array of integers `rollMax` and an integer `n`, return  *the number of distinct sequences that can be obtained with exact* `n` *rolls*. Since the answer may be too large, return it  **modulo**  `109 + 7`.

Two sequences are considered different if at least one element differs from each other.

 

 **Example 1:** 

```
Input: n = 2, rollMax = [1,1,2,2,2,3]
Output: 34
Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.

```

 **Example 2:** 

```
Input: n = 2, rollMax = [1,1,1,1,1,1]
Output: 30

```

 **Example 3:** 

```
Input: n = 3, rollMax = [1,1,1,2,2,3]
Output: 181

```

 

 **Constraints:** 

- 1 <= n <= 5000
- rollMax.length == 6
- 1 <= rollMax[i] <= 15

## Solution

**Language:** C++  
**Runtime:** 49 ms (beats 57.62%)  
**Memory:** 11.6 MB (beats 84.50%)  
**Submitted:** 2026-10-16T12:46:54.069Z  

```cpp
class Solution {
public:
    const int mod = 1e9+7;
    vector<int>rollmax;
    int dp[7][16][5001];
    int solve(int i,int cnt,int n){
        if(i>0 &&  cnt >= rollmax[i-1]) return 0; //if comes max times consecutively return 0
        if(n==0) return 1; //base case taken n times roll

        if(dp[i][cnt][n]!=-1) return dp[i][cnt][n]; 

        int ans=0;
        //try all possibility
        for(int d=1;d<=6;d++){
            if(i==d){
                ans = (ans + solve(d,cnt+1,n-1)) % mod;
            }else{
                ans= (ans + solve(d,0,n-1))% mod;
            }
        }
        return dp[i][cnt][n] = (ans) % mod;

    }
    int dieSimulator(int n, vector<int>& rollMax) {
        rollmax=rollMax;
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,n);
        return ans;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/dice-roll-simulation/)