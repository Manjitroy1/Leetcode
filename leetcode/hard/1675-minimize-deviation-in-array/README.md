# Minimize Deviation in Array

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array `nums` of `n` positive integers.

You can perform two types of operations on any element of the array any number of times:

- If the element is even, divide it by 2. For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
- If the element is odd, multiply it by 2. For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].

The  **deviation**  of the array is the  **maximum difference**  between any two elements in the array.

Return  *the  **minimum deviation**  the array can have after performing some number of operations.* 

 

 **Example 1:** 

```
Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.

```

 **Example 2:** 

```
Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.

```

 **Example 3:** 

```
Input: nums = [2,10,8]
Output: 3

```

 

 **Constraints:** 

- n == nums.length
- 2 <= n <= 5 * 104
- 1 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 239 ms (beats 50.97%)  
**Memory:** 60.7 MB (beats 29.36%)  
**Submitted:** 2026-08-27T17:29:20.844Z  

```cpp
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // odd number can beacame even and then odd
        //even number can reduce to 1 thus lost the track or the original value
        
        priority_queue<int>pq;

        int minval=INT_MAX;
        //twicing the odd ones and storing the minval
        for(int num:nums){
            if(num%2==1){
                num=num*2;
            }
            pq.push(num);
            minval=min(minval,num);
        }

        int mindev=INT_MAX;

        while(true){
            int mxval=pq.top();
            pq.pop();
            mindev=min(mindev,mxval-minval);

            if(mxval%2==1){
                break;
            }
            mxval/=2;
            minval=min(minval,mxval);
            pq.push(mxval);
        }
        return mindev;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimize-deviation-in-array/)