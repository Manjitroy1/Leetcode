# Floyd : City of Blinding Lights

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a directed weighted graph where weight indicates distance, for each query, determine the length of the shortest path between nodes.  There may be many queries, so efficiency counts.  

For example, your graph consists of $5$ nodes as in the following:



![image](https://s3.amazonaws.com/hr-assets/0/1525461069-142e0d306a-blindingLightsExample.png)  

A few queries are from node $4$ to node $3$, node $2$ to node $5$, and node $5$ to node $3$.  
<br>

1. There are two paths from $4$ to $3$:
	+	$4 \Rightarrow 1 \Rightarrow 2 \Rightarrow 3$ at a distance of $4 + 5 + 1 = 10$  
    +	$4 \Rightarrow 1 \Rightarrow 5 \Rightarrow 3$ at a distance of $4 + 3 + 2 = 9$  
  	In this case we choose path $2$.  
      
2. There is no path from $2$ to $5$, so we return $-1$.  
  
3. There is one path from $5$ to $3$:  
	+	$5 \Rightarrow 3$ at a distance of $2$.  
    

**Input Format**

The first line has two integers $n$ and $m$, the number of nodes and the number of edges in the graph.  
Each of the next $m$ lines contains three space-separated integers $u$ $v$ and $w$, the two nodes between which the _directed_ edge $u \Rightarrow v$ exists, and $w$, the length of the edge.  
The next line contains a single integer $q$, the number of queries.  
Each of the next $q$ lines contains two space-separated integers $a$ and $b$, denoting the start and end nodes for traversal.  

**Constraints**

$2 \le n \le 400$  
$1 \le m \le \frac{n\times(n-1)}{2}$  
$1 \le q \le 10^5$  
$1 \le u,v \le n$  
$1 \le w \le 350$  
The distance from a node to itself is always $0$ and it is always reachable from itself.

__If there are edges between the same pair of nodes with different weights, the last one (most recent) is to be considered as the only edge between them.__

**Output Format**

Print $q$ lines, each containing a single integer specifying the shortest distance for the query.  

If the destination node is not reachable, return $-1$.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-07-29T16:56:23.030Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void floyd(vector<vector<int>>&mat){
    int n=mat.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(mat[i][k]>=1e9 || mat[k][j]>=1e9) continue;
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
}

int main()
{
    string road_nodes_edges_temp;
    getline(cin, road_nodes_edges_temp);

    vector<string> road_nodes_edges = split(rtrim(road_nodes_edges_temp));

    int road_nodes = stoi(road_nodes_edges[0]);
    int road_edges = stoi(road_nodes_edges[1]);

    vector<int> road_from(road_edges);
    vector<int> road_to(road_edges);
    vector<int> road_weight(road_edges);
    
    int n=road_nodes;
    vector<vector<int>>mat(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++){
        mat[i][i]=0;
    }
    for (int i = 0; i < road_edges; i++) {
        
        
        string road_from_to_weight_temp;
        getline(cin, road_from_to_weight_temp);

        vector<string> road_from_to_weight = split(rtrim(road_from_to_weight_temp));

        int road_from_temp = stoi(road_from_to_weight[0]);
        int road_to_temp = stoi(road_from_to_weight[1]);
        int road_weight_temp = stoi(road_from_to_weight[2]);

        road_from[i] = road_from_temp;
        road_to[i] = road_to_temp;
        road_weight[i] = road_weight_temp;
        
        int u = road_from_temp-1;
        int v = road_to_temp-1;
        int w = road_weight_temp;
        mat[u][v]=w;
    }
    floyd(mat);

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int x = stoi(first_multiple_input[0]);

        int y = stoi(first_multiple_input[1]);
        
        int ans=mat[x-1][y-1];
        if(ans>=1e9) cout<<-1<<endl;
        else{ cout<<ans<<endl;}
    }

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

[View on HackerRank](https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem)