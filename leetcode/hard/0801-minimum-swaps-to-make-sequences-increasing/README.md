# Minimum Swaps To Make Sequences Increasing

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given two integer arrays of the same length `nums1` and `nums2`. In one operation, you are allowed to swap `nums1[i]` with `nums2[i]`.

- For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].

Return  *the minimum number of needed operations to make* `nums1` *and* `nums2` ***strictly increasing***. The test cases are generated so that the given input always makes it possible.

An array `arr` is  **strictly increasing**  if and only if `arr[0] < arr[1] < arr[2] <... < arr[arr.length - 1]`.

 

 **Example 1:** 

```
Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
Output: 1
Explanation: 
Swap nums1[3] and nums2[3]. Then the sequences are:
nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
which are both strictly increasing.

```

 **Example 2:** 

```
Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
Output: 1

```

 

 **Constraints:** 

- 2 <= nums1.length <= 105
- nums2.length == nums1.length
- 0 <= nums1[i], nums2[i] <= 2 * 105

## Solution

**Language:** C++  
**Runtime:** 97 ms (beats 33.13%)  
**Memory:** 124.4 MB (beats 51.85%)  
**Submitted:** 2026-10-15T11:28:35.165Z  

```cpp
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int>>dp(n,vector<int>(2,1e9));
        // dp[i][swap] = minimum number of swaps so that 0 to i is in strictly incrasing order
        dp[0][0] = 0; //we did not swap
        dp[0][1] = 1; //we swapped 0 index

        for(int i=1;i<n;i++){
            for(int s=0;s<2;s++){ //let s denote previos ones swap not swap
                if(s==0){//prev one not swapped
                    //this one swap
                    if(nums1[i-1] < nums2[i] && nums2[i-1]< nums1[i]){
                        dp[i][1] = min(dp[i][1], 1 + dp[i-1][0]);
                    }
                    //this not swap
                    if(nums1[i-1] < nums1[i] && nums2[i-1]< nums2[i]){
                        dp[i][0] = min(dp[i][0], dp[i-1][0]);
                    }

                }
                else{ // prev is swapped
                    //this not swap
                    if(nums2[i-1]< nums1[i] && nums1[i-1]< nums2[i]){
                        dp[i][0] = min(dp[i][0], dp[i-1][1]);
                    }
                    //this swap
                    if(nums2[i-1] < nums2[i] && nums1[i-1] < nums1[i]){
                        dp[i][1] = min(dp[i][1], 1 + dp[i-1][1]);
                    }

                }
            }
        } 
        return min(dp[n-1][0],dp[n-1][1]);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/)