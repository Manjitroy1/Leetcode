class Solution {
public:
    int n;
    int m;

    int dijks01(vector<vector<int>>& grid){
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;

        vector<pair<int,int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};

        using p=pair<int,int>;

        deque<p>dq;
        dq.push_front({0,0});

        while(!dq.empty()){
            auto [r,c]=dq.front();
            dq.pop_front();
            
            if(r==n-1 && c==m-1) return dis[r][c];

            for(int i=0;i<dir.size();i++){
                int vr=r+dir[i].first;
                int vc=c+dir[i].second;

                if(vr<0 || vr>=n || vc<0 || vc>=m) continue;

                int cost= (grid[r][c]==1+i)? 0 : 1;

                int newdis=dis[r][c]+cost;
                if(dis[vr][vc]>newdis){

                    dis[vr][vc]=newdis;
                    if(cost){
                        dq.push_back({vr,vc});
                    }else{
                        dq.push_front({vr,vc});
                    }
                }
            }
        }
        return dis[n-1][m-1];

    }
    int minCost(vector<vector<int>>& grid) {
        //cost =0 if same dir 1 if change dir
        n=grid.size();
        m=grid[0].size();

        int ans=dijks01(grid);
        return ans;
        
    }
};