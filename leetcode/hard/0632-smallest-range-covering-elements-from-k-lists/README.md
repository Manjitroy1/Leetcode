# Smallest Range Covering Elements from K Lists

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You have `k` lists of sorted integers in  **non-decreasing order**. Find the  **smallest**  range that includes at least one number from each of the `k` lists.

We define the range `[a, b]` is smaller than range `[c, d]` if `b - a < d - c`  **or**  `a < c` if `b - a == d - c`.

 

 **Example 1:** 

```
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

```

 **Example 2:** 

```
Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

```

 

 **Constraints:** 

- nums.length == k
- 1 <= k <= 3500
- 1 <= nums[i].length <= 50
- -105 <= nums[i][j] <= 105
- nums[i] is sorted in non-decreasing order.

## Solution

**Language:** C++  
**Runtime:** 75 ms (beats 69.69%)  
**Memory:** 37.9 MB (beats 60.69%)  
**Submitted:** 2026-08-20T08:59:11.426Z  

```cpp
class Solution {
public:

    bool check(int l, int& mid, vector<vector<int>>& nums) {

        mid = INT_MIN;

        for (const auto& vec : nums) {

            auto it = lower_bound(vec.begin(), vec.end(), l);

            if (it == vec.end()) {
                return false;
            }

            mid = max(mid, *it);
        }

        return true;
    }

    vector<int>better(vector<vector<int>>& nums) {

        int l = INT_MAX;
        int h = INT_MIN;

        for (const auto& vec : nums) {
            l = min(l, vec[0]);

            int n = vec.size();
            h = max(h, vec[n - 1]);
        }

        int a = l;
        int b = h;

        // Try every possible left endpoint
        for (l = l; l <= h; l++) {

            int mid;
            //the check funciton will mid update via check to auto adjust

            if (check(l, mid, nums)) {

                if (mid - l < b - a) {
                    a = l;
                    b = mid;
                }
                else if (mid - l == b - a) {

                    if (l < a) {
                        a = l;
                        b = mid;
                    }
                }
            }
        }

        return {a, b};
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        // return better(nums); //tle
        using t=tuple<int,int,int>;  //value,ith vec, index of ith vec
        priority_queue<t,vector<t>,greater<t>>pq;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i][0]);
            pq.push({nums[i][0],i,0});
        }
        auto [x,idx,p]=pq.top();
        int a=x;
        int b=mx;

        while(true){
            auto [val,i,pos]= pq.top();
            pq.pop();

            if(mx-val < b-a){
                a=val;
                b=mx;
            }
            if(pos+1>= nums[i].size()) break;
            pq.push({nums[i][pos+1],i,pos+1});
            mx=max(mx,nums[i][pos+1]);
        }
        return {a,b};
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)