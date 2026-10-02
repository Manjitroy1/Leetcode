# Number of Subsequences That Satisfy the Given Sum Condition

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array of integers `nums` and an integer `target`.

Return  *the number of  **non-empty**  subsequences of* `nums` *such that the sum of the minimum and maximum element on it is less or equal to* `target`. Since the answer may be too large, return it  **modulo**  `109 + 7`.

 

 **Example 1:** 

```
Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)

```

 **Example 2:** 

```
Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3], [3], [3,3], [3,6], [3,6], [3,3,6]

```

 **Example 3:** 

```
Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 106
- 1 <= target <= 106

## Solution

**Language:** C++  
**Runtime:** 24 ms (beats 92.98%)  
**Memory:** 56.3 MB (beats 5.19%)  
**Submitted:** 2026-10-02T09:55:17.155Z  

```cpp
class Solution {
public:
    const int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        if(nums[0]>target) return 0;
        long long ans=0;
        int i=0;
        int j=n-1;

        while(j>=0 && nums[j]>target){
            j--;
        }
        vector<long long>pow2(n);
        pow2[0]=1;        
        for(int i=1;i<n;i++){
            pow2[i]=(pow2[i-1]*2) % mod;
        }
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                int len=j-i;
                // for(int l=1;l<=len;l++){
                //     p= (p*2) % mod;
                // }

                //we have to precompute

                ans = (ans + pow2[len]) % mod;
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/)