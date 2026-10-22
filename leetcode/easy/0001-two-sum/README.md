# Two Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an array of integers `nums` and an integer `target`, return  *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have  ***exactly *one solution**, and you may not use the* same* element twice.

You can return the answer in any order.

 

 **Example 1:** 

 **Input:**  `nums = [2,7,11,15], target = 9`

 **Output:**  `[0,1]`

 **Explanation:** 

The sum of `nums[0]` and `nums[1]` is `2 + 7 = 9`, which equals the target. Therefore, the indices `[0, 1]` are returned.

 **Example 2:** 

 **Input:**  `nums = [3,2,4], target = 6`

 **Output:**  `[1,2]`

 **Explanation:** 

The sum of `nums[1]` and `nums[2]` is `2 + 4 = 6`, which equals the target. Therefore, the indices `[1, 2]` are returned.

 **Example 3:** 

 **Input:**  `nums = [3,3], target = 6`

 **Output:**  `[0,1]`

 **Explanation:** 

The sum of `nums[0]` and `nums[1]` is `3 + 3 = 6`, which equals the target. Therefore, the indices `[0, 1]` are returned.

 

 **Constraints:** 

- 2 <= nums.length <= 104
- -109 <= nums[i] <= 109
- -109 <= target <= 109
- Only one valid answer exists.

 

 **Follow-up:** Can you come up with an algorithm that is less than `O(n2)` time complexity?

## Solution

**Language:** Java  
**Runtime:** 3 ms (beats 58.48%)  
**Memory:** 47 MB (beats 68.96%)  
**Submitted:** 2026-10-22T10:59:03.008Z  

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        //iterate over each element
        //check if the need is in the map or not
        //then insert the num in the mpp

        //unorderemap
        HashMap<Integer,Integer>mpp= new HashMap<>();
        // ArrayList<Integer>ans = new ArrayList<>();
        int[] ans = {-1,-1};

        for(int i=0;i<nums.length;i++){
            int need =target-nums[i];
            if(mpp.containsKey(need)){
                ans[0]=i;
                ans[1]= mpp.get(need);
                return ans;
            }
            mpp.put(nums[i],i);
        }
        return ans;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/two-sum/)