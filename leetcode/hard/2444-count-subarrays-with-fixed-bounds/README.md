# Count Subarrays With Fixed Bounds

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` and two integers `minK` and `maxK`.

A  **fixed-bound subarray**  of `nums` is a subarray that satisfies the following conditions:

- The minimum value in the subarray is equal to minK.
- The maximum value in the subarray is equal to maxK.

Return  *the  **number**  of fixed-bound subarrays*.

A  **subarray**  is a  **contiguous**  part of an array.

 

 **Example 1:** 

```
Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

```

 **Example 2:** 

```
Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.

```

 

 **Constraints:** 

- 2 <= nums.length <= 105
- 1 <= nums[i], minK, maxK <= 106

## Solution

**Language:** C++  
**Runtime:** 25 ms (beats 7.68%)  
**Memory:** 95 MB (beats 7.79%)  
**Submitted:** 2026-10-18T06:09:00.637Z  

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left=0;
        long long cnt =0;
        int n= nums.size();

        deque<int>dqmn,dqmx;
        for(int i=0;i<n;i++){
            // out of regin case
            if(nums[i]<minK || nums[i]>maxK){
                left= i+1;
                dqmn.clear();
                dqmx.clear();
                continue;
            }

            //maintain monotonic queue
            while(!dqmn.empty() && nums[dqmn.back()] >= nums[i]) dqmn.pop_back();
            dqmn.push_back(i); 

            while(!dqmx.empty() && nums[dqmx.back()] <= nums[i]) dqmx.pop_back();
            dqmx.push_back(i);

            //calculate the ans

            if(!dqmn.empty() && !dqmx.empty()){
                if(nums[dqmn.front()]==minK && nums[dqmx.front()]==maxK){
                    int start = min(dqmn.front(),dqmx.front());
                    cnt+=1LL*(start-left+1);
                }
            } 
        }
        return cnt;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-subarrays-with-fixed-bounds/)