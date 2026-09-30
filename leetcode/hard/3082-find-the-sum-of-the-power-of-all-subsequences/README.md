# Find the Sum of the Power of All Subsequences

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` of length `n` and a  **positive**  integer `k`.

The  **power**  of an array of integers is defined as the number of subsequences with their sum  **equal**  to `k`.

Return  *the  **sum**  of  **power**  of all subsequences of*  `nums` *.* 

Since the answer may be very large, return it  **modulo**  `109 + 7`.

 

 **Example 1:** 

 **Input:**  nums = [1,2,3], k = 3

 **Output:**  6

 **Explanation:** 

There are `5` subsequences of nums with non-zero power:

- The subsequence [1,2,3] has 2 subsequences with sum == 3: [1,2,3] and [1,2,3].
- The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
- The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
- The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
- The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].

Hence the answer is `2 + 1 + 1 + 1 + 1 = 6`.

 **Example 2:** 

 **Input:**  nums = [2,3,3], k = 5

 **Output:**  4

 **Explanation:** 

There are `3` subsequences of nums with non-zero power:

- The subsequence [2,3,3] has 2 subsequences with sum == 5: [2,3,3] and [2,3,3].
- The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].
- The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].

Hence the answer is `2 + 1 + 1 = 4`.

 **Example 3:** 

 **Input:**  nums = [1,2,3], k = 7

 **Output:**  0

 **Explanation:** There exists no subsequence with sum `7`. Hence all subsequences of nums have `power = 0`.

 

 **Constraints:** 

- 1 <= n <= 100
- 1 <= nums[i] <= 104
- 1 <= k <= 100

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 88.80%)  
**Memory:** 23 MB (beats 78.40%)  
**Submitted:** 2026-09-30T11:54:39.607Z  

```cpp
class Solution {
public:
    const long long mod = 1e9 + 7;

   

    int tabu(vector<int>& nums, int K) {
        int n=nums.size();
        vector<long long>dp(K+1,0);
        dp[0]=1;
        //we are creating B whose sum =k
        //whether to take x or not take x
        //take x, then one possiblity 
        //not take x , x is in A or x is not in A
        for(int& x:nums){
            for(int k=K;k>=0;k--){
                dp[k]=(2*dp[k])%mod; //not take x;
                if(k-x>=0) dp[k]=(dp[k]+dp[k-x])%mod;
            }
        }
        return (int)dp[K];
    }
    int sumOfPower(vector<int>& nums, int K) {
        int n=nums.size();
        return tabu(nums,K);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-the-sum-of-the-power-of-all-subsequences/)