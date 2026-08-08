# Minimum Number of Operations to Make Array Continuous

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums`. In one operation, you can replace  **any**  element in `nums` with  **any**  integer.

`nums` is considered  **continuous**  if both of the following conditions are fulfilled:

- All elements in nums are unique.
- The difference between the maximum element and the minimum element in nums equals nums.length - 1.

For example, `nums = [4, 2, 5, 3]` is  **continuous**, but `nums = [1, 2, 3, 5, 6]` is  **not continuous**.

Return  *the  **minimum**  number of operations to make* `nums`  ***continuous** *.

 

 **Example 1:** 

```
Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.

```

 **Example 2:** 

```
Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.

```

 **Example 3:** 

```
Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 58 ms (beats 46.86%)  
**Memory:** 73.4 MB (beats 50.31%)  
**Submitted:** 2026-08-08T13:37:23.307Z  

```cpp
class Solution {
public:
    int solve(vector<int>& nums) {
        int n=nums.size();
        int len=n-1;
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        //this can be the start point
        int l=nums[0];
        int h=nums[n-1];
        int ans=n;

        for(int start=l;start<=h;start++){
            int below= upper_bound(nums.begin(),nums.end(),start)-nums.begin();
            int above= upper_bound(nums.begin(),nums.end(),start+len)-nums.begin();
            if(nums[below-1]!=start){
                below++;
            }
            int right=n-above;
            ans=min(ans,below+right);
        }
        return ans-1;
    }
    int solveopt(vector<int>&nums){
        int n=nums.size();
        sort(nums.begin(),nums.end());

        //arr is sorted an unique elements
        vector<int>arr;
        for(int i=0;i<n;i++){
            if(!arr.empty() && arr.back()==nums[i]) continue;
            arr.push_back(nums[i]);
        }
        int m=arr.size();
        int ans=n;
        for(int i=0;i<m;i++){
            int end= arr[i]+n-1;
            int j= upper_bound(arr.begin(),arr.end(),end)- arr.begin();
            int inside= j-i;
            ans= min(ans,n-inside);
        }
        return ans;
    }
    int minOperations(vector<int>& nums) {
        // return solve(nums);
        return solveopt(nums);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/)