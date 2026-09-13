class Solution {
public:
    void rowrotate(int r,int k,vector<vector<int>>& grid){
        //leftrotate by k
        int n=grid.size();
        vector<int>temp=grid[r];
        
        // rotate(grid[r].begin(),grid[r].begin()+k,grid.end());
        rotate(temp.begin(),temp.begin()+k,temp.end());
        grid[r]=temp;
        
        return ;
        
    }
    void colrotate(int c,int k,vector<vector<int>>& grid){
        int n=grid.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            temp[i] = grid[i][c];
        }
        rotate(temp.begin(),temp.begin()+k,temp.end());
        for(int i=0;i<n;i++){
            grid[i][c]=temp[i];
        }
        return;
    }
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0;i<n;i++){
             int v=rowShift[i];
             rowrotate(i,v%n,grid);
        }
        for(int i=0;i<n;i++){
             int v=colShift[i];
             colrotate(i,v%n,grid);
        }
        return grid;
    
    }
};