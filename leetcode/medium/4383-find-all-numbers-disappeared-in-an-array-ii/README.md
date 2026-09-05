# Q2. Find All Numbers Disappeared in an Array II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` and two integers `lower` and `upper`.

A  **missing integer**  is an integer in the inclusive range `[lower, upper]` that does not appear in `nums`.

Return a 2D integer array where each element is of the form `[start, end]`, representing a  **contiguous**  range of missing integers. Return the ranges in  **increasing**  order. If there are no missing integers, return an empty array.

 **Note:**  Consecutive missing integers should be grouped into a single range.

 

 **Example 1:** 

 **Input:**  nums = [3,9,7], lower = 1, upper = 12

 **Output:**  [[1,2],[4,6],[8,8],[10,12]]

 **Explanation:** 

- The missing integers are [1, 2, 4, 5, 6, 8, 10, 11, 12].
- Grouping the missing integers into the minimum number of contiguous ranges, we get [1, 2], [4, 6], [8, 8], and [10, 12].
- Therefore, the answer is [[1, 2], [4, 6], [8, 8], [10, 12]].

 **Example 2:** 

 **Input:**  nums = [1,1], lower = 5, upper = 7

 **Output:**  [[5,7]]

 **Explanation:** 

- The missing integers are [5, 6, 7].
- Grouping the missing integers into the minimum number of contiguous ranges, we get [5, 7].
- Therefore, the answer is [[5, 7]].

 **Example 3:** 

 **Input:**  nums = [2,3,5], lower = 2, upper = 3

 **Output:**  []

 **Explanation:** 

- There are no missing integers.
- Therefore, the answer is [].

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105
- 1 <= lower <= upper <= 105

## Solution

**Language:** C++  
**Runtime:** 59 ms (beats 93.26%)  
**Memory:** 259.5 MB (beats 40.59%)  
**Submitted:** 2026-09-05T12:54:53.531Z  

```cpp
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        // if(upper<nums[0] || lowe>nums[n-1]) return {{lower,upper}};
        int sz=upper-lower+1;
        vector<int>temp(sz);
        
        for(int i=0;i<sz;i++){
            temp[i]=lower+i;
        }
        for(int i=0;i<n;i++){
            if(lower<=nums[i] && nums[i]<=upper){
                int idx= nums[i]-lower;
                temp[idx]=0;
            }
        }
        int first=-1;
        int second=-1;
        for(int i=0;i<sz;i++){
            if(temp[i]!=0 && first==-1) first=temp[i];
            if(first!=-1 && temp[i]==0 && second==-1) ans.push_back({first});
            
            if(temp[i]!=0 && first!=-1) second=temp[i];
            if(first!=-1 && second!=-1 && temp[i]==0){
                ans.push_back({first,second});
                first=-1;
                second=-1;
            }
        }
        if(first!=-1 && second!=-1) ans.push_back({first,second});

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-ii/)