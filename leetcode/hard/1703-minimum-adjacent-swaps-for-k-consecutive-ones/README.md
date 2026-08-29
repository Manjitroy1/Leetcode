# Minimum Adjacent Swaps for K Consecutive Ones

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array, `nums`, and an integer `k`. `nums` comprises of only `0`'s and `1`'s. In one move, you can choose two  **adjacent**  indices and swap their values.

Return  *the  **minimum**  number of moves required so that* `nums` *has* `k` ***consecutive*** `1` *'s*.

 

 **Example 1:** 

```
Input: nums = [1,0,0,1,0,1], k = 2
Output: 1
Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 2 consecutive 1's.

```

 **Example 2:** 

```
Input: nums = [1,0,0,0,0,0,1,1], k = 3
Output: 5
Explanation: In 5 moves, the leftmost 1 can be shifted right until nums = [0,0,0,0,0,1,1,1].

```

 **Example 3:** 

```
Input: nums = [1,1,0,1], k = 2
Output: 0
Explanation: nums already has 2 consecutive 1's.

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- nums[i] is 0 or 1.
- 1 <= k <= sum(nums)

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.2 MB  
**Submitted:** 2026-08-29T10:08:20.792Z  

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            if(nums[i]) arr.push_back(i);
        }
        for(int i=0;i<arr.size();i++){
            arr[i] = arr[i]-i;
        }
        long long ans=INT_MAX;
        for(int i=0;i+k<=arr.size();i++){
            int mid= i + k/2;
            long long cost =0;
            for(int j=i;j<i+k;j++){
                cost+=abs(arr[j]-arr[mid]);
            }
            ans=min(ans,cost);
        }
        return (int)ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/)