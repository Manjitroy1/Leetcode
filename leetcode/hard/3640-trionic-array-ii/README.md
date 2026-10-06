# Trionic Array II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` of length `n`.

A  **trionic subarray**  is a contiguous subarray `nums[l...r]` (with `0 <= l < r < n`) for which there exist indices `l < p < q < r` such that:

- nums[l...p] is strictly increasing,
- nums[p...q] is strictly decreasing,
- nums[q...r] is strictly increasing.

Return the  **maximum**  sum of any trionic subarray in `nums`.

 

 **Example 1:** 

 **Input:**  nums = [0,-2,-1,-3,0,2,-1]

 **Output:**  -4

 **Explanation:** 

Pick `l = 1`, `p = 2`, `q = 3`, `r = 5`:

- nums[l...p] = nums[1...2] = [-2, -1] is strictly increasing (-2 < -1).
- nums[p...q] = nums[2...3] = [-1, -3] is strictly decreasing (-1 > -3)
- nums[q...r] = nums[3...5] = [-3, 0, 2] is strictly increasing (-3 < 0 < 2).
- Sum = (-2) + (-1) + (-3) + 0 + 2 = -4.

 **Example 2:** 

 **Input:**  nums = [1,4,2,7]

 **Output:**  14

 **Explanation:** 

Pick `l = 0`, `p = 1`, `q = 2`, `r = 3`:

- nums[l...p] = nums[0...1] = [1, 4] is strictly increasing (1 < 4).
- nums[p...q] = nums[1...2] = [4, 2] is strictly decreasing (4 > 2).
- nums[q...r] = nums[2...3] = [2, 7] is strictly increasing (2 < 7).
- Sum = 1 + 4 + 2 + 7 = 14.

 

 **Constraints:** 

- 4 <= n = nums.length <= 105
- -109 <= nums[i] <= 109
- It is guaranteed that at least one trionic subarray exists.

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 67.32%)  
**Memory:** 132.7 MB (beats 76.47%)  
**Submitted:** 2026-10-06T10:12:59.806Z  

```cpp
#define ll long long
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        //increasing decreasing increasing
        //up1 = maximum increasing subarry
        //down = inceasing + currently deacreaing
        // up2= increasing + decreasing + currenlty increasing
        const ll NEG= LLONG_MIN/4;
        int n=nums.size();
        ll ans=NEG;

        ll up1=NEG;
        ll up2=NEG;
        ll dn=NEG;


        for(int i=1;i<n;i++){
            ll x=nums[i-1];
            ll y=nums[i];

            if(x<y){
                //increasing
                up1=max(up1,x)+y;
                up2=max(up2,dn)+y;
                dn=NEG;

                ans=max(ans,up2);
            }
            else if(x>y){
                // decrasing
                dn=max(up1,dn)+y;
                up1=NEG;
                up2=NEG;
            }else{
                //straight
                up1=up2=dn=NEG;
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/trionic-array-ii/)