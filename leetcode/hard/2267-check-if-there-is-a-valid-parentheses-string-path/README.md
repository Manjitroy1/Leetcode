# Check if There Is a Valid Parentheses String Path

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

A parentheses string is a  **non-empty**  string consisting only of `'('` and `')'`. It is  **valid**  if  **any**  of the following conditions is  **true** :

- It is ().
- It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
- It can be written as (A), where A is a valid parentheses string.

You are given an `m x n` matrix of parentheses `grid`. A  **valid parentheses string path**  in the grid is a path satisfying  **all**  of the following conditions:

- The path starts from the upper left cell (0, 0).
- The path ends at the bottom-right cell (m - 1, n - 1).
- The path only ever moves down or right.
- The resulting parentheses string formed by the path is valid.

Return `true`  *if there exists a  **valid parentheses string path**  in the grid.*  Otherwise, return `false`.

 

 **Example 1:** 

```
Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.

```

 **Example 2:** 

```
Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 100
- grid[i][j] is either '(' or ')'.

## Solution

**Language:** C++  
**Runtime:** 280 ms (beats 18.99%)  
**Memory:** 227.5 MB (beats 11.18%)  
**Submitted:** 2026-10-07T13:58:21.937Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/)