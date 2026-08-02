# Maximize Score After N Operations

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given `nums`, an array of positive integers of size `2 * n`. You must perform `n` operations on this array.

In the `ith` operation  **(1-indexed)**, you will:

- Choose two elements, x and y.
- Receive a score of i * gcd(x, y).
- Remove x and y from nums.

Return  *the maximum score you can receive after performing* `n` *operations.* 

The function `gcd(x, y)` is the greatest common divisor of `x` and `y`.

 

 **Example 1:** 

```
Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1

```

 **Example 2:** 

```
Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1  *gcd(3, 6)) + (2*  gcd(4, 8)) = 3 + 8 = 11

```

 **Example 3:** 

```
Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1  *gcd(1, 5)) + (2*  gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14

```

 

 **Constraints:** 

- 1 <= n <= 7
- nums.length == 2 * n
- 1 <= nums[i] <= 106

## Solution

**Language:** C++  
**Runtime:** 43 ms (beats 91.63%)  
**Memory:** 16.6 MB (beats 51.07%)  
**Submitted:** 2026-08-02T18:27:03.505Z  

```cpp
class Solution {
public:
    int func(vector<int>& nums, int op, int mask, vector<int>& dp, vector<vector<int>>& gcd){
        int m = nums.size(), n = nums.size()/2;
        if(op > n) return 0;
        if(dp[mask] != -1) return dp[mask];

        for(int i=0;i<m;i++){
            if( (mask & (1<<i)) ) continue;
            for(int j=i+1;j<m;j++){
                if( (mask & (1<<j)) ) continue;
                
                int newMask = (1<<i) | (1<<j) | mask;
                int score = op * gcd[i][j] + func(nums, op+1, newMask, dp, gcd);
                dp[mask] = max(dp[mask], score);
            }
        }
        return dp[mask];
    }

    int maxScore(vector<int>& nums) {
        vector<int> dp(1<<14, -1);

        int m = nums.size(), n = nums.size()/2;
        vector<vector<int>> gcd(m, vector<int>(m, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                gcd[i][j] = __gcd(nums[i], nums[j]);
            }
        }

        return func(nums, 1, 0, dp, gcd);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximize-score-after-n-operations/)