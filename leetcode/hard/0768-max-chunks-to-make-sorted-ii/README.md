# Max Chunks To Make Sorted II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `arr`.

We split `arr` into some number of  **chunks**  (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return  *the largest number of chunks we can make to sort the array*.

 

 **Example 1:** 

```
Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.

```

 **Example 2:** 

```
Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.

```

 

 **Constraints:** 

- 1 <= arr.length <= 2000
- 0 <= arr[i] <= 108

## Solution

**Language:** C++  
**Runtime:** 15 ms (beats 12.61%)  
**Memory:** 20 MB (beats 7.30%)  
**Submitted:** 2026-08-28T19:05:45.735Z  

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int>nums=arr;
        sort(nums.begin(),nums.end());
        if(nums==arr) return n;
        map<int,int>stt1;
        map<int,int>stt2;

        int cnt=0;
        for(int i=0;i<n;i++){
            stt1[arr[i]]++;
            stt2[nums[i]]++;

            if(stt1==stt2){
                cnt++;
                stt1.clear();
                stt2.clear();
            }
        }
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/)