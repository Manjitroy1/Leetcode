# Maximum Number of Points From Grid Queries

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an `m x n` integer matrix `grid` and an array `queries` of size `k`.

Find an array `answer` of size `k` such that for each integer `queries[i]` you start in the  **top left**  cell of the matrix and repeat the following process:

- If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
- Otherwise, you do not get any points, and you end this process.

After the process, `answer[i]` is the  **maximum**  number of points you can get.  **Note**  that for each query you are allowed to visit the same cell  **multiple**  times.

Return  *the resulting array*  `answer`.

 

 **Example 1:** 

```
Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each query.
```

 **Example 2:** 

```
Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 2 <= m, n <= 1000
- 4 <= m * n <= 105
- k == queries.length
- 1 <= k <= 104
- 1 <= grid[i][j], queries[i] <= 106

## Solution

**Language:** C++  
**Runtime:** 113 ms (beats 66.90%)  
**Memory:** 48.3 MB (beats 73.17%)  
**Submitted:** 2026-10-08T06:09:46.122Z  

```cpp
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();
        int qs=queries.size();
    
        vector<pair<int,int>>q;

        for(int i=0;i<qs;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        
        vector<int>ans(qs,0);
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        using t=tuple<int,int,int>;
        priority_queue<t,vector<t>,greater<t>>pq; //value of grid r c
        pq.push({grid[0][0],0,0});
        vis[0][0]=true;

        int cnt=0;
        //for each query process
        for(auto& [val,idx] : q){
            while(!pq.empty() && get<0>(pq.top()) < val){
                auto [gval,r,c]=pq.top();
                pq.pop();
                cnt++;

                for(auto d:dir){
                    int vr= r+ d.first;
                    int vc= c+ d.second;
                    if(vr>=0 && vr<n && vc>=0 && vc<m && !vis[vr][vc]){
                        pq.push({grid[vr][vc],vr,vc});
                        vis[vr][vc]=true;
                    }
                }
            }
            ans[idx]=cnt;

        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/)