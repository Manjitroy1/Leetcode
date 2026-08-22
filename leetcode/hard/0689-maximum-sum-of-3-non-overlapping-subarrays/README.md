# Maximum Sum of 3 Non-Overlapping Subarrays

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an integer array `nums` and an integer `k`, find three non-overlapping subarrays of length `k` with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (**0-indexed**). If there are multiple answers, return the lexicographically smallest one.

 

 **Example 1:** 

```
Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

```

 **Example 2:** 

```
Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]

```

 

 **Constraints:** 

- 1 <= nums.length <= 2 * 104
- 1 <= nums[i] < 216
- 1 <= k <= floor(nums.length / 3)

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 75.09%)  
**Memory:** 27.1 MB (beats 54.02%)  
**Submitted:** 2026-08-22T09:57:06.784Z  

```cpp
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ksum;
        

        int sum = accumulate(nums.begin(),nums.begin()+k,0);
        ksum.push_back(sum);
        int l=0;
        int r=k;
        while(r<n){
            sum-=nums[l];
            sum+=nums[r];
            l++;
            r++;
            ksum.push_back(sum);
        }  
        int ks=ksum.size();
        vector<int>left(ks,0);
        vector<int>right(ks,0);

        int best=0;
        for(int i=0;i<ks;i++){
            if(ksum[i]>ksum[best]){
                best=i;
            }
            left[i] = best;
        }     

        best=ks-1;
        for(int i=ks-1;i>=0;i--){
            if(ksum[i]>=ksum[best]){
                best=i;
            }
            right[i]=best;
        } 

        vector<int>result(3,0);
        int mxsum=0;

        for(int i=k;i<ks-k;i++){
            int leftidx= left[i-k];
            int rightidx= right[i+k];
            int total= ksum[leftidx] + ksum[i] + ksum[rightidx];
            if(total>mxsum){
                mxsum=total;
                result={leftidx,i,rightidx};
            }
        }

        return result;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/)