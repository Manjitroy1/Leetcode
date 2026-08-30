# Q1. Count Integers Appearing in a Single Block

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer array `nums`.

An integer `x` is  **special**  if all occurrences of `x` in `nums` appear in a single  **contiguous**  block.

Return the number of  **distinct**  special integers in `nums`.

 

 **Example 1:** 

 **Input:**  nums = [1,2,2,1]

 **Output:**  1

 **Explanation:** 

- 1 appears at indices 0 and 3, forming two separate blocks, so it is not special.
- 2 appears in a single contiguous block at indices [1, 2], so it is special.

Therefore, there is one special integer.

 **Example 2:** 

 **Input:**  nums = [3,3,1,2,2,1]

 **Output:**  2

 **Explanation:** 

- 3 appears in a single contiguous block at indices [0, 1], so it is special.
- 1 appears at indices 2 and 5, forming two separate blocks, so it is not special.
- 2 appears in a single contiguous block at indices [3, 4], so it is special.

Therefore, there are two special integers.

 

 **Constraints:** 

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Solution

**Language:** C++  
**Runtime:** 10 ms (beats 3.08%)  
**Memory:** 36.4 MB (beats 6.35%)  
**Submitted:** 2026-08-30T08:48:14.330Z  

```cpp
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>bucket(101);
        for(int i=0;i<n;i++){
            bucket[nums[i]].push_back(i);
        }
        int cnt=0;
        
        for(int i=1;i<bucket.size();i++){
            if(!bucket[i].empty()){
                int sz=bucket[i].size();
                if(sz==1){
                    cnt++;
                    continue;
                }
                bool flag=true;
                for(int j=1;j<sz;j++){
                    if(bucket[i][j-1]+1 !=bucket[i][j]){
                        flag=false;
                    }
                }
                if(flag) cnt++;
            }
        }
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-integers-appearing-in-a-single-block/)