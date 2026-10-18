# Find the Minimum Area to Cover All Ones II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a 2D  **binary**  array `grid`. You need to find 3  **non-overlapping**  rectangles having  **non-zero**  areas with horizontal and vertical sides such that all the 1's in `grid` lie inside these rectangles.

Return the  **minimum**  possible sum of the area of these rectangles.

 **Note**  that the rectangles are allowed to touch.

 

 **Example 1:** 

 **Input:**  grid = [[1,0,1],[1,1,1]]

 **Output:**  5

 **Explanation:** 

- The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
- The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
- The 1 at (1, 1) is covered by a rectangle of area 1.

 **Example 2:** 

 **Input:**  grid = [[1,0,1,0],[0,1,0,1]]

 **Output:**  5

 **Explanation:** 

- The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
- The 1 at (1, 1) is covered by a rectangle of area 1.
- The 1 at (1, 3) is covered by a rectangle of area 1.

 

 **Constraints:** 

- 1 <= grid.length, grid[i].length <= 30
- grid[i][j] is either 0 or 1.
- The input is generated such that there are at least three 1's in grid.

## Solution

**Language:** C++  
**Runtime:** 88 ms (beats 58.93%)  
**Memory:** 25 MB (beats 64.29%)  
**Submitted:** 2026-10-18T19:49:35.622Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/)