# Q4. Lexicographically Largest Power Array

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` of length `n`. You may rearrange its elements to form any permutation `perm`.

Define an array `power` of length 15. For each `0 <= i < 15`, `power[i]` is the largest integer `j`, where `0 <= j <= n`, such that the first `j` elements of `perm` all have the `(14 - i)th` bit set.

Bit positions are indexed from right to left, starting with the `0th` bit.

Return the lexicographically largest possible `power` array.

 

 **Example 1:** 

 **Input:**  nums = [7,5]

 **Output:**  [0,0,0,0,0,0,0,0,0,0,0,0,2,1,2]

 **Explanation:** 

Choose `perm = [7, 5]`.

- Both elements have bit 2 set, so power[12] = 2.
- The first element has bit 1 set, but the second does not, so power[13] = 1.
- Both elements have bit 0 set, so power[14] = 2.

All higher bits are unset in the first element, so the remaining entries are 0.

 **Example 2:** 

 **Input:**  nums = [3,1,7]

 **Output:**  [0,0,0,0,0,0,0,0,0,0,0,0,1,2,3]

 **Explanation:** 

Choose `perm = [7, 3, 1]`.

- The first element has bit 2 set, but the second does not, so power[12] = 1.
- The first two elements have bit 1 set, but the third does not, so power[13] = 2.
- All three elements have bit 0 set, so power[14] = 3.

All higher bits are unset in the first element, so the remaining entries are 0.

 

 **Constraints:** 

- 1 <= nums.length <= 5 * 104
- 0 <= nums[i] < 215

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.3 MB  
**Submitted:** 2026-09-26T19:58:44.145Z  

```cpp
class Solution {
public:
    vector<int>solve2(vector<int>&nums){
        int n=nums.size();
        int mask=(1<<15)-1;
        vector<int>ans(15,0);
        
        int times=15;
        vector<bool>used(n,false);
        while(times--){
            
            int cnt=0;
            for(int i=0;i<n;i++){
                if(used[i]) continue;
                if((nums[i] & mask) == mask){
                    used[i]=true;
                    cnt++;
                }
            }
            for(int j=14;j>=0;j--){
                if((mask>>j) &1){
                    ans[14-j]+=cnt;
                }
            }
            //now can i find the best
            int bestidx=-1;
            int best=0;
            for(int i=0;i<n;i++){
                if(used[i]) continue;
                if((nums[i]&mask)>best){
                    best=(nums[i] & mask);
                    // best=nums[i];
                    bestidx=i;
                }
            }
            mask&=best;
            if(bestidx!=-1) used[bestidx]=true;
            for(int j=14;j>=0;j--){
                if((mask>>j) &1){
                    ans[14-j]++;
                }
            }
        }
        return ans;
    }
    vector<int> largestPower(vector<int>& nums) {
        
        //n^2
        //we have mask of 15 set bit initially
        //check with all the unused num
        //which give me best value
        //we will use that num
        //mark that as used
        return solve2(nums);

         // TC:: 15*n   
        //our mask will change for 15 times
        //so first check for all num such that mask& num==mask
        //we will perform on them 
        // then check changes our maxk with best popcount
        //uses that and change the mask
        // repeat for 15 times
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/lexicographically-largest-power-array/)