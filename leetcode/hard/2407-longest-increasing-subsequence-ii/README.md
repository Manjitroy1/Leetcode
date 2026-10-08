# Longest Increasing Subsequence II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` and an integer `k`.

Find the longest subsequence of `nums` that meets the following requirements:

- The subsequence is strictly increasing and
- The difference between adjacent elements in the subsequence is at most k.

Return *the length of the  **longest**   **subsequence**  that meets the requirements.* 

A  **subsequence**  is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

 **Example 1:** 

```
Input: nums = [4,2,1,4,3,4,5,8,15], k = 3
Output: 5
Explanation:
The longest subsequence that meets the requirements is [1,3,4,5,8].
The subsequence has a length of 5, so we return 5.
Note that the subsequence [1,3,4,5,8,15] does not meet the requirements because 15 - 8 = 7 is larger than 3.

```

 **Example 2:** 

```
Input: nums = [7,4,5,1,8,12,4,7], k = 5
Output: 4
Explanation:
The longest subsequence that meets the requirements is [4,5,8,12].
The subsequence has a length of 4, so we return 4.

```

 **Example 3:** 

```
Input: nums = [1,5], k = 1
Output: 1
Explanation:
The longest subsequence that meets the requirements is [1].
The subsequence has a length of 1, so we return 1.

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i], k <= 105

## Solution

**Language:** C++  
**Runtime:** 107 ms (beats 33.11%)  
**Memory:** 195.9 MB (beats 6.94%)  
**Submitted:** 2026-10-08T09:59:05.988Z  

```cpp
class SGT{
public:
    vector<int>sgt;
    int h;
    
    SGT(int n){
        h = n;
        sgt.resize(4*n+1);
    }

    void update(int idx,int low,int high,int pos,int val){
        if(low==high){
            sgt[idx]=val;
            return;
        }
        int mid= low+ (high-low)/2;
        if(pos<=mid) update(2*idx+1,low,mid,pos,val);
        else update(2*idx+2,mid+1,high,pos,val);

        sgt[idx] = max(sgt[2*idx+1],sgt[2*idx+2]);
    }
    int query(int idx, int low,int high,int l,int r){
        //no overlap low high l r .... l r low high
        if(high<l || r<low) return -1e9;
        
        //complete l  low high r
        if(l<=low && high<=r){
            return sgt[idx];
        }
        int mid= low+ (high-low)/2;
        int left= query(2*idx+1, low, mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);

        return max(left,right);
    }
    void update(int pos,int val){
        update(0,0,h-1,pos,val);

    }
    int query(int l,int r){
        return query(0,0,h-1,l,r);
    }
};
class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,1);
        
        int ans=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && nums[i] - nums[j] <= k && dp[i] < 1+dp[j]){
                    dp[i] = 1+ dp[j];
                    ans= max(ans,dp[i]);
                }
            }
        }
        return ans;
    }

    //using segment tree we can get maximum value in that range
    int lengthOfLIS(vector<int>& nums, int k) {
        int n=nums.size();
        int total = 1e5+1;
        SGT first(total);

        vector<int>dp(n,0);
        int ans=1;
        for(int i=0;i<n;i++){
            int v= nums[i];

            int left= max(0,v-k);
            int right = v-1;
            int mx= first.query(left,right); //maximum value in this range

            if(dp[i] < 1+mx){
                dp[i]= 1+mx;
                ans= max(ans,dp[i]);
                first.update(v,dp[i]);
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-increasing-subsequence-ii/)