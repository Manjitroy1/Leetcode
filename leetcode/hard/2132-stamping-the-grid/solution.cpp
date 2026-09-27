class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
        //can we stamp at top left cell
        //check the whole rectangle
        //if the whole rectangle has no 1's then we can
        //which can be calculated using pre comuting of presum
        int n=grid.size();
        int m=grid[0].size();
        // presum[i+1][j+1] represent 0,0 to i j rectagle total 1's in grid
        vector<vector<int>>presum(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                presum[i+1][j+1]= grid[i][j] + presum[i+1][j]+presum[i][j+1] - presum[i][j];
            }
        }

        //if we are able to fit an stamp
        //we have mark all, so we will +- difference array
        vector<vector<int>>diff(n+1,vector<int>(m+1,0));
        //at end prefum
        // i,j represetns starting cell of the stamp of h and w we create a box
        for(int i=0;i+h<=n;i++){
            for(int j=0;j+w<=m;j++){    
                int r=i+h;
                int c=j+w;

                int total = presum[r][c]-presum[r][j]-presum[i][c]+presum[i][j];
                if(total==0){
                    diff[i][j]++;
                    diff[i][c]--;
                    diff[r][j]--;
                    diff[r][c]++;
                }
                //created the diff array
            }
        }

        //is any cell of grid is zero have colletion is also 0 return -1
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0) diff[i][j]+=diff[i-1][j];
                if(j>0) diff[i][j]+=diff[i][j-1];
                if(i>0 && j>0) diff[i][j]-=diff[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(diff[i][j]==0 && grid[i][j]==0){
                    return false;
                }
            }
        }
        return true;
    }
};