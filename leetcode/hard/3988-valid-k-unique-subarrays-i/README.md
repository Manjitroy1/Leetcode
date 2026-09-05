# Q4. Valid K-Unique Subarrays I

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` and an integer `k`.

You are also given a 2D integer array `queries`, where `queries[i] = [li, ri]` represents the  **subarray**  `nums[li..ri]`.

For each query, the  **subarray**  `nums[li..ri]` is considered  **valid**  if:

- It contains exactly k distinct numbers, and
- The frequency of every number in the subarray is even.

Return a boolean array `ans`, where `ans[i]` is `true` if `nums[li..ri]` is  **valid**, and `false` otherwise.

 

 **Example 1:** 

 **Input:**  nums = [1,2,2,1], k = 2, queries = [[0,1],[0,3],[1,2]]

 **Output:**  [false,true,false]

 **Explanation:** 

`i`	`[li, ri]`	Subarray	Unique numbers	Frequency	Validity check
0	[0, 1]	[1, 2]	{1, 2} → 2	{1: 1, 2: 1}	`false`: Element counts are not even.
1	[0, 3]	[1, 2, 2, 1]	{1, 2} → 2	{1: 2, 2: 2}	`true`: Exactly `k = 2` distinct elements, all appear an even number of times.
2	[1, 2]	[2, 2]	{2} → 1	{2: 2}	`false`: Number of distinct elements is less than `k = 2`.

Thus, `ans = [false, true, false]`.

 **Example 2:** 

 **Input:**  nums = [3,3,3], k = 1, queries = [[1,2],[0,2]]

 **Output:**  [true,false]

 **Explanation:** 

`i`	`[li, ri]`	Subarray	Unique numbers	Frequency	Validity check
0	[1, 2]	[3, 3]	{3} → 1	{3: 2}	`true`: Exactly `k = 1` distinct element, appears an even number of times.
1	[0, 2]	[3, 3, 3]	{3} → 1	{3: 3}	`false`: 3 does not appear an even number of times.

Thus, `ans = [true, false]`.

 

 **Constraints:** 

- 2 <= n == nums.length <= 105
- 1 <= nums[i] <= 105
- 1 <= k <= n
- 1 <= queries.length <= 105
- queries[i] == [li, ri]
- 0 <= li < ri <= n - 1

## Solution

**Language:** C++  
**Runtime:** 1641 ms (beats 7.09%)  
**Memory:** 419.6 MB (beats 6.26%)  
**Submitted:** 2026-09-05T17:52:27.769Z  

```cpp
class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        
        int block=sqrt(n);

        vector<bool>ans(q,false);

        for(int i=0;i<q;i++){
            queries[i].push_back(i); //store the index
        }

        sort(queries.begin(),queries.end(),[&](auto& a,auto& b){
            int ba=a[0]/block;
            int bb=b[0]/block;
            
            if(ba!=bb) return ba<bb; //re order the queries on the basis least block size at begin
            return a[1]<b[1];        // biggest r at last
        });

        unordered_map<int,int>freq;  //num freq
        int oddfreq=0;
        int currl=0;
        int currr=-1;

        for(int i=0;i<q;i++){
            
            int l=queries[i][0];
            int r=queries[i][1];
            int idx=queries[i][2];

            while(currl>l){ //l move to left
                currl--;
                freq[nums[currl]]++;
                if(freq[nums[currl]]%2==1) oddfreq++;
                else oddfreq--;
            }
            while(currr<r){ //r move to right
                currr++;
                freq[nums[currr]]++;
                if(freq[nums[currr]]%2==1) oddfreq++;
                else oddfreq--;
                
            }
            while(currl<l){
                if(freq[nums[currl]]%2==1) oddfreq--;
                else oddfreq++;
                
                freq[nums[currl]]--;
                if(freq[nums[currl]]==0) freq.erase(nums[currl]);
                currl++;
            }
            while(currr>r){
                if(freq[nums[currr]]%2==1) oddfreq--;
                else oddfreq++;
                
                freq[nums[currr]]--;
                if(freq[nums[currr]]==0) freq.erase(nums[currr]);
                
                currr--;
            }

            if(freq.size()==k && oddfreq==0) ans[idx]=true;
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-k-unique-subarrays-i/)