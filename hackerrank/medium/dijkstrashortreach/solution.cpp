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
