# Create Sorted Array through Instructions

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an integer array `instructions`, you are asked to create a sorted array from the elements in `instructions`. You start with an empty container `nums`. For each element from  **left to right**  in `instructions`, insert it into `nums`. The  **cost**  of each insertion is the  **minimum**  of the following:

- The number of elements currently in nums that are strictly less than instructions[i].
- The number of elements currently in nums that are strictly greater than instructions[i].

For example, if inserting element `3` into `nums = [1,2,3,5]`, the  **cost**  of insertion is `min(2, 1)` (elements `1` and `2` are less than `3`, element `5` is greater than `3`) and `nums` will become `[1,2,3,3,5]`.

Return  *the  **total cost**  to insert all elements from* `instructions` *into* `nums`. Since the answer may be large, return it  **modulo**  `109 + 7`

 

 **Example 1:** 

```
Input: instructions = [1,5,6,2]
Output: 1
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
The total cost is 0 + 0 + 0 + 1 = 1.
```

 **Example 2:** 

```
Input: instructions = [1,2,3,6,5,4]
Output: 3
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.

```

 **Example 3:** 

```
Input: instructions = [1,3,3,3,2,4,2,1,2]
Output: 4
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3,3].
Insert 2 with cost min(1, 3) = 1, now nums = [1,2,3,3,3].
Insert 4 with cost min(5, 0) = 0, now nums = [1,2,3,3,3,4].
​​​​​​​Insert 2 with cost min(1, 4) = 1, now nums = [1,2,2,3,3,3,4].
​​​​​​​Insert 1 with cost min(0, 6) = 0, now nums = [1,1,2,2,3,3,3,4].
​​​​​​​Insert 2 with cost min(2, 4) = 2, now nums = [1,1,2,2,2,3,3,3,4].
The total cost is 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4.

```

 

 **Constraints:** 

- 1 <= instructions.length <= 105
- 1 <= instructions[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 163 ms (beats 87.97%)  
**Memory:** 146.9 MB (beats 53.37%)  
**Submitted:** 2026-10-08T06:51:55.800Z  

```cpp
class Solution {
public:
    const int total = 1e5+1;
    vector<int>bit;
    const int mod= 1e9+7;

    void update(int idx,int val){
        while(idx<=total){
            bit[idx]+=val;
            idx+=(idx & -idx);
        }
    }
    int query(int idx){ //sum till this index
        int ans=0;
        while(idx>0){
            ans+=bit[idx];
            idx-=(idx & -idx);
        }
        return ans;
    }
    int createSortedArray(vector<int>& instructions) {
        //total number of number less than this 
        // toal number of number greater than this
        int n=instructions.size();

        bit.resize(total,0);

        int cost=0;
        for(int i=0;i<n;i++){
            int val=instructions[i];
            //update
            //query
            int smal = query(val-1);
            int big= i - query(val); 

            update(val,1);
            cost= (cost + min(smal,big)) % mod;
        }

        //apply fenwick tree
        return cost;

        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/create-sorted-array-through-instructions/)