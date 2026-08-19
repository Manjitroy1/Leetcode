class Solution {
public:
    const int mod =1e9+7;
    int kInversePairs(int n, int k) {
        if(k==0) return 1;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));

        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }

        for(int nn=2;nn<=n;nn++){
            for(int kk=0;kk<=k;kk++){
                
                int ans=0;
                for(int l=0;l<nn;l++){
                    if(kk-l>=0){
                        ans = (ans + dp[nn-1][kk-l]) % mod;
                    }
                }

                dp[nn][kk] = ans;
            }
        }
        return dp[n][k];
    }
};