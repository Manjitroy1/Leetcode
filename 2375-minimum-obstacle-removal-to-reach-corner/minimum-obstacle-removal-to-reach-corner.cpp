class Solution {
public:
    int dijk01(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        using t=pair<int,int>; //r,c
        vector<vector<int>>dis(n,vector<int>(m,n*m));

        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

        //we will use dequeue
        deque<t>q; //r c
        dis[0][0]=0;
        q.push_front({0,0});

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop_front();

            if(r==n-1 && c==m-1) return dis[r][c];

            for(auto d:dir){
                int vr=r+d.first;
                int vc=c+d.second;

                if(vr>=0 && vr<n && vc>=0 && vc<m){
                    int b=grid[vr][vc]? 1:0;
                    int newblock = dis[r][c]+b;

                    if(dis[vr][vc] > newblock){
                        dis[vr][vc]=newblock;
                        if(b){
                            q.push_back({vr,vc});
                        }else{
                            q.push_front({vr,vc});
                        }
                    }
                }
            }
        }
        return dis[n-1][m-1];

    }
    int dijkstra(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        using t=tuple<int,int,int>; //cnt,r,c
        vector<vector<int>>dis(n,vector<int>(m,n*m));

        priority_queue<t,vector<t>,greater<t>>pq;
        // int first= grid[0][0]? 1:0;
        pq.push({0,0,0});
        dis[0][0]=0;
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

        while(!pq.empty()){
            auto [block,r,c]=pq.top();
            pq.pop();

            if(dis[r][c]<block) continue;
            if(r==n-1 && c==m-1) return block;

            for(auto d:dir){
                int vr= r+d.first;
                int vc= c+d.second;
                if(vr>=0 && vr<n && vc>=0 && vc<m){
                    int b= grid[vr][vc]? 1:0;
                    int newblock = block+b;
                    
                    if(dis[vr][vc]>newblock){
                        dis[vr][vc]=newblock;
                        pq.push({newblock,vr,vc});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        // int ans=dijkstra(grid);
        int ans=dijk01(grid);
        return ans;
    }
};