class Solution {
public:
    bool recc(int i,int j,string& s,string& p,vector<vector<int>>&dp){
        if(j>=p.size()) return i>=s.size();

        if(dp[i][j]!=-1) return dp[i][j];

        bool firstmatch = (i<s.size() && (s[i]==p[j] || p[j]=='.'));

        if(j+1 < p.size() && p[j+1]=='*'){
            //match zero
            return dp[i][j]= (recc(i,j+2,s,p,dp) || (firstmatch && recc(i+1,j,s,p,dp)));
            //match one or more
        }
        return dp[i][j]= (firstmatch && recc(i+1,j+1,s,p,dp));
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+2,vector<int>(m+2,-1));
        return recc(0,0,s,p,dp);
        
    }
};