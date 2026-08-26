# Range Sum Query - Mutable

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums`, handle multiple queries of the following types:

- Update the value of an element in nums.
- Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the `NumArray` class:

- NumArray(int[] nums) Initializes the object with the integer array nums.
- void update(int index, int val) Updates the value of nums[index] to be val.
- int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] +... + nums[right]).

 

 **Example 1:** 

```
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

```

 

 **Constraints:** 

- 1 <= nums.length <= 3 * 104
- -100 <= nums[i] <= 100
- 0 <= index < nums.length
- -100 <= val <= 100
- 0 <= left <= right < nums.length
- At most 3 * 104 calls will be made to update and sumRange.

## Solution

**Language:** C++  
**Runtime:** 40 ms (beats 90.81%)  
**Memory:** 180.3 MB (beats 90.07%)  
**Submitted:** 2026-08-26T13:43:48.962Z  

```cpp
class NumArray {
public:
    int n;
    vector<int>bit;
    vector<int>nums;

    void upd(int idx,int val){
        while(idx<=n){
            bit[idx]+=val;
            idx+=(idx & -idx);
        }
    }
    int query(int idx){
        int ans=0;
        while(idx>0){
            ans+=bit[idx];
            idx-=(idx & -idx);
        }
        return ans;
    }
    NumArray(vector<int>& arr) {
        this->nums = arr;
        n=nums.size();
        bit.resize(n+1,0);

        for(int i=0;i<n;i++){
            upd(i+1,nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff= val-nums[index];
        nums[index]=val;
        upd(index+1,diff);
        
    }
    
    int sumRange(int left, int right) {
        return query(right+1) - query(left);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
```

---

[View on LeetCode](https://leetcode.com/problems/range-sum-query-mutable/)