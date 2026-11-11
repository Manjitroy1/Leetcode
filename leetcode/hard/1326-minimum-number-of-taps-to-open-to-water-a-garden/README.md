# Minimum Number of Taps to Open to Water a Garden

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

There is a one-dimensional garden on the x-axis. The garden starts at the point `0` and ends at the point `n`. (i.e., the length of the garden is `n`).

There are `n + 1` taps located at points `[0, 1,..., n]` in the garden.

Given an integer `n` and an integer array `ranges` of length `n + 1` where `ranges[i]` (0-indexed) means the `i-th` tap can water the area `[i - ranges[i], i + ranges[i]]` if it was open.

Return  *the minimum number of taps*  that should be open to water the whole garden, If the garden cannot be watered return  **-1**.

 

Original
C++
 **Example 1:** 

```
Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]

```

 **Example 2:** 

```
Input: n = 3, ranges = [0,0,0,0]
Output: -1
Explanation: Even if you activate all the four taps you cannot water the whole garden.

```

 

 **Constraints:** 

- 1 <= n <= 104
- ranges.length == n + 1
- 0 <= ranges[i] <= 100

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 68.83%)  
**Memory:** 19.2 MB (beats 60.51%)  
**Submitted:** 2026-11-11T14:17:57.226Z  

```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>maxrange(n+1,0);
        for(int i=0;i<n+1;i++){
            int l = max(0,i-ranges[i]);
            int r = min(n,i+ranges[i]);

            maxrange[l] = max(maxrange[l],r);
            //i have tap range from 2 to 3 
            // i have another tap range 2 to 5 
            //in short we can say i have a tap of range 2 to 5
            // l = each initial start (2)
        }
        int maxreach=0; //we have the change to go that max
        int currreach=0; //with the current number of tap we can go till that
        int tap=0;

        // if somehow i is greater than maxreach return -1
        for(int i=0;i<=n;i++){
            if(i>maxreach) return -1;
            if(i>currreach){
                tap++;
                currreach =  maxreach;
            }
            maxreach = max(maxreach,maxrange[i]);
        }
        return tap;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/)