# Q4. Minimum Cost Path With At Most K Turns

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a 2D integer array `grid` of size `m x n`, where `grid[i][j]` represents the cost of visiting cell `(i, j)`, and an integer `k`.

You start at the  **top-left**  cell `(0, 0)` and want to reach the  **bottom-right**  cell `(m - 1, n - 1)`.

From each cell, you may move one step in any of the four directions:  **up**,  **down**,  **left**, or  **right**.

The cost of a path is the sum of the values of all visited cells,  **including**  the starting and ending cells. If a cell is visited more than once, its value is included each time it is visited.

Return the  **minimum**  possible path cost to reach `(m - 1, n - 1)` using  **at most**  `k` turns. If no such path exists, return `-1`.

A  **turn**  occurs when the direction changes between two consecutive moves. For example, moving right and then down counts as one turn, while moving right and then right does not.

 

 **Example 1:** 

 **Input:**  grid = [[2,7,3],[1,4,5]], k = 1

 **Output:**  12

 **Explanation:** 

- An optimal path is (0, 0) → (1, 0) → (1, 1) → (1, 2). The moves are down, right, right.
- The direction changes from down to right once, so the path uses exactly k = 1 turn.
- The total path cost is 2 + 1 + 4 + 5 = 12.

 **Example 2:** 

 **Input:**  grid = [[4,1,9],[3,2,5],[4,8,6]], k = 2

 **Output:**  20

 **Explanation:** ​​​​​​​

- An optimal path is (0, 0) → (1, 0) → (1, 1) → (1, 2) → (2, 2). The moves are down, right, right, down.
- The direction changes from down to right and from right to down, so the path uses exactly k = 2 turns.
- The total path cost is 4 + 3 + 2 + 5 + 6 = 20.

 **Example 3:** 

 **Input:**  grid = [[1,9],[3,4]], k = 0

 **Output:**  -1

 **Explanation:** 

- It is impossible to reach (1, 1) using k = 0 turns. Thus, the answer is -1.

 

 **Constraints:** 

- 1 <= m == grid.length <= 75
- 1 <= n == grid[i].length <= 75
- 0 <= grid[i][j] <= 1000
- 0 <= k < min(m, n)

## Solution

**Language:** C++  
**Runtime:** 511 ms (beats 67.88%)  
**Memory:** 85.6 MB (beats 61.20%)  
**Submitted:** 2026-09-06T10:52:33.518Z  

```cpp
class Solution {
public:
    struct Node{
        int cost;
        int moves;
        int d;
        int r;
        int c;
    };
    int solve(vector<vector<int>>& grid,vector<pair<int,int>>&direction,int k){
        int n=grid.size();
        int m=grid[0].size();
        // int dis[][][][] r c d moves = store the min cost
        vector<vector<vector<vector<int>>>>dis(n+1,
                vector<vector<vector<int>>>(m+1,
                        vector<vector<int>>(4,
                                vector<int>(k+1,INT_MAX))));

        auto cmp= [](const Node& a,const Node& b){
            return a.cost>b.cost;
        };

        priority_queue<Node,vector<Node>, decltype(cmp)>pq(cmp); //min cost at first

        //first push special case
        for(int dir=0;dir<4;dir++){
            int vr=direction[dir].first;
            int vc=direction[dir].second;
            if(vr<0 || vr>=n || vc<0 || vc>=m) continue;
            
            int cost=grid[0][0]+ grid[vr][vc];
            dis[vr][vc][dir][0]= cost;
            
            pq.push({cost,0,dir,vr,vc});
        }

        while(!pq.empty()){
            auto node= pq.top();
            pq.pop();
            //currently i am at this node
            int cost=node.cost;
            int moves=node.moves;
            int d=node.d;
            int r=node.r;
            int c=node.c;


            if(moves>k) continue;
            if(r==n-1 && c==m-1) return cost;
            
            if(cost!=dis[r][c][d][moves]) continue;

            for(int dir=0;dir<4;dir++){
                int vr=r+ direction[dir].first;
                int vc=c+ direction[dir].second;
                if(vr<0 || vr>=n || vc<0 || vc>=m) continue;

                int newmoves=moves;
                if(d!=dir){
                    newmoves++;
                }
                if(newmoves>k) continue;
                
                int newcost=cost+grid[vr][vc];
                if(newcost<dis[vr][vc][dir][newmoves]){
                    dis[vr][vc][dir][newmoves]=newcost;
                    pq.push({newcost,newmoves,dir,vr,vc});
                }
            }            
        }
        return -1;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1) return grid[0][0];
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}}; //left right down up
        int ans = solve(grid,dir,k);
        
        return ans;
    }
    
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-cost-path-with-at-most-k-turns/)