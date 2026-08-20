# Number of Submatrices That Sum to Target

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a `matrix` and a `target`, return the number of non-empty submatrices that sum to target.

A submatrix `x1, y1, x2, y2` is the set of all cells `matrix[x][y]` with `x1 <= x <= x2` and `y1 <= y <= y2`.

Two submatrices `(x1, y1, x2, y2)` and `(x1', y1', x2', y2')` are different if they have some coordinate that is different: for example, if `x1 != x1'`.

 

 **Example 1:** 

```
Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.

```

 **Example 2:** 

```
Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

```

 **Example 3:** 

```
Input: matrix = [[904]], target = 0
Output: 0

```

 

 **Constraints:** 

- 1 <= matrix.length <= 100
- 1 <= matrix[0].length <= 100
- -1000 <= matrix[i][j] <= 1000
- -10^8 <= target <= 10^8

## Solution

**Language:** C++  
**Runtime:** 486 ms (beats 37.83%)  
**Memory:** 166 MB (beats 40.10%)  
**Submitted:** 2026-08-20T11:10:57.932Z  

```cpp
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        //column compression to evenuall convert into single column
        int n=matrix.size();
        int m=matrix[0].size();
        int cnt=0;

        for(int top=0;top<n;top++){
            vector<int>col(m,0);

            for(int bottom=top;bottom<n;bottom++){
                
                for(int j=0;j<m;j++){
                    col[j]+=matrix[bottom][j];
                }

                unordered_map<int,int>mpp;
                int sum=0;
                mpp[0]=1;

                for(int j=0;j<m;j++){
                    sum+=col[j];
                    int need= sum-target;

                    if(mpp.count(need)){
                        cnt+=mpp[need];
                    }
                    mpp[sum]++;
                }

            }
        }
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/)