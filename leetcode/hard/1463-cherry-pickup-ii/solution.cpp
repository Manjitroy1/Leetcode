class Solution {
public:
    int dp[71][71][71];
    int solve(int j1,int j2, int i, vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();

        if(i>=n) return 0;
        if(j1<0 || j1>=m || j2<0 || j2>=m) return 0;

        if(dp[j1][j2][i]!=-1) return dp[j1][j2][i];
        
        int ans=0;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                int nj1=j1+d1;
                int nj2=j2+d2;

                // if(issafe(nj1,nj2)){
                    if(j1==j2){
                        ans= max(ans, grid[i][j1] + solve(nj1,nj2,i+1,grid));
                    }else{
                        ans =max(ans, grid[i][j1]+ grid[i][j2] + solve(nj1,nj2,i+1,grid));
                    }
                // }
            }
        }
        return dp[j1][j2][i] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,m-1,0,grid);
    }
};