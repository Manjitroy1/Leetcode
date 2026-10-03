# Q3. Longest Subarray With Restricted Pair Sums

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums`.

A  **subarray**  `nums[l..r]` is valid if there are no three  **distinct**  indices `i`, `j`, and `k` such that `l <= i, j, k <= r` and:

- nums[i] + nums[j] == nums[k]

Return the  **maximum**  length of a valid subarray of `nums`.

A  **subarray**  is a contiguous  **non-empty**  sequence of elements within an array.

 

 **Example 1:** 

 **Input:**  nums = [2,3,5,3,2,1]

 **Output:**  3

 **Explanation:** 

Consider the subarray `[3, 5, 3]`. The pairs of elements at distinct indices have the following sums:

- 3 + 5 = 8
- 3 + 3 = 6, using the two different occurrences of 3
- 5 + 3 = 8

None of these sums is an element at the remaining index, so the subarray is valid.

Every subarray of length 4 contains 2, 3, and 5 at distinct indices, where `2 + 3 = 5`. Therefore, no longer valid subarray exists, and the answer is 3.

 **Example 2:** 

 **Input:**  nums = [3,4,5,6]

 **Output:**  4

 **Explanation:** 

The sums obtained from every pair of elements at distinct indices are 7, 8, 9, 9, 10, and 11. None of these values appears at the remaining index, so the entire array is valid.

 

 **Constraints:** 

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 500

## Solution

**Language:** C++  
**Runtime:** 247 ms (beats 32.82%)  
**Memory:** 45.2 MB (beats 22.08%)  
**Submitted:** 2026-10-03T17:49:26.609Z  

```cpp
class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int ans=0;
        unordered_map<int,int>presum;
        unordered_map<int,int>diff;
        
        while(r<n){
            int x=nums[r];
            bool invalid= ( presum[x]>0 || diff[x]>0 );

            while(l<r && invalid){
                //remove l
                int val=nums[l];
                for(int i=l+1;i<r;i++){
                    presum[val+nums[i]]--;
                    int md=abs(nums[l]-nums[i]);
                    diff[md]--;
                    
                    if(presum[val+nums[i]]==0) presum.erase(val+nums[i]);
                    if(diff[md]==0) diff.erase(md);
                }
                l++;
                
                invalid= ( presum[x]>0 || diff[x]>0 );
            }
            ans=max(ans,r-l+1);

            //insert the value in both the mp
            int val=nums[r];
            for(int i=l;i<r;i++){
                presum[val+nums[i]]++;
                int md=abs(nums[i]-nums[r]);
                diff[md]++;
            }
            
            r++;
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-subarray-with-restricted-pair-sums/)