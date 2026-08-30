# GRDJUMP - Rating 1148

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Grid Jump

You are standing at point $(0, 0)$ of the 2D coordinate grid. You would like to reach point $(A, B)$.

You have the following movements available to you:

- Move either $1$ or $2$ steps right for a cost of $P$ coins. That is, you can move from $(x, y)$ to either $(x+1, y)$ or $(x+2, y)$ for a cost of $P$.
- Move either $1$ or $2$ steps up for a cost of $Q$ coins. That is, you can move from $(x, y)$ to either $(x, y+1)$ or $(x, y+2)$ for a cost of $Q$.
- Move $1$ step up and $1$ step right for a cost of $R$ coins. That is, you can move from $(x, y)$ to $(x+1, y+1)$ for a cost of $R$.

Find the minimum number of coins you need to spend in order to reach point $(A, B)$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of a single line of input, containing five space-separated integers $A, B, P, Q, R$ — the coordinates of the destination point, and the movement costs.
### Output Format

For each test case, output on a new line the minimum number of coins you need to move to $(A, B)$.

### Constraints
- $1 \leq T \leq 1000$
- $1 \le A, B, P, Q, R \le 100$
### Sample 1:
Input
Output

```
4
2 1 6 3 4
2 2 6 3 4
3 4 1 3 2
4 7 4 2 7

```

```
9
8
8
16

```

### Explanation:

 **Test case $1$:**  We want to reach $(2, 1)$. It's optimal to:

- Use the first type and move two steps right, with a cost of $P=6$.
- Use the second type and move one step up, with a cost of $Q=3$.

This will put us at $(2, 1)$ for a cost of $6+3 = 9$, which is the best we can do.

 **Test case $2$:**  We want to reach $(2, 2)$. It's optimal to use the third type of move (simultaneously move right and up one step each) two times, each costing $R=4$.
This will put us at $(2, 2)$ for a cost of $4+4=8$.
For the given costs, this is optimal.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-30T11:40:29.989Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int x,int y,int p,int q,int r,vector<vector<int>>&dp){
    if(x==0 && y==0) return 0;
    if(x<0 || y<0) return 1e9;
    
    if(dp[x][y]!=-1) return dp[x][y];
    int ans=1e9;
    int right = p + min(solve(x-1,y,p,q,r,dp),solve(x-2,y,p,q,r,dp));
    int up =q+ min(solve(x,y-1,p,q,r,dp),solve(x,y-2,p,q,r,dp));
    int both =r+ solve(x-1,y-1, p,q,r,dp);
    
    ans = min(right,min(up,both));
    return dp[x][y]=ans;
}

// int tabu(int a,int b,int p,int q,int r){
//     vector<vector<int>>dp(a+1,vector<int>dp(b+1,1e9));
//     dp[0][0]=0;
    
//     for(int x=0;x<=a;x++){
//         for(int y=0;y<=b;y++){
//             if(x==0 && y==0) continue;
            
//             int ans=1e9;
//             int right = (x>=2)? (p + min(dp[x-1][y],dp[x-2][y])) : 1e9;
//             int up =(y>=2)? (q+ min(dp[x][y-1],dp[x][y-2])) : 1e9;
//             int both =(x>=1 && y>=1)? (r+ dp[x-1][y-1]) : 1e9;
            
//             ans=min(right,min(up,both));
//             dp[x][y]=ans;
//         }
//     }
//     return dp[a][b];
// }

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b,p,q,r;
	    cin>>a>>b>>p>>q>>r;
	    //target a,b start 0,0
	    vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
	    int ans= solve(a,b,p,q,r,dp);
	    cout<<ans<<endl;
	}
	return 0;

}

```

---

[View on CodeChef](https://www.codechef.com/problems/GRDJUMP)