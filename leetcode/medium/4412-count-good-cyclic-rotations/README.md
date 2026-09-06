# Q2. Count Good Cyclic Rotations

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` of even length `n`.

A  **cyclic rotation**  of `nums` is obtained by choosing a prefix of `nums` whose length is between 0 and `n - 1` (inclusive), and moving it to the end of the array while preserving the order of all elements.

A cyclic rotation is  **good**  if the sum of its first `n / 2` elements is  **strictly greater**  than the sum of its last `n / 2` elements.

Return the number of cyclic rotations of `nums` that are good.

 

 **Example 1:** 

 **Input:**  nums = [1,2,3,4,5,6]

 **Output:**  3

 **Explanation:** 

The cyclic rotations of `nums` are:

Cyclic rotation	Sum of first `n / 2` elements	Sum of last `n / 2` elements
`[1, 2, 3, 4, 5, 6]`	`1 + 2 + 3 = 6`	`4 + 5 + 6 = 15`
`[2, 3, 4, 5, 6, 1]`	`2 + 3 + 4 = 9`	`5 + 6 + 1 = 12`
`[3, 4, 5, 6, 1, 2]`	`3 + 4 + 5 = 12`	`6 + 1 + 2 = 9`
`[4, 5, 6, 1, 2, 3]`	`4 + 5 + 6 = 15`	`1 + 2 + 3 = 6`
`[5, 6, 1, 2, 3, 4]`	`5 + 6 + 1 = 12`	`2 + 3 + 4 = 9`
`[6, 1, 2, 3, 4, 5]`	`6 + 1 + 2 = 9`	`3 + 4 + 5 = 12`

The first half has a greater sum than the second half for 3 rotations. Thus, the answer is 3.

 **Example 2:** 

 **Input:**  nums = [1,2,1,2]

 **Output:**  0

 **Explanation:** 

The cyclic rotations of `nums` are:

Cyclic rotation	Sum of first `n / 2` elements	Sum of last `n / 2` elements
`[1, 2, 1, 2]`	`1 + 2 = 3`	`1 + 2 = 3`
`[2, 1, 2, 1]`	`2 + 1 = 3`	`2 + 1 = 3`
`[1, 2, 1, 2]`	`1 + 2 = 3`	`1 + 2 = 3`
`[2, 1, 2, 1]`	`2 + 1 = 3`	`2 + 1 = 3`

No cyclic rotation is good because the two sums are equal for every rotation. Thus, the answer is 0.

 

 **Constraints:** 

- 2 <= n == nums.length <= 105
- 1 <= nums[i] <= 109
- n is even.

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 36.86%)  
**Memory:** 103.3 MB (beats 29.68%)  
**Submitted:** 2026-09-06T11:00:13.950Z  

```cpp
#define ll long long
class Solution {
public:
    // int brute(vector<int>& nums) {
    //     int n=nums.size();
    //     int m=2*n;
        
    //     ll pref=0;
    //     ll suff=0;
        
    //     for(int i=0;i<n;i++){
    //         if(i<n/2) pref+=nums[i];
    //         else suff+=nums[i];
    //     }
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
            
    //         if(pref>suff) cnt++;
            
    //         int j=(i+n)%n;
    //         int k=(i+(n/2))%n;
            
    //         pref-=nums[i];
    //         pref+=nums[k];
    //         suff-=nums[k];
    //         suff+=nums[j];   
    //     }
    //     return cnt;
    // }
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        ll pref=0;
        ll total=0;
        int len=n/2; //half
        
        for(int i=0;i<n;i++){
            total+=nums[i];
            if(i<len) pref+=nums[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(2*pref>total){
                cnt++;
            }
            pref-=nums[i];
            pref+=nums[(i+len) % n];
        }
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-good-cyclic-rotations/)