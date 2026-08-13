# Q4. Count Subarrays With Even Odd Ratio II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

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

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 1 <= a, b <= 109​​​​​​​

## Solution

**Language:** C++  
**Runtime:** 577 ms (beats 5.92%)  
**Memory:** 364.2 MB (beats 5.00%)  
**Submitted:** 2026-08-13T07:26:05.297Z  

```cpp
class Solution {
public:
    long long  merge(int low,int mid,int high,vector<long long>&pre){
        long long cnt=0;
        vector<long long>temp;
        int l=low;
        int r=mid+1;
        while(l<=mid && r<=high){
            if(pre[l]<=pre[r]){
                cnt+=(high-r+1);
                temp.push_back(pre[l]);
                l++;
            }else{
                temp.push_back(pre[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(pre[l]);
            l++;
        }
        while(r<=high){
            temp.push_back(pre[r]);
            r++;

        }
        for(int i=low;i<=high;i++){
            pre[i] = temp[i-low];
        }
        return cnt;
        
    }
    
    long long mergetech(int low,int high,vector<long long>&pre){
        if(low>=high) return 0;
        
        long long cnt=0;
        if(low<high){
            int mid= low + (high-low)/2;
            
            cnt+=mergetech(low,mid,pre);
            cnt+=mergetech(mid+1,high,pre);
            cnt+=merge(low,mid,high,pre);
        }
        return cnt;
    }
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int g = __gcd(a,b);
        a/=g;
        b/=g;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0)  nums[i]= -b;  //even then neg
            else nums[i]=a;   //odd then pos
        }

        vector<long long>pre(n+1,0);

        for(int i=0;i<n;i++){
            pre[i+1] = nums[i] + pre[i];
        }

        return mergetech(0,n,pre);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-ii/)