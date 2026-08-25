class Solution {
public:
    int dp[51][51][51];  //r1,c1,c2
    int solve(int r1,int c1,int c2,vector<vector<int>>& grid){
        int r2= (r1+c1-c2);
        int n=grid.size();

        //base case
        //bound case
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        if(r1==n-1 && c1==n-1 && c2==n-1) return grid[n-1][n-1];

        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];

        int cherries= (r1==r2 && c1==c2)? grid[r1][c1] : grid[r1][c1]+grid[r2][c2];

        int ans= max(solve(r1+1,c1,c2+1,grid),solve(r1+1,c1,c2,grid));
        ans= max(ans,solve(r1,c1+1,c2,grid));
        ans= max(ans,solve(r1,c1+1,c2+1,grid));

        return dp[r1][c1][c2]= (ans==INT_MIN)? INT_MIN : cherries+ans;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==-1 || grid[n-1][n-1]==-1) return 0;
        if(n==1) return grid[0][0]==1? 1:0;
        memset(dp,-1,sizeof(dp));
        return max(0,solve(0,0,0,grid));
    }
};