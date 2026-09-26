# Reorder Routes to Make All Paths Lead to the City Zero

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There are `n` cities numbered from `0` to `n - 1` and `n - 1` roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by `connections` where `connections[i] = [ai, bi]` represents a road from city `ai` to city `bi`.

This year, there will be a big event in the capital (city `0`), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city `0`. Return the  **minimum**  number of edges changed.

It's  **guaranteed**  that each city can reach city `0` after reorder.

 

 **Example 1:** 

```
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

```

 **Example 2:** 

```
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

```

 **Example 3:** 

```
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0

```

 

 **Constraints:** 

- 2 <= n <= 5 * 104
- connections.length == n - 1
- connections[i].length == 2
- 0 <= ai, bi <= n - 1
- ai != bi

## Solution

**Language:** C++  
**Runtime:** 220 ms (beats 13.65%)  
**Memory:** 123.4 MB (beats 24.22%)  
**Submitted:** 2026-09-26T10:24:43.665Z  

```cpp
class Solution {
public:
    set<pair<int,int>>stt;

    int dfs(int u,int parent,vector<vector<int>>&adj){
        int cnt=0;
        for(int v:adj[u]){
            if(v==parent) continue;
            if(stt.count({u,v})) cnt++;
            cnt+=dfs(v,u,adj);
        }
        return cnt;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto& node:connections){
            int u=node[0];
            int v=node[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            stt.insert({u,v}); //u----v
        }
        int ans= dfs(0,-1,adj);
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/)