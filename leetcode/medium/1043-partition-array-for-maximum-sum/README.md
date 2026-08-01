# Partition Array for Maximum Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `arr`, partition the array into (contiguous) subarrays of length  **at most**  `k`. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return  *the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a  **32-bit**  integer.* 

 

 **Example 1:** 

```
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

```

 **Example 2:** 

```
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

```

 **Example 3:** 

```
Input: arr = [1], k = 1
Output: 1

```

 

 **Constraints:** 

- 1 <= arr.length <= 500
- 0 <= arr[i] <= 109
- 1 <= k <= arr.length

## Solution

**Language:** C++  
**Runtime:** 21 ms (beats 10.30%)  
**Memory:** 38 MB (beats 5.08%)  
**Submitted:** 2026-08-01T18:16:45.080Z  

```cpp
class Solution {
public:
    int recc(int start, int end, vector<int>&arr, int k,vector<vector<int>>&dp){
        if(start>= arr.size()) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int n=arr.size();
        int ans=0;
        int mx=arr[start];
        for(int c=start;c < min(n, start+k); c++){
            mx= max(mx,arr[c]);
            int len = c-start+1;

            ans = max(ans, mx*len + recc(c+1,end,arr,k,dp));

        }
        return dp[start][end] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int start=0;
        int end =arr.size()-1;
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return recc(start,end,arr,k,dp);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/partition-array-for-maximum-sum/)