# Remove Max Number of Edges to Keep Graph Fully Traversable

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Alice and Bob have an undirected graph of `n` nodes and three types of edges:

- Type 1: Can be traversed by Alice only.
- Type 2: Can be traversed by Bob only.
- Type 3: Can be traversed by both Alice and Bob.

Given an array `edges` where `edges[i] = [typei, ui, vi]` represents a bidirectional edge of type `typei` between nodes `ui` and `vi`, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return  *the maximum number of edges you can remove, or return*  `-1`  *if Alice and Bob cannot fully traverse the graph.* 

 

 **Example 1:** 

```
Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.

```

 **Example 2:** 

```
Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.

```

 **Example 3:** 

```
Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
```

 

 

 **Constraints:** 

- 1 <= n <= 105
- 1 <= edges.length <= min(105, 3  *n*  (n - 1) / 2)
- edges[i].length == 3
- 1 <= typei <= 3
- 1 <= ui < vi <= n
- All tuples (typei, ui, vi) are distinct.

## Solution

**Language:** C++  
**Runtime:** 10 ms (beats 93.01%)  
**Memory:** 143.7 MB (beats 83.92%)  
**Submitted:** 2026-08-21T17:54:22.375Z  

```cpp
class DSU{
public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=1;i<n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int u,int v){
        int up=find(u);
        int vp=find(v);
        if(up==vp) return;
        if(size[up]<size[vp]) swap(up,vp);
        parent[vp]=up;
        size[up]+=size[vp];
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU red(n+1);
        DSU green(n+1);
        int total =edges.size();
        int used=0;
        for(auto& edge:edges){
            int type=edge[0];
            int u=edge[1];
            int v=edge[2];

            if(type==3){
                int up=red.find(u);
                int vp=red.find(v);

                if(up!=vp){
                    //unite them
                    red.unite(u,v);
                    green.unite(u,v);
                    // bcnt++; //no of blue edges used
                    used++;
                }
            }
            

        }
        for(auto& edge:edges){
            int type=edge[0];
            int u=edge[1];
            int v=edge[2];

            if(type==1){
                int up=red.find(u);
                int vp=red.find(v);

                if(up!=vp){
                    //unite them
                    red.unite(u,v);
                    // green.unite(u,v);
                    // rcnt++; //no of blue edges used
                    used++;
                }
            }
            if(type==2){
                int up=green.find(u);
                int vp=green.find(v);

                if(up!=vp){
                    //unite them
                    green.unite(u,v);
                    // green.unite(u,v);
                    // gcnt++; //no of blue edges used
                    used++;
                }
            }
        }
        bool rflag=false,gflag=false;

        for(int i=0;i<=n;i++){
            if(red.size[i]==n) rflag=true;
            if(green.size[i]==n) gflag=true;
        }
        if(!(rflag & gflag)) return -1;
        return total - used;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/)