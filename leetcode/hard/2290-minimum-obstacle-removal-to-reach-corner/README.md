# Minimum Obstacle Removal to Reach Corner

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a  **0-indexed**  2D integer array `grid` of size `m x n`. Each cell has one of two values:

- 0 represents an empty cell,
- 1 represents an obstacle that may be removed.

You can move up, down, left, or right from and to an empty cell.

Return  *the  **minimum**  number of  **obstacles**  to  **remove**  so you can move from the upper left corner* `(0, 0)` *to the lower right corner* `(m - 1, n - 1)`.

 

 **Example 1:** 

```
Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
Output: 2
Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
It can be shown that we need to remove at least 2 obstacles, so we return 2.
Note that there may be other ways to remove 2 obstacles to create a path.

```

 **Example 2:** 

```
Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
Output: 0
Explanation: We can move from (0, 0) to (2, 4) without removing any obstacles, so we return 0.

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 105
- 2 <= m * n <= 105
- grid[i][j] is either 0 or 1.
- grid[0][0] == grid[m - 1][n - 1] == 0

## Solution

**Language:** C++  
**Runtime:** 272 ms (beats 33.50%)  
**Memory:** 109.9 MB (beats 65.90%)  
**Submitted:** 2026-09-26T10:42:30.816Z  

```cpp
class Solution {
public:
    int dijkstra(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        using t=tuple<int,int,int>; //cnt,r,c
        vector<vector<int>>dis(n,vector<int>(m,n*m));

        priority_queue<t,vector<t>,greater<t>>pq;
        // int first= grid[0][0]? 1:0;
        pq.push({0,0,0});
        dis[0][0]=0;
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

        while(!pq.empty()){
            auto [block,r,c]=pq.top();
            pq.pop();

            if(dis[r][c]<block) continue;
            if(r==n-1 && c==m-1) return block;

            for(auto d:dir){
                int vr= r+d.first;
                int vc= c+d.second;
                if(vr>=0 && vr<n && vc>=0 && vc<m){
                    int b= grid[vr][vc]? 1:0;
                    int newblock = block+b;
                    
                    if(dis[vr][vc]>newblock){
                        dis[vr][vc]=newblock;
                        pq.push({newblock,vr,vc});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int ans=dijkstra(grid);
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/)