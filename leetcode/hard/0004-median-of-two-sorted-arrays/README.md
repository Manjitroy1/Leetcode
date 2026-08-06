# Median of Two Sorted Arrays

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return  **the median**  of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

 

 **Example 1:** 

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

```

 **Example 2:** 

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

```

 

 **Constraints:** 

- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -106 <= nums1[i], nums2[i] <= 106

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 95 MB (beats 80.16%)  
**Submitted:** 2026-08-06T14:08:15.892Z  

```cpp
class Solution {
public:
    double binary(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();  // i want n to be small to operate in nums1
        int m=nums2.size();
        if(n>m) return binary(nums2,nums1);
        double ans=0.0;

        int l=0;
        int h=n;
        int left = (n+m+1)/2;

        while(l<=h){
            int mid1= l + (h-l)/2;
            int mid2= left - mid1;

            int l1 = mid1-1 >=0 ? nums1[mid1-1]: INT_MIN;
            int l2=  mid2-1 >=0 ?  nums2[mid2-1] : INT_MIN;

            int r1 = mid1 < n ? nums1[mid1]: INT_MAX;
            int r2= mid2 < m ? nums2[mid2]: INT_MAX;

            if(l1<=r2 && l2<=r1){
                if((n+m) % 2==1){
                    ans= max(l1,l2);
                }else{
                    ans= (max(l1,l2)+ min(r1,r2))/2.0;
                }
                return ans;
            }else if(l2>r1){
                l=mid1+1;
            }else{
                h=mid1-1;
            }

        }
        return ans;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return binary(nums1,nums2);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/median-of-two-sorted-arrays/)