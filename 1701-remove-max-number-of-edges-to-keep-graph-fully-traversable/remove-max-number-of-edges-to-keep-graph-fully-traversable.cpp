class DSU{
public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=1;i<n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int u,int v){
        int up=find(u);
        int vp=find(v);
        if(up==vp) return;
        if(size[up]<size[vp]) swap(up,vp);
        parent[vp]=up;
        size[up]+=size[vp];
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU red(n+1);
        DSU green(n+1);
        int total =edges.size();
        int used=0;
        for(auto& edge:edges){
            int type=edge[0];
            int u=edge[1];
            int v=edge[2];

            if(type==3){
                int up=red.find(u);
                int vp=red.find(v);

                if(up!=vp){
                    //unite them
                    red.unite(u,v);
                    green.unite(u,v);
                    // bcnt++; //no of blue edges used
                    used++;
                }
            }
            

        }
        for(auto& edge:edges){
            int type=edge[0];
            int u=edge[1];
            int v=edge[2];

            if(type==1){
                int up=red.find(u);
                int vp=red.find(v);

                if(up!=vp){
                    //unite them
                    red.unite(u,v);
                    // green.unite(u,v);
                    // rcnt++; //no of blue edges used
                    used++;
                }
            }
            if(type==2){
                int up=green.find(u);
                int vp=green.find(v);

                if(up!=vp){
                    //unite them
                    green.unite(u,v);
                    // green.unite(u,v);
                    // gcnt++; //no of blue edges used
                    used++;
                }
            }
        }
        bool rflag=false,gflag=false;

        for(int i=0;i<=n;i++){
            if(red.size[i]==n) rflag=true;
            if(green.size[i]==n) gflag=true;
        }
        if(!(rflag & gflag)) return -1;
        return total - used;
    }
};