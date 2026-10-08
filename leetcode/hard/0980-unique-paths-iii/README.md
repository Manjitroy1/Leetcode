# Unique Paths III

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an `m x n` integer array `grid` where `grid[i][j]` could be:

- 1 representing the starting square. There is exactly one starting square.
- 2 representing the ending square. There is exactly one ending square.
- 0 representing empty squares we can walk over.
- -1 representing obstacles that we cannot walk over.

Return  *the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once*.

 

 **Example 1:** 

```
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

```

 **Example 2:** 

```
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

```

 **Example 3:** 

```
Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 20
- 1 <= m * n <= 20
- -1 <= grid[i][j] <= 2
- There is exactly one starting cell and one ending cell.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 29.17%)  
**Memory:** 9.4 MB (beats 46.24%)  
**Submitted:** 2026-10-08T11:35:02.433Z  

```cpp
class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int total;
    int n;
    int m;
    int fr=-1;
    int fc=-1;
    
    int dfs(int r,int c,int cnt,vector<vector<bool>>&vis){
        if(r==fr && c==fc) return cnt==total;

        vis[r][c]=true;
        int ans=0;
        for(auto d:dir){
            int vr= r+d.first;
            int vc= c+d.second;

            if(vr>=0 && vr<n && vc>=0 && vc<m && !vis[vr][vc]){
                ans+=dfs(vr,vc,1+cnt,vis);
            }
        }
        vis[r][c]=false;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        total = n*m;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        // dir.resize(4);
        
        int sr=-1;
        int sc=-1;
       

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                }else if(grid[i][j]==2){
                    fr=i;
                    fc=j;
                }
                else if(grid[i][j]==-1){
                    vis[i][j]=true;
                    total--;
                }

            }
        }
        return dfs(sr,sc,1,vis);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/unique-paths-iii/)