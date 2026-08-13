# Q2. Count Subarrays With Even Odd Ratio I

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` and two integers `a` and `b`.

For a subarray, let:

- x be the number of even elements.
- y be the number of odd elements.

The ratio of even to odd elements in a subarray is defined as `x / y`, where ratios are compared by their exact rational values.

A subarray is considered  **valid**  if:

- y > 0, and
- x / y <= a / b.

Return the number of valid subarrays in `nums`.

 

 **Example 1:** 

 **Input:**  nums = [1,2,1,2], a = 3, b = 2

 **Output:**  7

 **Explanation:** 

The following are the valid subarrays:

Subarray	Values	Even Count	Odd Count	Ratio
`nums[0..0]`	`[1]`	0	1	`0 / 1`
`nums[0..1]`	`[1, 2]`	1	1	`1 / 1`
`nums[0..2]`	`[1, 2, 1]`	1	2	`1 / 2`
`nums[0..3]`	`[1, 2, 1, 2]`	2	2	`2 / 2`
`nums[1..2]`	`[2, 1]`	1	1	`1 / 1`
`nums[2..2]`	`[1]`	0	1	`0 / 1`
`nums[2..3]`	`[1, 2]`	1	1	`1 / 1`

Thus, the number of valid subarrays is 7.

 **Example 2:** 

 **Input:**  nums = [2,2,1], a = 2, b = 1

 **Output:**  3

 **Explanation:** 

The following are the valid subarrays:

Subarray	Values	Even Count	Odd Count	Ratio
`nums[0..2]`	`[2, 2, 1]`	2	1	`2 / 1`
`nums[1..2]`	`[2, 1]`	1	1	`1 / 1`
`nums[2..2]`	`[1]`	0	1	`0 / 1`

Thus, the number of valid subarrays is 3.

 **Example 3:** 

 **Input:**  nums = [2,2,2], a = 1, b = 1

 **Output:**  0

 **Explanation:** 

Every subarray contains 0 odd numbers, so no subarray is valid.

 

 **Constraints:** 

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 1000
- 1 <= a, b <= 1000

## Solution

**Language:** C++  
**Runtime:** 99 ms (beats 5.22%)  
**Memory:** 31.7 MB (beats 15.23%)  
**Submitted:** 2026-08-13T06:03:46.396Z  

```cpp
class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<int>odd(n,0);
        vector<int>even(n,0);
        
        nums[0]%2==0 ? even[0]=1: odd[0]=1;
        
        for(int i=1;i<n;i++){
            if(nums[i]%2==0){
                even[i]= 1+ even[i-1];
                odd[i]= odd[i-1];
            }else{
                odd[i] = 1+ odd[i-1];
                even[i]=even[i-1];
            }
        }
        int cnt=0;
        double act=(double)a/(double)(b);
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int e= i>0?  even[j]- even[i-1] : even[j];
                int o= i>0 ? odd[j]- odd[i-1] : odd[j];
                
                
                if(o>0){
                    double curr=(double)e/(double)(o);
                    if(curr<=act) cnt++;
                }
            }
        }
        return cnt;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/)