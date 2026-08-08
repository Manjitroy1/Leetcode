# Maximum Sum of Two Non-Overlapping Subarrays

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums` and two integers `firstLen` and `secondLen`, return  *the maximum sum of elements in two non-overlapping  **subarrays**  with lengths* `firstLen` *and* `secondLen`.

The array with length `firstLen` could occur before or after the array with length `secondLen`, but they have to be non-overlapping.

A  **subarray**  is a  **contiguous**  part of an array.

 

 **Example 1:** 

```
Input: nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.

```

 **Example 2:** 

```
Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.

```

 **Example 3:** 

```
Input: nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [0,3,8] with length 3.

```

 

 **Constraints:** 

- 1 <= firstLen, secondLen <= 1000
- 2 <= firstLen + secondLen <= 1000
- firstLen + secondLen <= nums.length <= 1000
- 0 <= nums[i] <= 1000

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.2 MB (beats 71.06%)  
**Submitted:** 2026-08-08T14:59:35.747Z  

```cpp
class Solution {
public:
    int func(int first,int second,vector<int>&presum){
        int n=presum.size();
        // first of L window
        int ans=0;
        int bestfirst=0;
        for(int i=first-1;i<n-second;i++){
            int fmx= presum[i] - (i-first>=0 ? presum[i-first] : 0 );
            int smx= presum[i+second] - presum[i]; 

            bestfirst=max(bestfirst,fmx);
            ans= max(ans, bestfirst+smx);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        if(nums.size() == firstLen + secondLen){
            return accumulate(nums.begin(),nums.end(),0);
        }
        int n=nums.size();

        vector<int>presum(n);
        presum[0]=nums[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1] + nums[i];
        }
        int f =func(firstLen,secondLen,presum);  //first second
        int s =func(secondLen,firstLen,presum);
        return max(f,s);

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/)