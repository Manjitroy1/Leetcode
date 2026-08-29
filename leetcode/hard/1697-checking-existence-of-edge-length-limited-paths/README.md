# Checking Existence of Edge Length Limited Paths

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

An undirected graph of `n` nodes is defined by `edgeList`, where `edgeList[i] = [ui, vi, disi]` denotes an edge between nodes `ui` and `vi` with distance `disi`. Note that there may be  **multiple**  edges between two nodes.

Given an array `queries`, where `queries[j] = [pj, qj, limitj]`, your task is to determine for each `queries[j]` whether there is a path between `pj` and `qj` such that each edge on the path has a distance  **strictly less than**  `limitj`.

Return  *a  **boolean array*** `answer` *, where* `answer.length == queries.length`  *and the* `jth`  *value of* `answer`  *is* `true` *if there is a path for* `queries[j]` *is* `true` *, and* `false` *otherwise*.

 

 **Example 1:** 

```
Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
Output: [false,true]
Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.

```

 **Example 2:** 

```
Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
Output: [true,false]
Explanation: The above figure shows the given graph.

```

 

 **Constraints:** 

- 2 <= n <= 105
- 1 <= edgeList.length, queries.length <= 105
- edgeList[i].length == 3
- queries[j].length == 3
- 0 <= ui, vi, pj, qj <= n - 1
- ui != vi
- pj != qj
- 1 <= disi, limitj <= 109
- There may be multiple edges between two nodes.

## Solution

**Language:** C++  
**Runtime:** 100 ms (beats 26.95%)  
**Memory:** 130.4 MB (beats 39.31%)  
**Submitted:** 2026-08-29T14:02:13.664Z  

```cpp
class DSU{
public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n,0);
        size.resize(n,1);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int u){
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u,int v){
        int up=find(u);
        int vp=find(v);

        if(up==vp) return;
        if(size[up] < size[vp]) swap(up,vp);
        size[up]+=size[vp];
        parent[vp]=up;
    }
};
class Solution {
public:

    static bool comp(vector<int>&a,vector<int>&b){
        return a[2] < b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edge, vector<vector<int>>& query) {
        //first sort the edge
        sort(edge.begin(),edge.end(),comp);

        //berfore sort store the index
        vector<vector<int>>queries;
        for(int i=0;i<query.size();i++){
            int u=query[i][0];
            int v=query[i][1];
            int limit=query[i][2];
            int idx=i;
            queries.push_back({u,v,limit,idx});
        }

        sort(queries.begin(),queries.end(),comp);
        //sort the queries
        int m=edge.size();
        int l=0;
        DSU dsu(n+1);

        vector<bool>ans(queries.size(),false);
        //we will process for each query
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            int limit=queries[i][2];
            int idx=queries[i][3];
    
            //if current query limit is l
            //connect all the edge whose distnace is l

            while(l<m && edge[l][2]<limit){
                //merge the edges
                dsu.unite(edge[l][0],edge[l][1]);
                l++;
            }

            //check if current u anv v are connected in dsu or not
            int up=dsu.find(u);
            int vp=dsu.find(v);
            if(up==vp) ans[idx]=true;
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/)