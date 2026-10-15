# Number of Visible People in a Queue

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

There are `n` people standing in a queue, and they numbered from `0` to `n - 1` in  **left to right**  order. You are given an array `heights` of  **distinct**  integers where `heights[i]` represents the height of the `ith` person.

A person can  **see**  another person to their right in the queue if everybody in between is  **shorter**  than both of them. More formally, the `ith` person can see the `jth` person if `i < j` and `min(heights[i], heights[j]) > max(heights[i+1], heights[i+2],..., heights[j-1])`.

Return  *an array* `answer` *of length* `n` *where* `answer[i]` *is the  **number of people**  the* `ith` *person can  **see**  to their right in the queue*.

 

 **Example 1:** 

```
Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.

```

 **Example 2:** 

```
Input: heights = [5,1,2,3,10]
Output: [4,1,1,1,0]

```

 

 **Constraints:** 

- n == heights.length
- 1 <= n <= 105
- 1 <= heights[i] <= 105
- All the values of heights are unique.

## Solution

**Language:** C++  
**Runtime:** 15 ms (beats 55.09%)  
**Memory:** 88.5 MB (beats 83.10%)  
**Submitted:** 2026-10-15T09:00:25.121Z  

```cpp
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        //we can solve using stack 
        int n=heights.size();
        stack<int>stk;
        vector<int>ans(n,0);
        stk.push(heights[n-1]);
        
        for(int i=n-2;i>=0;i--){
            int cnt=0;
            while(!stk.empty() && stk.top() <= heights[i]){
                stk.pop();
                cnt++;
            }
            ans[i] = cnt + (!stk.empty());
            stk.push(heights[i]);
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-visible-people-in-a-queue/)