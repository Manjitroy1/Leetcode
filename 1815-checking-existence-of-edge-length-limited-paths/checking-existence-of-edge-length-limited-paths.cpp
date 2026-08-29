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