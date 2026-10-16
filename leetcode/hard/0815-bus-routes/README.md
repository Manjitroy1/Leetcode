# Bus Routes

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array `routes` representing bus routes where `routes[i]` is a bus route that the `ith` bus repeats forever.

- For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 ->... forever.

You will start at the bus stop `source` (You are not on any bus initially), and you want to go to the bus stop `target`. You can travel between bus stops by buses only.

Return  *the least number of buses you must take to travel from* `source` *to* `target`. Return `-1` if it is not possible.

 

 **Example 1:** 

```
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

```

 **Example 2:** 

```
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1

```

 

 

 **Constraints:** 

- 1 <= routes.length <= 500.
- 1 <= routes[i].length <= 105
- All the values of routes[i] are unique.
- sum(routes[i].length) <= 105
- 0 <= routes[i][j] < 106
- 0 <= source, target < 106

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.3 MB  
**Submitted:** 2026-10-16T17:34:22.589Z  

```cpp
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //build the graph
        int n=routes.size();
        // vector<vector<int>>adj(n);
        unordered_map<int,vector<int>>mpp; //number -->> nodes  7 in 0 2 5 nodes
        vector<vector<int>>dis(n,vector<int>(n,1e9));

        for(int i=0;i<n;i++){
            for(int j=0;j<routes[i].size();j++){
                int v = routes[i][j];

                if(mpp.count(v)){
                    //try all connections
                    for(auto& u : mpp[v]){
                        //connect u to i and i to u
                        // adj[u].push_back(i);
                        // adj[i].push_back(u);
                        dis[u][i]=1;
                        dis[i][u]=1;
                    }
                } 
                mpp[v].push_back(i);
            }
        }
        //now i have the graph
        //apply floyd warshal
        for(int i=0;i<n;i++) dis[i][i]=0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    if(dis[i][k] >= 1e9 || dis[k][j] >= 1e9) continue;
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int ans = 1e9;
        if(!mpp.count(source) || !mpp.count(target)) return -1; //source or target not in the mpp
        if(source==target) return 0;
        
        for(int& u: mpp[source]){
            for(int& v:mpp[target]){
                //find the shortest dis from u to v
                ans = min(ans, dis[u][v]);
            }
        } 
        return ans>=1e9? -1 : ans+1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/bus-routes/)