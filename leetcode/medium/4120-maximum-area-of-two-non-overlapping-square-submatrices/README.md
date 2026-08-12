# Q3. Maximum Area of Two Non-Overlapping Square Submatrices

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a 2D integer matrix `mat` of size `m × n`, where:

- mat[r][c] == 1 means the cell at row r and column c is usable.
- mat[r][c] == 0 means it is not usable.

Your task is to find  **two submatrices**  that satisfy the following conditions:

- Both submatrices must be squares of the same side length k.
- The two submatrices must not share any cell.
- Each submatrix can only cover cells where mat[r][c] == 1.

Return the  **maximum possible area**  of each of the two squares. If it is not possible to choose two such squares, return 0.

 

 **Example 1:** 

 **Input:**  mat = [[1,1,1,0],[1,1,1,1],[0,0,1,1]]

 **Output:**  4

 **Explanation:** 

The largest equal non-overlapping squares have side length `k = 2` with area 4.

- First square starts at top-left (0, 0) and covers cells (0, 0), (0, 1), (1, 0), and (1, 1).
- Second square starts at top-left (1, 2) and covers cells (1, 2), (1, 3), (2, 2), and (2, 3).

Thus, the answer is 4.

 **Example 2:** 

 **Input:**  mat = [[0,1],[1,0]]

 **Output:**  1

 **Explanation:** 

The largest equal non-overlapping squares have side length `k = 1` with area 1.

- First square starts at top-left (0, 1) and covers cell (0, 1).
- Second square starts at top-left (1, 0) and covers cell (1, 0).

Thus, the answer is 1.

 **Example 3:** 

 **Input:**  mat = [[0,0],[0,1]]

 **Output:**  0

 **Explanation:** 

There is only one usable cell, so it is impossible to choose two non-overlapping squares. Thus, the answer is 0.

 

 **Constraints:** 

- mat.length == m
- mat[i].length == n
- 1 <= m, n <= 500
- mat[i][j] is either 0 or 1.

## Solution

**Language:** C++  
**Runtime:** 84 ms (beats 65.34%)  
**Memory:** 139 MB (beats 28.89%)  
**Submitted:** 2026-08-12T18:38:50.114Z  

```cpp
class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // up[i][j] = largest square ending at (i,j)
        vector<vector<int>> up(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0)
                    continue;

                if (i == 0 || j == 0) {
                    up[i][j] = 1;
                }
                else {
                    up[i][j] = 1 + min({
                        up[i-1][j],
                        up[i][j-1],
                        up[i-1][j-1]
                    });
                }
            }
        }

        // down[i][j] = largest square starting at (i,j)
        vector<vector<int>> down(n, vector<int>(m, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (mat[i][j] == 0)
                    continue;

                if (i == n - 1 || j == m - 1) {
                    down[i][j] = 1;
                }
                else {
                    down[i][j] = 1 + min({
                        down[i+1][j],
                        down[i][j+1],
                        down[i+1][j+1]
                    });
                }
            }
        }

        int ans = 0;

        /*
            CASE 1:
            Two squares are separated vertically.

            left square  | right square
                         |
        */

        vector<int> left(m, 0);
        vector<int> right(m, 0);

        // Largest square completely contained in columns [0 ... j]
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                left[j] = max(left[j], up[i][j]);
            }

            if (j > 0)
                left[j] = max(left[j], left[j-1]);
        }

        // Largest square completely contained in columns [j ... m-1]
        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                right[j] = max(right[j], down[i][j]);
            }

            if (j + 1 < m)
                right[j] = max(right[j], right[j+1]);
        }

        // Split between j and j+1
        for (int j = 0; j < m - 1; j++) {
            int k = min(left[j], right[j+1]);
            ans = max(ans, k);
        }


        /*
            CASE 2:
            Two squares are separated horizontally.

            top
            ---
            bottom
        */

        vector<int> top(n, 0);
        vector<int> bottom(n, 0);

        // Largest square completely contained in rows [0 ... i]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                top[i] = max(top[i], up[i][j]);
            }

            if (i > 0)
                top[i] = max(top[i], top[i-1]);
        }

        // Largest square completely contained in rows [i ... n-1]
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                bottom[i] = max(bottom[i], down[i][j]);
            }

            if (i + 1 < n)
                bottom[i] = max(bottom[i], bottom[i+1]);
        }

        // Split between i and i+1
        for (int i = 0; i < n - 1; i++) {
            int k = min(top[i], bottom[i+1]);
            ans = max(ans, k);
        }

        return ans * ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-area-of-two-non-overlapping-square-submatrices/)