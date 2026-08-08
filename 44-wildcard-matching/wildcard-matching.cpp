class Solution {
public:
    bool solve(int i,int j, string& s, string& p, vector<vector<int>>&dp){
        if(j<0) return i<0;  // p gets over return s is over or not
        // if(i<0) return j<0;  // s is over case 1 p is not over case 2 p over
        if(i<0){
            if(j<0) return true;
            else{
                while(j>=0){
                    if(p[j]!='*') return false;
                    j--;
                }
                return true;
            }
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]= solve(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*'){
            return dp[i][j]= (solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp));
        } 
        return dp[i][j]= false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,s,p,dp);
    }
};