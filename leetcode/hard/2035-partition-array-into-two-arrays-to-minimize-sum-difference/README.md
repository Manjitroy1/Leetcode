# Partition Array Into Two Arrays to Minimize Sum Difference

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` of `2 * n` integers. You need to partition `nums` into  **two**  arrays of length `n` to  **minimize the absolute difference**  of the  **sums**  of the arrays. To partition `nums`, put each element of `nums` into  **one**  of the two arrays.

Return  *the  **minimum**  possible absolute difference*.

 

 **Example 1:** 

```
Input: nums = [3,9,7,3]
Output: 2
Explanation: One optimal partition is: [3,9] and [7,3].
The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.

```

 **Example 2:** 

```
Input: nums = [-36,36]
Output: 72
Explanation: One optimal partition is: [-36] and [36].
The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.

```

 **Example 3:** 

```
Input: nums = [2,-1,0,4,-2,-9]
Output: 0
Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.

```

 

 **Constraints:** 

- 1 <= n <= 15
- nums.length == 2 * n
- -107 <= nums[i] <= 107

## Solution

**Language:** C++  
**Runtime:** 391 ms (beats 50.77%)  
**Memory:** 73.4 MB (beats 57.22%)  
**Submitted:** 2026-08-02T14:37:10.050Z  

```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        // left[k] = all possible sums by choosing k elements from left half
        // right[k] = all possible sums by choosing k elements from right half
        vector<vector<int>> left(half + 1), right(half + 1);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Generate all subset sums
        for (int mask = 0; mask < (1 << half); mask++) {
            int cnt = 0;
            int leftSum = 0;
            int rightSum = 0;

            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    leftSum += nums[i];
                    rightSum += nums[i + half];
                }
            }

            left[cnt].push_back(leftSum);
            right[cnt].push_back(rightSum);
        }

        // Sort all right subset sums
        for (int i = 1; i <= half; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        // Choose i elements from left and half-i from right
        for (int i = 1; i <= half; i++) {

            int need = half - i;

            for (int leftSum : left[i]) {

                double target = totalSum / 2.0 - leftSum;

                auto &vec = right[need];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int chosen = leftSum + *it;
                    ans = min(ans, abs(totalSum - 2 * chosen));
                }

                if (it != vec.begin()) {
                    --it;
                    int chosen = leftSum + *it;
                    ans = min(ans, abs(totalSum - 2 * chosen));
                }
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/)