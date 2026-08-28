# Constrained Subsequence Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an integer array `nums` and an integer `k`, return the maximum sum of a  **non-empty**  subsequence of that array such that for every two  **consecutive**  integers in the subsequence, `nums[i]` and `nums[j]`, where `i < j`, the condition `j - i <= k` is satisfied.

A  *subsequence*  of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

 

 **Example 1:** 

```
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].

```

 **Example 2:** 

```
Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.

```

 **Example 3:** 

```
Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].

```

 

 **Constraints:** 

- 1 <= k <= nums.length <= 105
- -104 <= nums[i] <= 104

## Solution

**Language:** C++  
**Runtime:** 88 ms (beats 17.76%)  
**Memory:** 143 MB (beats 39.31%)  
**Submitted:** 2026-08-28T17:09:15.959Z  

```cpp
class Solution {
public:
    int brute(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,-1e9);
        int ans=-1e9;
        for(int i=0;i<n;i++){
            int now=0;
            for(int left=max(0,i-k);left<i;left++){
                now= max(now,dp[left]);
            }
            dp[i]= nums[i] + now;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        using t= pair<int,int>; // {dp[i],i}
        priority_queue<t>pq;
        
        int ans=-1e9;
        for(int i=0;i<n;i++){
            if(!pq.empty()){
                while(!pq.empty() && pq.top().second < (i-k)){
                    pq.pop();
                }
            }
            int now=0;
            if(!pq.empty()){
                int currtop=pq.top().first;
                now= max(now,currtop);
            }
            int curr=now+nums[i];
            ans=max(ans,now+nums[i]);
            pq.push({curr,i});
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/constrained-subsequence-sum/)