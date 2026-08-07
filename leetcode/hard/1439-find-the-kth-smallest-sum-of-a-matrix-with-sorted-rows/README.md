# Find the Kth Smallest Sum of a Matrix With Sorted Rows

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an `m x n` matrix `mat` that has its rows sorted in non-decreasing order and an integer `k`.

You are allowed to choose  **exactly one element**  from each row to form an array.

Return  *the* `kth` *smallest array sum among all possible arrays*.

 

 **Example 1:** 

```
Input: mat = [[1,3,11],[2,4,6]], k = 5
Output: 7
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.

```

 **Example 2:** 

```
Input: mat = [[1,3,11],[2,4,6]], k = 9
Output: 17

```

 **Example 3:** 

```
Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
Output: 9
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  

```

 

 **Constraints:** 

- m == mat.length
- n == mat.length[i]
- 1 <= m, n <= 40
- 1 <= mat[i][j] <= 5000
- 1 <= k <= min(200, nm)
- mat[i] is a non-decreasing array.

## Solution

**Language:** C++  
**Runtime:** 106 ms (beats 48.25%)  
**Memory:** 37.6 MB (beats 49.18%)  
**Submitted:** 2026-08-07T11:15:45.545Z  

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> curr = mat[0];
        if (curr.size() > k)
            curr.resize(k);

        for (int i = 1; i < m; i++) {
            vector<int> temp;

            // Merge current smallest sums with the current row
            for (int sum : curr) {
                for (int j = 0; j < n; j++) {
                    temp.push_back(sum + mat[i][j]);
                }
            }

            sort(temp.begin(), temp.end());

            // Keep only the first k smallest sums
            if (temp.size() > k)
                temp.resize(k);

            curr = temp;
        }

        return curr[k - 1];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/)