# Continuous Subarrays

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a  **0-indexed**  integer array `nums`. A subarray of `nums` is called  **continuous**  if:

- Let i, i + 1,..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.

Return  *the total number of  **continuous**  subarrays.* 

A subarray is a contiguous  **non-empty**  sequence of elements within an array.

 

 **Example 1:** 

```
Input: nums = [5,4,2,4]
Output: 8
Explanation: 
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
There are no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.

```

 

 **Example 2:** 

```
Input: nums = [1,2,3]
Output: 6
Explanation: 
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 106 ms (beats 41.32%)  
**Memory:** 121.4 MB (beats 48.58%)  
**Submitted:** 2026-10-26T13:31:15.304Z  

```cpp
#define ll long long
class Solution {
public:
    long long better(vector<int>& nums) {
        int n=nums.size();
        ll ans=0;
        int l=0;
        multiset<int>stt;
        for(int r=0;r<n;r++){
            stt.insert(nums[r]);
            int mn= *stt.begin();
            int mx = *prev(stt.end());

            while(l<r && !stt.empty() && (mx-mn)>2){
                auto it = stt.find(nums[l]);
                stt.erase(it);
                l++;
                mn= *stt.begin();
                mx = *prev(stt.end());
            }
            ans += (r-l+1)*1LL;        
        }
        return ans;
    }
    long long best(vector<int>& nums) {
        int n=nums.size();
        //using mono tonic dequeue
        deque<int>mn;
        deque<int>mx;
        long long ans =0;

        int l=0;
        for(int r=0;r<n;r++){

            int x =nums[r];

            //pusing the element
            while(!mn.empty() && nums[mn.back()] > x){
                mn.pop_back();
            }
            mn.push_back(r);

            while(!mx.empty() && nums[mx.back()] < x){
                mx.pop_back();
            }
            mx.push_back(r);

            //remove outdated elemnt
            while(!mn.empty() && mn.front() < l){
                mn.pop_front();
            }
            while(!mx.empty() && mx.front() < l){
                mx.pop_front();
            }

            while(l<r && nums[mx.front()] - nums[mn.front()] > 2){
                if(mx.front()==l) mx.pop_front();
                if(mn.front()==l) mn.pop_front();
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    long long continuousSubarrays(vector<int>& nums) {
        return best(nums);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/continuous-subarrays/)