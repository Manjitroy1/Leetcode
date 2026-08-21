# Dungeon Game

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

The demons had captured the princess and imprisoned her in  **the bottom-right corner**  of a `dungeon`. The `dungeon` consists of `m x n` rooms laid out in a 2D grid. Our valiant knight was initially positioned in  **the top-left room**  and must fight his way through `dungeon` to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to `0` or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only  **rightward**  or  **downward**  in each step.

Return  *the knight's minimum initial health so that he can rescue the princess*.

 **Note**  that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

 

 **Example 1:** 

```
Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.

```

 **Example 2:** 

```
Input: dungeon = [[0]]
Output: 1

```

 

 **Constraints:** 

- m == dungeon.length
- n == dungeon[i].length
- 1 <= m, n <= 200
- -1000 <= dungeon[i][j] <= 1000

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.6 MB (beats 98.28%)  
**Submitted:** 2026-08-21T19:24:58.769Z  

```cpp
class Solution {
public:
int dp[201][201];
int better(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        // using p=pair<int,int>; //initial health currhealth
        using t=tuple<int,int,int,int>; //initial curr i,j
        vector<pair<int,int>>dir={{0,1},{1,0}};

        priority_queue<t,vector<t>,greater<t>>pq;
        int v= grid[0][0];
        if(v>0){
            pq.push({0,v,0,0});
        }
        else{
            pq.push({abs(v),0,0,0});
        }

        while(!pq.empty()){
            auto [init,curr,r,c]=pq.top();
            if(r==n-1 && c==m-1) return init+1;
            pq.pop();

            for(auto& d:dir){
                int vr= r+d.first;
                int vc= c+d.second;

                if(vr>=n || vc>=m) continue;
                if(vr>=0 && vr<n && vc>=0 && vc<m){
                    int newcurr=curr;
                    int newinit=init;

                    if(grid[vr][vc]<0){

                        //decrease the current health
                        //if needed increase the initial
                        
                        if(newcurr>0){
                            newcurr+=(grid[vr][vc]);
                            if(newcurr<0) newinit+=abs(newcurr),newcurr=0;
                            pq.push({newinit,newcurr,vr,vc});
                        }else{
                            newinit+=abs(grid[vr][vc]);
                            pq.push({newinit,newcurr,vr,vc});
                        }

                    }else{
                        //increase the current health
                        newcurr+=grid[vr][vc];
                        pq.push({newinit,newcurr,vr,vc});

                    }
                }
            }

        }
        return 0;        
    }
    int solve(int r,int c,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(dp[r][c]!=-1) return dp[r][c];

        if(r==n-1 && c==m-1) return max(1,1-grid[r][c]);
        int right=1e9;
        int down =1e9;
        if(r+1<n) down =solve(r+1,c,grid);
        if(c+1<m) right=solve(r,c+1,grid);

        int need = min(down,right);
        return dp[r][c]=max(1,need-grid[r][c]);
    }
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // return better(grid);
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/dungeon-game/)