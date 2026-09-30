# Trapping Rain Water II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an `m x n` integer matrix `heightMap` representing the height of each unit cell in a 2D elevation map, return  *the volume of water it can trap after raining*.

 

 **Example 1:** 

```
Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.

```

 **Example 2:** 

```
Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10

```

 

 **Constraints:** 

- m == heightMap.length
- n == heightMap[i].length
- 1 <= m, n <= 200
- 0 <= heightMap[i][j] <= 2 * 104

## Solution

**Language:** C++  
**Runtime:** 25 ms (beats 74.68%)  
**Memory:** 19.1 MB (beats 37.09%)  
**Submitted:** 2026-09-30T17:33:05.770Z  

```cpp
class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        //the water we can trap inside depend on the min height of the boundry
        //so we will traverse the min height first
        //and try to continously safegurad the path with max possible height
        using t=tuple<int,int,int>;
        priority_queue<t,vector<t>,greater<t>>pq;//height r,c
        vector<pair<int,int>>dir={{0,-1},{0,1},{1,0},{-1,0}};

        for(int i=0;i<n;i++){
            int left =grid[i][0];
            int right =grid[i][m-1];

            pq.push({left,i,0});
            pq.push({right,i,m-1});

            vis[i][0]=1;
            vis[i][m-1]=1;
        }
        for(int j=1;j<m-1;j++){
            int up=grid[0][j];
            int dn=grid[n-1][j];

            pq.push({up,0,j});
            pq.push({dn,n-1,j});

            vis[0][j]=1;
            vis[n-1][j]=1;
        }
        int ans=0;
        // pushed all the boundry ,, now process from the min height
        while(!pq.empty()){
            auto [h,r,c]=pq.top();
            pq.pop();

            for(auto d:dir){
                int vr= r+d.first;
                int vc= c+d.second;

                if(vr>=0 && vr<n && vc>=0 && vc<m && !vis[vr][vc]){
                    int x=grid[vr][vc];
                    if(x<h){
                        ans+=(h-x);
                    }
                    vis[vr][vc]=1;
                    pq.push({max(h,x),vr,vc});
                }
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/trapping-rain-water-ii/)