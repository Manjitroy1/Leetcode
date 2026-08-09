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
**Runtime:** 62 ms (beats 52.04%)  
**Memory:** 182.3 MB (beats 38.43%)  
**Submitted:** 2026-08-09T09:57:51.463Z  

```cpp
class SGTree{
public:
    vector<int>sgt;
    SGTree(int n){
        sgt.resize(4*n+1);
    }
    void build(int idx,int low,int high,vector<int>&arr){
        if(low==high){
            sgt[idx]=arr[low];
            return ;
        }
        int mid= (low+high)>>1;

        build(2*idx + 1, low,  mid,arr);
        build(2*idx + 2, mid+1,high,arr);
        sgt[idx] = sgt[2*idx + 1] + sgt[2*idx + 2];
    }
    int query(int idx,int low, int high, int l,int r){

        //no overlap. low high l r.  or l r low high
        if(l>high || r< low) return 0;

        //complete overlap. l low high  r
        if(l<=low && high <=r) return sgt[idx];

        //partial ovelap
        int mid= (low+high)>>1;
        int left= query(2*idx+1, low, mid,l,r);
        int right = query(2*idx+2, mid+1, high, l,r);
        return (left+right);
    }
    void update(int idx,int low, int  high, int pos,int val){
        if(low==high){
            sgt[idx] = val;
            return;
        }

        int mid= (low+high)>>1;

        if(pos<=mid) update(2*idx+1,low,mid, pos,val);
        else update(2*idx+2,mid+1,high,pos,val);

        sgt[idx] = sgt[2*idx+1] + sgt[2*idx + 2];
    }
};
class NumArray {
public:
    int n;
    SGTree sg;
    NumArray(vector<int>& nums) : n(nums.size()), sg(n) {
        sg.build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        sg.update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return sg.query(0,0,n-1,left,right);
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