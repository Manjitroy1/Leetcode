# Minimum Number of Removals to Make Mountain Array

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You may recall that an array `arr` is a  **mountain array**  if and only if:

- arr.length >= 3
- There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that: arr[0] < arr[1] <... < arr[i - 1] < arr[i] arr[i] > arr[i + 1] >... > arr[arr.length - 1]

Given an integer array `nums`​​​, return  *the  **minimum**  number of elements to remove to make* `nums​​​`  *a  **mountain array**.* 

 

 **Example 1:** 

```
Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.

```

 **Example 2:** 

```
Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].

```

 

 **Constraints:** 

- 3 <= nums.length <= 1000
- 1 <= nums[i] <= 109
- It is guaranteed that you can make a mountain array out of nums.

## Solution

**Language:** C++  
**Runtime:** 62 ms (beats 55.69%)  
**Memory:** 16.2 MB (beats 52.14%)  
**Submitted:** 2026-08-25T15:03:24.443Z  

```cpp
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>prev(n,0);
        vector<int>next(n,0);

        prev[0]=1;
        next[n-1]=1;

        for(int i=1;i<n;i++){
            int mx=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    mx= max(mx,prev[j]);
                }
            }
            prev[i]=1+mx;
        }

        for(int i=n-2;i>=0;i--){
            int mx=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[i]){
                    mx=max(mx,next[j]);
                }
            }
            next[i]=1+mx;
        }
        int ans=0;
        int i=1;
        while(i<n && nums[i-1]>=nums[i]){
            i++;
        }
        int j=n-2;
        while(j>0 && nums[j+1]>=nums[j]){
            j--;
        }

        if(j<i) return n-1;

        for(int k=i;k<=j;k++){
            ans=max(ans,prev[k]+next[k]);
        }
        return n-ans+1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/)