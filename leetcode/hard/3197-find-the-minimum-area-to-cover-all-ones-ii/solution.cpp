class Solution {
public:
    int n;
    int m;
    int helper(int sr,int er,int sc,int ec, vector<vector<int>>& grid){
        //min r min c
        //max r max c
        int mnr=n,mnc=m,mxr=-1,mxc=-1;
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                if(grid[i][j]){
                    mnr =min(mnr,i);
                    mnc =min(mnc,j);
                    mxr =max(mxr,i);
                    mxc= max(mxc,j);
                }
            }
        }
        if(mnr==n || mnc==m || mxr==-1 || mxc==-1) return 1; //if there is no one, have to take a rec of are 1 
        return (mxr-mnr+1)*(mxc-mnc+1);
    }
    int minimumSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        n=grid.size();
        m=grid[0].size();

        // horizontal cut
       for(int i=0;i<=m-3;i++){
        for(int j=i+1;j<=m-2;j++){
            ans= min(ans,helper(0,n-1,0,i,grid)+ helper(0,n-1,i+1,j,grid)+ helper(0,n-1,j+1,m-1,grid)); //first col to next coln
        }
       }
        //  vertical cut
       for(int i=0;i<=n-3;i++){
        for(int j=i+1;j<=n-2;j++){
            ans= min(ans,helper(0,i,0,m-1,grid)+ helper(i+1,j,0,m-1,grid)+ helper(j+1,n-1,0,m-1,grid)); //first col to next coln
        }
       }
       //top cut
       for(int i=0;i<=n-2;i++){
        for(int j=0;j<=m-2;j++){
            ans = min(ans,helper(0,i,0,m-1,grid)+ helper(i+1,n-1,0,j,grid) + helper(i+1,n-1,j+1,m-1,grid));
        }
       }
       //bottoom cut
       for(int i=n-1;i>0;i--){
        for(int j=0;j<=m-2;j++){
            ans = min(ans,helper(i,n-1,0,m-1,grid)+ helper(0,i-1,0,j,grid) + helper(0,i-1,j+1,m-1,grid));
        }
       }
       //left 
       for(int j=0;j<=m-2;j++){
        for(int i=0;i<=n-2;i++){
            ans= min(ans,helper(0,n-1,0,j,grid)+ helper(0,i,j+1,m-1,grid)+ helper(i+1,n-1,j+1,m-1,grid));
        }
       }
       //right
       for(int j=m-1;j>0;j--){
        for(int i=0;i<=n-2;i++){
            ans= min(ans,helper(0,n-1,j,m-1,grid)+ helper(0,i,0,j-1,grid)+ helper(i+1,n-1,0,j-1,grid));
            
        }
       }
       return ans;
    }
};