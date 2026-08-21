# Contiguous Array

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a binary array `nums`, return  *the maximum length of a contiguous subarray with an equal number of* `0` *and* `1`.

 

 **Example 1:** 

```
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

```

 **Example 2:** 

```
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

```

 **Example 3:** 

```
Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- nums[i] is either 0 or 1.

## Solution

**Language:** C++  
**Runtime:** 29 ms (beats 25.62%)  
**Memory:** 88.3 MB (beats 43.16%)  
**Submitted:** 2026-08-21T17:20:12.975Z  

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int presum=0;
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) presum--;
            else presum++;

            if(mpp.count(presum)){
                ans=max(ans,i-mpp[presum]);
            }else{
                mpp[presum]=i;
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/contiguous-array/)