# Q2. Maximum Equal Adjacent Pairs After at Most One Replacement

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a  **1-indexed**  integer array `nums`.

You can choose two  **distinct**  values `x` and `y` and perform the following operation  **at most**  once:

- Replace every occurrence of x in nums with y.

Return the  **maximum**  possible number of pairs of adjacent elements that are equal after performing the operation.

 

 **Example 1:** 

 **Input:**  nums = [1,2,3,2]

 **Output:**  2

 **Explanation:** 

- One optimal solution is to choose x = 3 and y = 2.
- The resulting array is [1, 2, 2, 2].
- There are 2 pairs of adjacent elements that are equal: (nums[2], nums[3]) and (nums[3], nums[4]).
- Therefore, the answer is 2.

 **Example 2:** 

 **Input:**  nums = [1,2,1,2,1]

 **Output:**  4

 **Explanation:** 

- One optimal solution is to choose x = 1 and y = 2.
- The resulting array is [2, 2, 2, 2, 2].
- There are 4 pairs of adjacent elements that are equal: (nums[1], nums[2]), (nums[2], nums[3]), (nums[3], nums[4]), and (nums[4], nums[5]).
- Therefore, the answer is 4.

 **Example 3:** 

 **Input:**  nums = [1,1,1]

 **Output:**  2

 **Explanation:** 

- One optimal solution is to perform no operation.
- Thus, the resulting array is [1, 1, 1].
- There are 2 pairs of adjacent elements that are equal: (nums[1], nums[2]) and (nums[2], nums[3]).
- Therefore, the answer is 2.

 

 **Constraints:** 

- 2 <= nums.length <= 105
- 1 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 516 ms (beats 50.97%)  
**Memory:** 327.3 MB (beats 92.69%)  
**Submitted:** 2026-10-03T18:06:16.027Z  

```cpp
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        //number of pair already equal
        int n=nums.size();
        int base=0;
        map<pair<int,int>,int>mpp;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) base++;
            else{
                int a=nums[i];
                int b=nums[i+1];
                if(a>b) swap(a,b);
                mpp[{a,b}]++;
            }
        }
        int ans=0;
        for(auto& node:mpp){
            ans=max(ans,node.second);
        }
        return ans+base;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-equal-adjacent-pairs-after-at-most-one-replacement/)