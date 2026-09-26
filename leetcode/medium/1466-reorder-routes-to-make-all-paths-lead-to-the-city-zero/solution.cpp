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