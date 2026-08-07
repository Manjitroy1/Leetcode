# Number of Squareful Arrays

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

An array is  **squareful**  if the sum of every pair of adjacent elements is a  **perfect square**.

Given an integer array nums, return  *the number of permutations of* `nums` *that are  **squareful***.

Two permutations `perm1` and `perm2` are different if there is some index `i` such that `perm1[i] != perm2[i]`.

 

 **Example 1:** 

```
Input: nums = [1,17,8]
Output: 2
Explanation: [1,8,17] and [17,8,1] are the valid permutations.

```

 **Example 2:** 

```
Input: nums = [2,2,2]
Output: 1

```

 

 **Constraints:** 

- 1 <= nums.length <= 12
- 0 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10.2 MB (beats 54.14%)  
**Submitted:** 2026-08-07T10:09:39.207Z  

```cpp
class Solution {
public:
    int cnt=0;
    bool sq(int val){
        int q= sqrt(val);
       return q*q==val;
    }
    // bool func(vector<int>&nums){
    //     int n=nums.size();
    //     for(int i=0;i<n-1;i++){
    //         if(!sq(nums[i]+nums[i+1])){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // int solve(vector<int>& nums) {
    //     int cnt=0;
    //     sort(nums.begin(),nums.end());
    //     do{
    //         if(func(nums)) cnt++;
    //     }while(next_permutation(nums.begin(),nums.end()));

    //     return cnt;
    // }
void recc(int curr, vector<int>& nums) {
    if(curr == nums.size()) {
        cnt++;
        return;
    }

    unordered_set<int> used;

    for(int i = curr; i < nums.size(); i++) {

        if(used.count(nums[i])) continue;
        used.insert(nums[i]);

        swap(nums[curr], nums[i]);

        if(curr == 0 || sq(nums[curr-1] + nums[curr]))
            recc(curr + 1, nums);

        swap(nums[curr], nums[i]);
    }
}

void help(int curr,vector<int> arr){
        if(curr>= arr.size()){
            cnt++;
            return ;
        }
        for(int i= curr;i<arr.size();i++){
            if(i== curr || arr[i]!= arr[curr]){
                swap(arr[curr],arr[i]);
                if(curr==0 || (curr>0 && sq(arr[curr-1]+arr[curr]))) help(curr+1,arr);
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
    //    return solve(nums);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // recc(0,nums); 
        help(0,nums);
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-squareful-arrays/)