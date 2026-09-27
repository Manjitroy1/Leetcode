# Stamping the Grid

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an `m x n` binary matrix `grid` where each cell is either `0` (empty) or `1` (occupied).

You are then given stamps of size `stampHeight x stampWidth`. We want to fit the stamps such that they follow the given  **restrictions**  and  **requirements** :

- Cover all the empty cells.
- Do not cover any of the occupied cells.
- We can put as many stamps as we want.
- Stamps can overlap with each other.
- Stamps are not allowed to be rotated.
- Stamps must stay completely inside the grid.

Return `true`  *if it is possible to fit the stamps while following the given restrictions and requirements. Otherwise, return*  `false`.

 

 **Example 1:** 

```
Input: grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
Output: true
Explanation: We have two overlapping stamps (labeled 1 and 2 in the image) that are able to cover all the empty cells.

```

 **Example 2:** 

```
Input: grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2 
Output: false 
Explanation: There is no way to fit the stamps onto all the empty cells without the stamps going outside the grid.

```

 

 **Constraints:** 

- m == grid.length
- n == grid[r].length
- 1 <= m, n <= 105
- 1 <= m  *n <= 2*  105
- grid[r][c] is either 0 or 1.
- 1 <= stampHeight, stampWidth <= 105

## Solution

**Language:** C++  
**Runtime:** 117 ms (beats 66.14%)  
**Memory:** 186.7 MB (beats 55.12%)  
**Submitted:** 2026-09-27T17:24:11.119Z  

```cpp
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
        //can we stamp at top left cell
        //check the whole rectangle
        //if the whole rectangle has no 1's then we can
        //which can be calculated using pre comuting of presum
        int n=grid.size();
        int m=grid[0].size();
        // presum[i+1][j+1] represent 0,0 to i j rectagle total 1's in grid
        vector<vector<int>>presum(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                presum[i+1][j+1]= grid[i][j] + presum[i+1][j]+presum[i][j+1] - presum[i][j];
            }
        }

        //if we are able to fit an stamp
        //we have mark all, so we will +- difference array
        vector<vector<int>>diff(n+1,vector<int>(m+1,0));
        //at end prefum
        // i,j represetns starting cell of the stamp of h and w we create a box
        for(int i=0;i+h<=n;i++){
            for(int j=0;j+w<=m;j++){    
                int r=i+h;
                int c=j+w;

                int total = presum[r][c]-presum[r][j]-presum[i][c]+presum[i][j];
                if(total==0){
                    diff[i][j]++;
                    diff[i][c]--;
                    diff[r][j]--;
                    diff[r][c]++;
                }
                //created the diff array
            }
        }

        //is any cell of grid is zero have colletion is also 0 return -1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0) diff[i][j]+=diff[i-1][j];
                if(j>0) diff[i][j]+=diff[i][j-1];
                if(i>0 && j>0) diff[i][j]-=diff[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(diff[i][j]==0 && grid[i][j]==0){
                    return false;
                }
            }
        }
        return true;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/stamping-the-grid/)