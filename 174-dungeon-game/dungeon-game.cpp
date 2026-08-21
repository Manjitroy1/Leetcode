class Solution {
public:
int dp[201][201];
int better(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        // using p=pair<int,int>; //initial health currhealth
        using t=tuple<int,int,int,int>; //initial curr i,j
        vector<pair<int,int>>dir={{0,1},{1,0}};

        priority_queue<t,vector<t>,greater<t>>pq;
        int v= grid[0][0];
        if(v>0){
            pq.push({0,v,0,0});
        }
        else{
            pq.push({abs(v),0,0,0});
        }

        while(!pq.empty()){
            auto [init,curr,r,c]=pq.top();
            if(r==n-1 && c==m-1) return init+1;
            pq.pop();

            for(auto& d:dir){
                int vr= r+d.first;
                int vc= c+d.second;

                if(vr>=n || vc>=m) continue;
                if(vr>=0 && vr<n && vc>=0 && vc<m){
                    int newcurr=curr;
                    int newinit=init;

                    if(grid[vr][vc]<0){

                        //decrease the current health
                        //if needed increase the initial
                        
                        if(newcurr>0){
                            newcurr+=(grid[vr][vc]);
                            if(newcurr<0) newinit+=abs(newcurr),newcurr=0;
                            pq.push({newinit,newcurr,vr,vc});
                        }else{
                            newinit+=abs(grid[vr][vc]);
                            pq.push({newinit,newcurr,vr,vc});
                        }

                    }else{
                        //increase the current health
                        newcurr+=grid[vr][vc];
                        pq.push({newinit,newcurr,vr,vc});

                    }
                }
            }

        }
        return 0;        
    }
    int solve(int r,int c,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(dp[r][c]!=-1) return dp[r][c];

        if(r==n-1 && c==m-1) return max(1,1-grid[r][c]);
        int right=1e9;
        int down =1e9;
        if(r+1<n) down =solve(r+1,c,grid);
        if(c+1<m) right=solve(r,c+1,grid);

        int need = min(down,right);
        return dp[r][c]=max(1,need-grid[r][c]);
    }
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // return better(grid);
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};