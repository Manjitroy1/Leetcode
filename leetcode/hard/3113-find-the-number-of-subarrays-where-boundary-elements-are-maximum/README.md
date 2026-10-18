# Find the Number of Subarrays Where Boundary Elements Are Maximum

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array of  **positive**  integers `nums`.

Return the number of subarrays of `nums`, where the  **first**  and the  **last**  elements of the subarray are  *equal*  to the  **largest**  element in the subarray.

 

 **Example 1:** 

 **Input:**  nums = [1,4,3,3,2]

 **Output:**  6

 **Explanation:** 

There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:

- subarray [1,4,3,3,2], with its largest element 1. The first element is 1 and the last element is also 1.
- subarray [1,4,3,3,2], with its largest element 4. The first element is 4 and the last element is also 4.
- subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and the last element is also 3.
- subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and the last element is also 3.
- subarray [1,4,3,3,2], with its largest element 2. The first element is 2 and the last element is also 2.
- subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and the last element is also 3.

Hence, we return 6.

 **Example 2:** 

 **Input:**  nums = [3,3,3]

 **Output:**  6

 **Explanation:** 

There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:

- subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
- subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
- subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
- subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
- subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
- subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.

Hence, we return 6.

 **Example 3:** 

 **Input:**  nums = [1]

 **Output:**  1

 **Explanation:** 

There is a single subarray of `nums` which is `[1]`, with its largest element 1. The first element is 1 and the last element is also 1.

Hence, we return 1.

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 226 ms (beats 19.90%)  
**Memory:** 183.3 MB (beats 28.16%)  
**Submitted:** 2026-10-18T17:19:08.102Z  

```cpp
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>pge(n,-1);
        stack<int>stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && nums[i] >= nums[stk.top()]){
                stk.pop();
            }
            pge[i] = stk.empty()? -1: stk.top();
            stk.push(i);
        }
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            //end index is the i
            //start index have to find from mpp
            mpp[nums[i]].push_back(i);
            int pos = pge[i];
            if(pos==-1) ans+= mpp[nums[i]].size();
            else{
                //find the upper bound of pos
                ans+= mpp[nums[i]].end() - upper_bound(mpp[nums[i]].begin(),mpp[nums[i]].end(),pos);
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/)