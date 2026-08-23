class Solution {
  public:
    /*You are required to complete below method */
    int countPS(string &s) {
        // Your code here
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){//i is the start and j is the end
                if(s[i]==s[j]){
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
                }
                else{
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                }
            }
        }
        return dp[0][n-1];
    }
};