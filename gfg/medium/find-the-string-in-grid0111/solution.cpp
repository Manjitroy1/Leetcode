class Solution {
  public:
  
  
  vector<pair<int,int>>dir;
  int n;
  int m;
  
  bool bfs(int r,int c,int pos,int d,string& word,vector<vector<char>> &mat){
      if(pos>=(int)word.size()) return true;
      if(r<0 || r>=n) return false;
      if(c<0 || c>=m) return false;
      
      int vr = r + dir[d].first;
      int vc = c + dir[d].second;
      
      if(word[pos] == mat[r][c]){
          return bfs(vr,vc,pos+1,d,word,mat);
      }
      return false;
  }
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        // Code here
        n=mat.size();
        m = mat[0].size();
        int k = word.size();
        vector<vector<int>>ans;
        
        if(k==0) return ans;
        if(k > max(n,m)) return ans;
        
        dir.resize(8);
        dir= {{0,1},{0,-1},{1,0},{-1,0},{-1,1},{1,-1},{-1,-1},{1,1}};
            //R L D U // upleft downright upleft downright 8 direction
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(mat[i][j]==word[0]){
                    
                    for(int d=0;d<8;d++){
                        
                        if(bfs(i,j,0,d,word,mat)){
                            ans.push_back({i,j});
                            break;
                        }
                    }
                    
                }
                
            }
        }
        return ans;
    }
};