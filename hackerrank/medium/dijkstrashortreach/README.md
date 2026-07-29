# Dijkstra: Shortest Reach 2

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an undirected graph and a starting node, determine the lengths of the shortest paths from the starting node to all other nodes in the graph.  If a node is unreachable, its distance is -1.  Nodes will be numbered consecutively from $1$ to $n$, and edges will have varying distances or lengths.
 
For example, consider the following graph of 5 nodes:

```
Begin	End	Weight
1	2	5
2	3	6
3	4	2
1	3	15
```
[##]: "![image](https://s3.amazonaws.com/hr-assets/0/1523465555-dcd300c21d-drawing.jpg)" 
![image](https://s3.amazonaws.com/hr-assets/0/1535120384-c96f8f586f-djikstraexample.png)   
Starting at node $1$, the shortest path to $2$ is direct and distance $5$.  Going from $1$ to $3$, there are two paths: $1\rightarrow2\rightarrow3$ at a distance of $5+6=11$ or $1\rightarrow3$ at a distance of $15$.  Choose the shortest path, $11$.  From $1$ to $4$, choose the shortest path through $3$ and extend it: $1\rightarrow2\rightarrow3\rightarrow4$ for a distance of $11+2=13$  There is no route to node $5$, so the distance is $-1$.

The distances to all nodes in increasing node order, omitting the starting node, are `5 11 13 -1`.

**Function Description**  

Complete the *shortestReach* function in the editor below.  It should return an array of integers that represent the shortest distance to each node from the start node in ascending order of node number.  

shortestReach has the following parameter(s):  

- *n*: the number of nodes in the graph  
- *edges*: a 2D array of integers where each $edges[i]$ consists of three integers that represent the start and end nodes of an edge, followed by its length  
- *s*: the start node number  

**Input Format**

The first line contains $t$, the number of test cases. 

Each test case is as follows:  
- The first line contains two space-separated integers $n$ and $m$, the number of nodes and edges in the graph.  
- Each of the next $m$ lines contains three space-separated integers $x$, $y$, and $r$, the beginning and ending nodes of an edge, and the length of the edge.  
- The last line of each test case has an integer $s$, denoting the starting position.  




**Constraints**

$1 \le t \le 10$  
$2 \le n \le 3000$  
$1 \le m \le \frac{N\times(N-1)}{2}$  
$1 \le x,y,s \le N$  
$1 \le r \le 10^5$  

__If there are edges between the same pair of nodes with different weights, they are to be considered as is, like multiple edges.__


**Output Format**

For each of the $t$ test cases, print a single line consisting $n-1$ space separated integers denoting the shortest distance to the $n-1$ nodes from starting position $s$ in  increasing order of their labels, excluding $s$. 

For unreachable nodes, print $-1$.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-29T14:49:22.325Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shortestReach' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER s
 */
//for n-1 times to all the edges

vector<int>dijk(vector<vector<pair<int,int>>>&adj,int s){
    int n=adj.size();
    vector<int>dis(n,1e9);
    dis[s]=0;
    using t=pair<int,int>; //weight vertex
    priority_queue<t,vector<t>,greater<t>>pq;
    pq.push({0,s});
    
    while(!pq.empty()){
        auto node= pq.top();
        pq.pop();
        
        int curr= node.first;
        int u= node.second;
        
        if(curr>dis[u] || curr>=1e9) continue;
        
        for(auto ngbr: adj[u]){
            int v=ngbr.first;
            int w=ngbr.second;
            
            if(curr+w < dis[v]){
                dis[v]=curr+w;
                pq.push({dis[v],v});
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(i==s) continue;
        if(dis[i]>=1e9){
            ans.push_back(-1);
        }else{
            ans.push_back(dis[i]);
        }
    }
    return ans;
}

// vector<int>bell(int n,int s, map<pair<int,int>,int>&mpp){
//     vector<int>dis(n,1e9);
    
//     dis[s]=0;
    
//     for(int i=1;i<=n-1;i++){
//         for(auto edge : mpp){
//             int u= edge.first.first;
//             int v= edge.first.second;
//             int w=edge.second;
            
//             if(dis[u]>=1e9) continue;
//             if(dis[u] + w <dis[v]){
//                 dis[v]= dis[u]+w;
//             }
//         }
//     }
    
//     vector<int>ans;
//     for(int i=0;i<n;i++){
//         if(i==s) continue;
//         if(dis[i]>=1e9){
//             ans.push_back(-1);
//         }else{
//             ans.push_back(dis[i]);
//         }
//     }
//     return ans;
// }

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    vector<vector<pair<int,int>>>adj(n);
    for(auto node:edges){
        int u=node[0]-1;
        int v=node[1]-1;
        int w=node[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    s-=1;
    return dijk(adj,s);
    
    
    // map<pair<int,int>,int>mpp;
    
    // for(auto node:edges){
    //     int u=node[0]-1;
    //     int v=node[1]-1;
    //     int w=node[2];
    //     if(mpp.count({u,v}) || mpp.count({v,u})){
    //         mpp[{u,v}]= min(mpp[{u,v}],w);
    //         mpp[{v,u}]= min(mpp[{v,u}],w);
    //     }else{
    //         mpp[{u,v}]=w;
    //         mpp[{v,u}]=w;
    //     }
       
    // }
    // return bell(n,s,mpp);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 3; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = shortestReach(n, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/dijkstrashortreach/problem)