# Strange Printer II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

There is a strange printer with the following two special requirements:

- On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
- Once the printer has used a color for the above operation, the same color cannot be used again.

You are given a `m x n` matrix `targetGrid`, where `targetGrid[row][col]` is the color in the position `(row, col)` of the grid.

Return `true` *if it is possible to print the matrix* `targetGrid` *,** otherwise, return* `false`.

 

 **Example 1:** 

```
Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
Output: true

```

 **Example 2:** 

```
Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
Output: true

```

 **Example 3:** 

```
Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
Output: false
Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.

```

 

 **Constraints:** 

- m == targetGrid.length
- n == targetGrid[i].length
- 1 <= m, n <= 60
- 1 <= targetGrid[row][col] <= 60

## Solution

**Language:** C++  
**Runtime:** 114 ms (beats 12.65%)  
**Memory:** 26.8 MB (beats 43.24%)  
**Submitted:** 2026-08-21T10:39:45.037Z  

```cpp
class Solution {
public:
    struct Node{
        int mnrow,mnclm,mxrow,mxclm;
    };

    bool kahn(vector<set<int>>&adj){
        int n=adj.size();
        queue<int>q;

        vector<int>indeg(n,0);
        for(int u=0;u<n;u++){
            for(int v : adj[u]){
                indeg[v]++;
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        if(q.empty()) return false;

        while(!q.empty()){
            int u=q.front();
            q.pop();
            cnt++;

            for(int v : adj[u]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        return cnt==n? true:false;
    }

    bool isPrintable(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        
        map<int,Node>mpp;

        unordered_map<int,int>freq;
        int cnt=0;  // to assign zero based colorign

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int clr= grid[i][j];
                //it is a new color
                if(!freq.count(clr)) freq[clr]=cnt,cnt++;

                if(mpp.count(clr)){
                    auto& [mnr,mnc,mxr,mxc]= mpp[clr];
                    mnr= min(mnr,i),mnc=min(mnc,j);
                    mxr=max(mxr,i),mxc=max(mxc,j);  
                }
                else{
                    mpp[clr]={i,j,i,j};
                }

            }
        }
        vector<set<int>>adj(cnt);  //the graph

        for(auto& data:mpp){
            int clr=data.first;
            auto& [mnrow,mnclm,mxrow,mxclm] = data.second;

            for(int i=mnrow;i<=mxrow;i++){
                for(int j=mnclm;j<=mxclm;j++){
                    int newclr= grid[i][j];

                    if(newclr!=clr){ /// clr------>newclr
                        int u= freq[clr];
                        int v= freq[newclr];
                        adj[u].insert(v);
                    }
                }
            }
        }

        //i have the graph go for kahns algo
        return kahn(adj);
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/strange-printer-ii/)