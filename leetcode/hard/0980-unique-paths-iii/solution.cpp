class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int total;
    int n;
    int m;
    int fr=-1;
    int fc=-1;
    
    int dfs(int r,int c,int cnt,vector<vector<bool>>&vis){
        if(r==fr && c==fc) return cnt==total;

        vis[r][c]=true;
        int ans=0;
        for(auto d:dir){
            int vr= r+d.first;
            int vc= c+d.second;

            if(vr>=0 && vr<n && vc>=0 && vc<m && !vis[vr][vc]){
                ans+=dfs(vr,vc,1+cnt,vis);
            }
        }
        vis[r][c]=false;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        total = n*m;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        // dir.resize(4);
        
        int sr=-1;
        int sc=-1;
       

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                }else if(grid[i][j]==2){
                    fr=i;
                    fc=j;
                }
                else if(grid[i][j]==-1){
                    vis[i][j]=true;
                    total--;
                }

            }
        }
        return dfs(sr,sc,1,vis);
    }
};