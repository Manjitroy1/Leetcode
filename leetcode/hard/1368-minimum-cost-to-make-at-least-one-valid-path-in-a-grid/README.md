# Minimum Cost to Make at Least One Valid Path in a Grid

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an `m x n` grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of `grid[i][j]` can be:

- 1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
- 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
- 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
- 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])

Notice that there could be some signs on the cells of the grid that point outside the grid.

You will initially start at the upper left cell `(0, 0)`. A valid path in the grid is a path that starts from the upper left cell `(0, 0)` and ends at the bottom-right cell `(m - 1, n - 1)` following the signs on the grid. The valid path does not have to be the shortest.

You can modify the sign on a cell with `cost = 1`. You can modify the sign on a cell  **one time only**.

Return  *the minimum cost to make the grid have at least one valid path*.

 

 **Example 1:** 

```
Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
The total cost = 3.

```

 **Example 2:** 

```
Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
Output: 0
Explanation: You can follow the path from (0, 0) to (2, 2).

```

 **Example 3:** 

```
Input: grid = [[1,2],[4,3]]
Output: 1

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 100
- 1 <= grid[i][j] <= 4

## Solution

**Language:** C++  
**Runtime:** 16 ms (beats 64.16%)  
**Memory:** 26.1 MB (beats 46.47%)  
**Submitted:** 2026-09-26T17:34:16.681Z  

```cpp
class Solution {
public:
    int n;
    int m;

    int dijks01(vector<vector<int>>& grid){
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;

        vector<pair<int,int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};

        using p=pair<int,int>;

        deque<p>dq;
        dq.push_front({0,0});

        while(!dq.empty()){
            auto [r,c]=dq.front();
            dq.pop_front();
            
            if(r==n-1 && c==m-1) return dis[r][c];

            for(int i=0;i<dir.size();i++){
                int vr=r+dir[i].first;
                int vc=c+dir[i].second;

                if(vr<0 || vr>=n || vc<0 || vc>=m) continue;

                int cost= (grid[r][c]==1+i)? 0 : 1;

                int newdis=dis[r][c]+cost;
                if(dis[vr][vc]>newdis){

                    dis[vr][vc]=newdis;
                    if(cost){
                        dq.push_back({vr,vc});
                    }else{
                        dq.push_front({vr,vc});
                    }
                }
            }
        }
        return dis[n-1][m-1];

    }
    int minCost(vector<vector<int>>& grid) {
        //cost =0 if same dir 1 if change dir
        n=grid.size();
        m=grid[0].size();

        int ans=dijks01(grid);
        return ans;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)