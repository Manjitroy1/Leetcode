# Q3. Maximum Gap Between Stations

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two strings `skill` and `station` of lengths `n` and `m`, respectively.

`skill[i]` represents the skill of worker `i`, and `station[j]` represents the skill supported by station `j`.

You must assign  **every**  worker to a  **distinct**  station. Let `ji` be the index of the station assigned to worker `i`. A valid assignment must satisfy:

- station[ji] == skill[i] for every 0 <= i < n.
- The assigned station indices must be strictly increasing in worker order, meaning j0 < j1 <... < jn - 1.

The  **gap**  of an assignment is the  **maximum difference**  between the station indices assigned to two  **consecutive**  workers. In other words, it is `max(ji - ji - 1)` over all `1 <= i < n`.

If there is only one worker, the gap is 0.

Return the  **maximum**  possible gap among all valid assignments. It is guaranteed that  **at least**  one valid assignment exists.

 

 **Example 1:** 

 **Input:**  skill = "aa", station = "aaaa"

 **Output:**  3

 **Explanation:** 

- The two workers must be assigned to two different 'a' stations.
- Assigning them to stations [0, 3] gives a gap of 3.

 **Example 2:** 

 **Input:**  skill = "xyz", station = "xyzz"

 **Output:**  2

 **Explanation:** 

- Assign worker 0 to station j = 0, and worker 1 to station j = 1.
- To maximize the gap, assign worker 2 to station j = 3.
- This gives the assignment [0, 1, 3] with gaps [1, 2], so the gap is 2.

 **Example 3:** 

 **Input:**  skill = "cbc", station = "cbcdbc"

 **Output:**  4

 **Explanation:** 

- Assign worker 0 to station j = 0, and worker 1 to station j = 1.
- To maximize the gap, assign worker 2 to station j = 5.
- This gives the assignment [0, 1, 5] with gaps [1, 4], so the gap is 4.

 

 **Constraints:** 

- skill.length == n
- station.length == m
- 1 <= n <= m <= 105
- skill and station consist of lowercase English letters.
- It is guaranteed that a valid assignment exists for every worker.

## Solution

**Language:** C++  
**Runtime:** 51 ms (beats 71.51%)  
**Memory:** 72.1 MB (beats 81.11%)  
**Submitted:** 2026-08-16T14:09:12.154Z  

```cpp
class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        int j=0;

        for(int i=0;i<m && j<n;i++){
            if(station[i]==skill[j]){
                left[j]=i;
                j++;
            }
        }
        j=n-1;
        
        for(int i=m-1;i>=0 && j>=0;i--){
            if(station[i]==skill[j]){
                right[j]=i;
                j--;
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans, right[i]-left[i-1]);
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-gap-between-stations/)