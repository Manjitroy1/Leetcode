# K Inverse Pairs Array

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

For an integer array `nums`, an  **inverse pair**  is a pair of integers `[i, j]` where `0 <= i < j < nums.length` and `nums[i] > nums[j]`.

Given two integers n and k, return the number of different arrays consisting of numbers from `1` to `n` such that there are exactly `k`  **inverse pairs**. Since the answer can be huge, return it  **modulo**  `109 + 7`.

 

 **Example 1:** 

```
Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.

```

 **Example 2:** 

```
Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.

```

 

 **Constraints:** 

- 1 <= n <= 1000
- 0 <= k <= 1000

## Solution

**Language:** C++  
**Runtime:** 2782 ms (beats 5.10%)  
**Memory:** 25 MB (beats 35.34%)  
**Submitted:** 2026-08-19T18:15:01.643Z  

```cpp
class Solution {
public:
    const int mod =1e9+7;
    int kInversePairs(int n, int k) {
        if(k==0) return 1;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));

        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }

        for(int nn=2;nn<=n;nn++){
            for(int kk=0;kk<=k;kk++){
                
                int ans=0;
                for(int l=0;l<nn;l++){
                    if(kk-l>=0){
                        ans = (ans + dp[nn-1][kk-l]) % mod;
                    }
                }

                dp[nn][kk] = ans;
            }
        }
        return dp[n][k];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/k-inverse-pairs-array/)