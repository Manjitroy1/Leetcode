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
                // if(u==v) return 0;
                //find the shortest dis from u to v
                ans = min(ans, dis[u][v]);
            }
        } 
        return ans>=1e9? -1 : ans+1;
    }
};