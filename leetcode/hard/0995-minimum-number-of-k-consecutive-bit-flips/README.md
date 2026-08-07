# Minimum Number of K Consecutive Bit Flips

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a binary array `nums` and an integer `k`.

A  **k-bit flip**  is choosing a  **subarray**  of length `k` from `nums` and simultaneously changing every `0` in the subarray to `1`, and every `1` in the subarray to `0`.

Return  *the minimum number of  **k-bit flips**  required so that there is no* `0` *in the array*. If it is not possible, return `-1`.

A  **subarray**  is a  **contiguous**  part of an array.

 

 **Example 1:** 

```
Input: nums = [0,1,0], k = 1
Output: 2
Explanation: Flip nums[0], then flip nums[2].

```

 **Example 2:** 

```
Input: nums = [1,1,0], k = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we cannot make the array become [1,1,1].

```

 **Example 3:** 

```
Input: nums = [0,0,0,1,0,1,1,0], k = 3
Output: 3
Explanation: 
Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= k <= nums.length

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 110.3 MB (beats 87.58%)  
**Submitted:** 2026-08-07T08:21:21.953Z  

```cpp
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool>flip(n,false);
        int flipcount=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i>=k && flip[i-k]){
                flipcount--;
            }

            if(flipcount%2==nums[i]){
                if(i+k>n) return -1;
                //we have to flip
                flip[i]=true;
                flipcount++;
                ans++;
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/)