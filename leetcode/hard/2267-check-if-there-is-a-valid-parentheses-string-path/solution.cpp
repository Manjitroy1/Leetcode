class Solution {
public:
    //start must be open 
    //at end opencnt ==0 
    //if opencount is 0 then donot take the close one 
    int n;
    int m;
    vector<pair<int,int>>dir;
    vector<vector<vector<int>>>dp;

    bool dfs(int r,int c,int open,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        if(r==n-1 && c==m-1){
            if(!open) return true;
            else return false;
        }
        if(dp[r][c][open]!=-1) return dp[r][c][open];
        vis[r][c]=true;

        for(auto d:dir){
            int vr=r+d.first;
            int vc=c + d.second;

            if(vr>=0 && vr<n && vc>=0 && vc<m && !vis[vr][vc]){
                if(grid[vr][vc]=='('){
                    if(dfs(vr,vc,open+1,grid,vis)){
                        return dp[r][c][open]=true;
                    }
                }else{
                    if(open){
                        if(dfs(vr,vc,open-1,grid,vis)){
                            return dp[r][c][open]=true;
                        }
                    }
                }
            }
        }
        vis[r][c]=false;

        return dp[r][c][open]=false;
    } 
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        dir.resize(2);
        dir={{0,1},{1,0}};

        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(n+m+1,-1)));
        if(grid[0][0]!='(' || grid[n-1][m-1]!=')') return false;

        return dfs(0,0,1,grid,vis);
    }
};