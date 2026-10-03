# Q1. Rearrange Array by Removing Distinct Values

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an integer array `nums`.

You start with an  **empty**  array `ans`. Repeat the following operation until `nums` is  **empty** :

- Identify all distinct values currently present in nums.
- Remove one occurrence of every distinct value currently in nums, and append those values to ans in ascending order.

Return the array `ans`.

 

 **Example 1:** 

 **Input:**  nums = [3,1,3,2,1,3]

 **Output:**  [1,2,3,1,3,3]

 **Explanation:** 

Operation	Appended to `ans`	`nums` after	`ans` after
1	1, 2, 3	`[3, 1, 3]`	`[1, 2, 3]`
2	1, 3	`[3]`	`[1, 2, 3, 1, 3]`
3	3	`[]`	`[1, 2, 3, 1, 3, 3]`

`nums` is now empty, so the answer is `[1, 2, 3, 1, 3, 3]`.

 **Example 2:** 

 **Input:**  nums = [7,7,4,4,4]

 **Output:**  [4,7,4,7,4]

 **Explanation:** 

Operation	Appended to `ans`	`nums` after	`ans` after
1	4, 7	`[7, 4, 4]`	`[4, 7]`
2	4, 7	`[4]`	`[4, 7, 4, 7]`
3	4	`[]`	`[4, 7, 4, 7, 4]`

`nums` is now empty, so the answer is `[4, 7, 4, 7, 4]`.

 

 **Constraints:** 

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 50.32%)  
**Memory:** 34.8 MB (beats 53.99%)  
**Submitted:** 2026-10-03T16:45:59.241Z  

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int>freq;
        for(int& e:nums){
            freq[e]++;
        }
        vector<int>ans;
        while(!freq.empty()){

            int l=ans.size();
            
            for(auto& node:freq){
                ans.push_back(node.first);
            }
            
            int r=ans.size();
            for(int i=l;i<r;i++){
                freq[ans[i]]--;
                if(freq[ans[i]]==0) freq.erase(ans[i]);
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/rearrange-array-by-removing-distinct-values/)