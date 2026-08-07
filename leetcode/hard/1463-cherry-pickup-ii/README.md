# Cherry Pickup II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a `rows x cols` matrix `grid` representing a field of cherries where `grid[i][j]` represents the number of cherries that you can collect from the `(i, j)` cell.

You have two robots that can collect cherries for you:

- Robot #1 is located at the top-left corner (0, 0), and
- Robot #2 is located at the top-right corner (0, cols - 1).

Return  *the maximum number of cherries collection using both robots by following the rules below* :

- From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
- When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
- When both robots stay in the same cell, only one takes the cherries.
- Both robots cannot move outside of the grid at any moment.
- Both robots should reach the bottom row in grid.

 

 **Example 1:** 

```
Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.

```

 **Example 2:** 

```
Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.

```

 

 **Constraints:** 

- rows == grid.length
- cols == grid[i].length
- 2 <= rows, cols <= 70
- 0 <= grid[i][j] <= 100

## Solution

**Language:** C++  
**Runtime:** 39 ms (beats 81.56%)  
**Memory:** 13.8 MB (beats 89.35%)  
**Submitted:** 2026-08-07T17:45:31.246Z  

```cpp
class Solution {
public:
    int dp[71][71][71];
    int solve(int j1,int j2, int i, vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();

        if(i>=n) return 0;
        if(j1<0 || j1>=m || j2<0 || j2>=m) return 0;

        if(dp[j1][j2][i]!=-1) return dp[j1][j2][i];
        
        int ans=0;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                int nj1=j1+d1;
                int nj2=j2+d2;

                // if(issafe(nj1,nj2)){
                    if(j1==j2){
                        ans= max(ans, grid[i][j1] + solve(nj1,nj2,i+1,grid));
                    }else{
                        ans =max(ans, grid[i][j1]+ grid[i][j2] + solve(nj1,nj2,i+1,grid));
                    }
                // }
            }
        }
        return dp[j1][j2][i] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,m-1,0,grid);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/cherry-pickup-ii/)