# GCD Sort of an Array

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums`, and you can perform the following operation  **any**  number of times on `nums`:

- Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], nums[j]) > 1 where gcd(nums[i], nums[j]) is the greatest common divisor of nums[i] and nums[j].

Return `true`  *if it is possible to sort* `nums` *in  **non-decreasing**  order using the above swap method, or* `false` *otherwise.* 

 

 **Example 1:** 

```
Input: nums = [7,21,3]
Output: true
Explanation: We can sort [7,21,3] by performing the following operations:
- Swap 7 and 21 because gcd(7,21) = 7. nums = [21,7,3]
- Swap 21 and 3 because gcd(21,3) = 3. nums = [3,7,21]

```

 **Example 2:** 

```
Input: nums = [5,2,6,2]
Output: false
Explanation: It is impossible to sort the array because 5 cannot be swapped with any other element.

```

 **Example 3:** 

```
Input: nums = [10,5,9,3,15]
Output: true
We can sort [10,5,9,3,15] by performing the following operations:
- Swap 10 and 15 because gcd(10,15) = 5. nums = [15,5,9,3,10]
- Swap 15 and 3 because gcd(15,3) = 3. nums = [3,5,9,15,10]
- Swap 10 and 15 because gcd(10,15) = 5. nums = [3,5,9,10,15]

```

 

 **Constraints:** 

- 1 <= nums.length <= 3 * 104
- 2 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 407 ms (beats 18.85%)  
**Memory:** 66.9 MB (beats 82.29%)  
**Submitted:** 2026-08-11T10:31:07.688Z  

```cpp
class Solution {
public:
    vector<int>parent;
    vector<int>size;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u,int v){
        int up=find(u);
        int vp=find(v);
        if(up==vp) return;
        if(size[up] < size[vp]) swap(up,vp);

        size[up]+=size[vp];
        parent[vp]=up;
        return;
    }
    bool gcdSort(vector<int>& nums) {
        vector<int>nums2(nums);
        sort(nums2.begin(),nums2.end());

        int n=nums.size();
        int mx=nums2[n-1];

        parent.resize(mx+1,0);
        size.resize(mx+1,1);

        for(int i=1;i<=mx;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=2;j<=sqrt(nums[i]);j++){
                if(nums[i]%j==0){
                    unite(nums[i],j);
                    unite(nums[i], nums[i]/j);
                }
            }
        }

        for(int i=0;i<n;i++){
            if( find(nums[i]) != find(nums2[i]) ) return false;
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/gcd-sort-of-an-array/)