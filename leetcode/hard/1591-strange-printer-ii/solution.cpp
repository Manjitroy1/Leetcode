// class Solution {
// public:
//     struct Node{
//         int mnrow,mnclm,mxrow,mxclm;
//     };

//     bool kahn(vector<set<int>>&adj){
//         int n=adj.size();
//         queue<int>q;

//         vector<int>indeg(n,0);
//         for(int u=0;u<n;u++){
//             for(int v : adj[u]){
//                 indeg[v]++;
//             }
//         }

//         int cnt=0;
//         for(int i=0;i<n;i++){
//             if(indeg[i]==0){
//                 q.push(i);
//             }
//         }
//         if(q.empty()) return false;

//         while(!q.empty()){
//             int u=q.front();
//             q.pop();
//             cnt++;

//             for(int v : adj[u]){
//                 indeg[v]--;
//                 if(indeg[v]==0){
//                     q.push(v);
//                 }
//             }
//         }
//         return cnt==n? true:false;
//     }

//     bool isPrintable(vector<vector<int>>&grid){
//         int n=grid.size();
//         int m=grid[0].size();
        
//         map<int,Node>mpp;

//         unordered_map<int,int>freq;
//         int cnt=0;  // to assign zero based colorign

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 int clr= grid[i][j];
//                 //it is a new color
//                 if(!freq.count(clr)) freq[clr]=cnt,cnt++;

//                 if(mpp.count(clr)){
//                     auto& [mnr,mnc,mxr,mxc]= mpp[clr];
//                     mnr= min(mnr,i),mnc=min(mnc,j);
//                     mxr=max(mxr,i),mxc=max(mxc,j);  
//                 }
//                 else{
//                     mpp[clr]={i,j,i,j};
//                 }

//             }
//         }
//         vector<set<int>>adj(cnt);  //the graph

//         for(auto& data:mpp){
//             int clr=data.first;
//             auto& [mnrow,mnclm,mxrow,mxclm] = data.second;

//             for(int i=mnrow;i<=mxrow;i++){
//                 for(int j=mnclm;j<=mxclm;j++){
//                     int newclr= grid[i][j];

//                     if(newclr!=clr){ /// clr------>newclr
//                         int u= freq[clr];
//                         int v= freq[newclr];
//                         adj[u].insert(v);
//                     }
//                 }
//             }
//         }

//         //i have the graph go for kahns algo
//         return kahn(adj);
        
//     }
// };

class Solution {
public:

    struct Node {
        int mnrow = INT_MAX;
        int mnclm = INT_MAX;
        int mxrow = INT_MIN;
        int mxclm = INT_MIN;
    };

    bool kahn(vector<vector<int>>& adj, int cnt) {

        vector<int> indeg(cnt, 0);

        for(int u = 0; u < cnt; u++) {
            for(int v : adj[u]) {
                indeg[v]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < cnt; i++) {
            if(indeg[i] == 0)
                q.push(i);
        }

        int done = 0;

        while(!q.empty()) {

            int u = q.front();
            q.pop();

            done++;

            for(int v : adj[u]) {

                indeg[v]--;

                if(indeg[v] == 0)
                    q.push(v);
            }
        }

        return done == cnt;
    }

    bool isPrintable(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        const int C = 61;

        vector<Node> mpp(C);
        vector<bool> present(C, false);

        // Find bounding rectangle of every color
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                int clr = grid[i][j];

                if(!present[clr]) {

                    present[clr] = true;

                    mpp[clr] = {i, j, i, j};
                }
                else {

                    mpp[clr].mnrow = min(mpp[clr].mnrow, i);
                    mpp[clr].mnclm = min(mpp[clr].mnclm, j);

                    mpp[clr].mxrow = max(mpp[clr].mxrow, i);
                    mpp[clr].mxclm = max(mpp[clr].mxclm, j);
                }
            }
        }

        vector<vector<int>> adj(C);

        // edge[u][v] = whether u -> v already exists
        vector<vector<bool>> edge(C, vector<bool>(C, false));

        int cnt = 0;

        for(int clr = 1; clr < C; clr++) {

            if(!present[clr])
                continue;

            cnt++;

            auto& [mnrow, mnclm, mxrow, mxclm] = mpp[clr];

            for(int i = mnrow; i <= mxrow; i++) {

                for(int j = mnclm; j <= mxclm; j++) {

                    int newclr = grid[i][j];

                    if(newclr != clr && !edge[clr][newclr]) {

                        adj[clr].push_back(newclr);

                        edge[clr][newclr] = true;
                    }
                }
            }
        }

        return kahn(adj, C);
    }
};