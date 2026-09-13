class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        //first check for rows
        //then check for columns 
        //return the minimum
        int n=grid.size();
        int m=grid[0].size();

        int row=0;
        for(int r=0;r<n;r++){
            int i=0;
            int j=m-1;
            while(i<j){
                if(grid[r][i]!=grid[r][j]){
                    row++;
                }
                i++;
                j--;
            }

        }

        int col=0;
        for(int c=0;c<m;c++){
            int i=0;
            int j=n-1;
            while(i<j){
                if(grid[i][c]!=grid[j][c]){
                    col++;
                }
                i++;
                j--;
            }

        }
        return min(row,col);
        
    }
};