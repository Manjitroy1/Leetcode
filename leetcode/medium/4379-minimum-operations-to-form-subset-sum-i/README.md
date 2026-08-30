# Q3. Minimum Operations to Form Subset Sum I

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` and an integer `sum`.

In one  **operation**, choose an element with current value `x` and replace it with either `2 * x` or `floor(x / 2)`.

For each element, all  **multiplication**  operations performed on it must occur  **before**  any  **division**  operations performed on it.

Return the  **minimum**  number of operations needed so that some subset of the resulting array has a sum  **exactly**  equal to `sum`. If it is impossible, return -1.

The `floor()` function returns the integer part of the division.

 

 **Example 1:** 

 **Input:**  nums = [5,6,10], sum = 4

 **Output:**  3

 **Explanation:** 

- Divide nums[0] = 5 twice: 5 → 2 → 1, costing 2 operations.
- Divide nums[1] = 6 once: 6 → 3, costing 1 operation.
- After these operations, nums = [1, 3, 10]. The subset {1, 3} sums to 4 using 3 operations in total.

 **Example 2:** 

 **Input:**  nums = [10,2], sum = 13

 **Output:**  3

 **Explanation:** 

- Divide nums[0] = 10 once: 10 → 5, costing 1 operation.
- Multiply nums[1] = 2 twice: 2 → 4 → 8, costing 2 operations.
- After these operations, nums = [5, 8]. The subset {5, 8} sums to 13 using 3 operations in total.

 **Example 3:** 

 **Input:**  nums = [6,3], sum = 8

 **Output:**  -1

 **Explanation:** ​​​​​​​

- No sequence of operations lets a subset of nums sum to 8, so the answer is -1.

 

 **Constraints:** 

- 1 <= nums.length <= 100
- 1 <= nums[i] <= 500
- 1 <= sum <= 5000

## Solution

**Language:** C++  
**Runtime:** 2231 ms (beats 5.02%)  
**Memory:** 366.2 MB (beats 5.02%)  
**Submitted:** 2026-08-30T10:27:29.872Z  

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        //for each number 
        //we will have this possibility 
        //check for other possibility
        //store the minimum
        
        unordered_map<int,int>dp;
        dp[0]=0;
        
        for(int i=0;i<n;i++){
            int num=nums[i];

            unordered_map<int,int>newdp;
            //currect must inlcude the previous also
            newdp=dp;
            
            //what we already have
            for(auto node:dp){
                int s=node.first;
                int step=node.second;

                //use num as it is
                int total = s+num;
                if(total<=sum){
                    int tillstep = newdp.count(total)? newdp[total]:1e9;
                    newdp[total] = min(tillstep,step);
                }
                
                //multiply
                int scount=0;
                long long curr=nums[i];
                while(curr*2<=sum){
                    
                    curr*=2;
                    scount++;
                    
                    long long newval = curr+s;
                    if(newval<=sum){
                        int tillstep = newdp.count(newval)? newdp[newval]:1e9;
                        newdp[newval]=min(tillstep,step+scount);
                    }
                    
                }
                //devide
                curr=nums[i];
                scount=0;
                while(curr/2 >=1){
                    curr/=2;
                    scount++;
                    int newval = curr+s;
                    if(newval<=sum){
                        int tillstep = newdp.count(newval)? newdp[newval]:1e9;
                        newdp[newval]=min(tillstep,step+scount);
                    }
                }
            }
            dp=newdp;
        }
        if(!dp.count(sum)) return -1;

        return dp[sum];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-operations-to-form-subset-sum-i/)