# Maximum Alternating Subarray Sum With One Deletion

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums`.

You may delete  **at most one**  element from `nums`, then choose a  **subarray**  of the resulting array.

Return the  **maximum**  possible  **alternating sum**  of the chosen subarray.

The  **alternating sum**  of an array is the sum of its elements at even indices minus the sum of its elements at odd indices. The chosen subarray is  **reindexed starting from 0**  before calculating its alternating sum.

 

 **Example 1:** 

 **Input:**  nums = [5,-5,1]

 **Output:**  11

 **Explanation:** 

Choose not to delete an element and select the entire array. Its alternating sum is `5 - (-5) + 1 = 11`, which is the maximum possible.

 **Example 2:** 

 **Input:**  nums = [10,-5,-100]

 **Output:**  110

 **Explanation:** 

Delete `nums[1] = -5` to obtain `[10,-100]`, then select the entire resulting array. Its alternating sum is `10 - (-100) = 110`, which is the maximum possible.

 **Example 3:** 

 **Input:**  nums = [4,7]

 **Output:**  7

 **Explanation:** 

Choose not to delete an element and select the subarray `[7]`. Its alternating sum is 7, which is the maximum possible.

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -105 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 1214 ms (beats 14.52%)  
**Memory:** 422.2 MB (beats 21.51%)  
**Submitted:** 2026-10-15T08:36:37.094Z  

```cpp
#define ll long long
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        // dp[i][parity][deletion used] till index i the max value with 
        //parity begin 0 1 --> next is + and -
        //deletion used --> 0 1 still we did not dele as we can delete at most 1

        //for this i start as a new subarray
        //can be consider for previous value
        //if del ==0 we can now delete this 1
        int n=nums.size();
        ll INF = LLONG_MIN/4;
        ll ans = INF;

        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(2,vector<ll>(2,INF)));
        for(int i=0;i<n;i++){
            dp[i][1][0]=nums[i]; //fresh start of a new subarray

            //we have a prev element only for i>0
            if(i>0){
                for(int p=0;p<2;p++){
                    for(int d=0;d<2;d++){
                        ll prev = dp[i-1][p][d]; //prev maximum value
                        if(prev<=INF) continue; // useless

                        //accoding to the p nums[i] have + or - val
                        ll val = (p==0)? prev + nums[i] : prev -nums[i];

                        //if we take this parity will change
                        dp[i][1-p][d] =max(dp[i][1-p][d], val);

                        //we cal delete alo
                        if(d==0){
                            dp[i][p][1] = max(dp[i][p][1], prev);
                        }
                    }
                }
            }
            //

            //the answer can be at any index
            for(int p=0;p<2;p++){
                for(int d=0;d<2;d++){
                    ans = max(ans,dp[i][p][d]);
                }
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-alternating-subarray-sum-with-one-deletion/)