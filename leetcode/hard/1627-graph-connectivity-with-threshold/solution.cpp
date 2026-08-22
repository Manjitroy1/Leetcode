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

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]= find(parent[x]);
    }

    void unite(int u,int v){
        int up=find(u);
        int vp=find(v);

        if(up==vp) return;
        if(size[up]<size[vp]) swap(up,vp);
        size[up]+=size[vp];
        parent[vp]=up;
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n+1);
        int q=queries.size();
        if(threshold==0) return vector<bool>(q,true);

        vector<bool>ans(q,false);
        if(threshold>=n) return ans;

        // for(int i=1;i<=n;i++){
        //     for(int j=i+1;j<=n;j++){
        //         int g= __gcd(i,j);
        //         if(g>threshold){
        //             dsu.unite(i,j);
        //         }
        //     }
        // }

        for(int d=threshold+1;d<n;d++){
            for(int mul=2*d;mul<=n;mul+=d){
                dsu.unite(d,mul);
            }
        }

        for(int i=0;i<q;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            int up=dsu.find(u);
            int vp=dsu.find(v);
            if(up==vp) ans[i]=true;
        }
        return ans;
        
    }
};