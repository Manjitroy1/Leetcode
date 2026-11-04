# Word in Grid - All Occurrences

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a 2D grid  **mat[][]**  of size **n × m**  consisting of characters and a string  **word**, find all starting positions where the word occurs in the grid.

- The word can be formed from any cell by moving in any of the 8 directions (2 horizontal, 2 vertical, and 4 diagonal) in a straight line without changing direction.
- Each cell can be used at most once per occurrence.
- Return all unique starting coordinates in lexicographically smallest order.

 **Examples :** 

```
Input: mat[][] = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}, word = "abe"
Output: {{0,0}, {0,2}, {1,0}}
Explanation: From (0,0) we can find "abe" in right-down diagonal. From (0,2) we can find "abe" in left-down diagonal. From (1,0) we can find "abe" in horizontally right direction.

```

```
Input: mat[][] = {{G,E,E,K,S,F,O,R,G,E,E,K,S}, {G,E,E,K,S,Q,U,I,Z,G,E,E,K}, {I,D,E,Q,A,P,R,A,C,T,I,C,E}}, word = "GEEKS"
Output: {{0,0}, {0,8}, {1,0}}
Explanation: From (0,0) we can find "GEEKS" horizontally right. From (0,8) we can find "GEEKS" horizontally right. From (1,0) we can find "GEEKS" horizontally right. 

```

 **Constraints:** 
1 <= n <= m <= 50
1 <= |word| <= 20

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-04T14:38:51.881Z  

```cpp
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
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1)