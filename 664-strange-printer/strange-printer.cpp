class Solution {
public:
    int recc(int start, int end, string& s,vector<vector<int>>&dp){
        if(start>end) return 0;
        if(dp[start][end]<1e7) return dp[start][end];

        dp[start][end] = 1 + recc(start+1,end,s,dp);

        for(int k=start+1;k<=end;k++){
            if(s[start]==s[k]){
                dp[start][end] = min(dp[start][end], recc(start+1,k-1,s,dp) + recc(k,end,s,dp));
            }
        }
        return dp[start][end];
    }
    int strangePrinter(string s) {
        int n=s.size();
        int end= n-1;
        int start=0;
        vector<vector<int>>dp(n,vector<int>(n,1e7));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        return recc(start,end,s,dp);
    }
};