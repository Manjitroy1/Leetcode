# Trapping Rain Water

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

 

 **Example 1:** 

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

```

 **Example 2:** 

```
Input: height = [4,2,0,3,2,5]
Output: 9

```

 

 **Constraints:** 

- n == height.length
- 1 <= n <= 2 * 104
- 0 <= height[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 27.4 MB (beats 17.36%)  
**Submitted:** 2026-08-08T06:04:28.504Z  

```cpp
class Solution {
public:
    int solve(vector<int>&height){
        int n=height.size();
        vector<int>pre(n,0);
        vector<int>suff(n,0);

        int pmx=height[0];
        int smx=height[n-1];
        for(int i=1;i<n;i++){
            int j=n-i-1;
            pre[i]=pmx;
            suff[j]=smx;
            smx=max(smx,height[j]);
            pmx=max(pmx,height[i]);
        }

        // smx=height[n-1];
        // for(int i=n-2;i>=0;i--){
        //     suff[i]=smx;
        //     smx=max(smx,height[i]);
        // }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int curr= height[i];
            if(curr<pre[i] && curr<suff[i]){
                ans+= (min(pre[i],suff[i]) - curr);
            }
        }
        return ans;
    }
    int trap(vector<int>& height) {
        return solve(height);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/trapping-rain-water/)