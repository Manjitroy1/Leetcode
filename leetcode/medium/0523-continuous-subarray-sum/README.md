# Continuous Subarray Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array nums and an integer k, return `true`  *if* `nums` *has a  **good subarray**  or* `false` *otherwise*.

A  **good subarray**  is a subarray where:

- its length is at least two, and
- the sum of the elements of the subarray is a multiple of k.

 **Note**  that:

- A subarray is a contiguous part of the array.
- An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

 

 **Example 1:** 

```
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

```

 **Example 2:** 

```
Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

```

 **Example 3:** 

```
Input: nums = [23,2,6,4,7], k = 13
Output: false

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 109
- 0 <= sum(nums[i]) <= 231 - 1
- 1 <= k <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 79 ms (beats 50.95%)  
**Memory:** 146.4 MB (beats 26.17%)  
**Submitted:** 2026-08-21T14:12:59.127Z  

```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        //store the index of remainder that comes earliest
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;

            if(mpp.count(rem)){
                if(i-mpp[rem] >=2) return true;
            }
            else{
                mpp[rem]=i;
            }
        }
        
        return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/continuous-subarray-sum/)