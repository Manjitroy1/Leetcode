class Solution {
public:
    int dp[501][501];
    int solve(int l,int r,vector<int>&arr,vector<int>&presum){
        //max among min possibilities
        if(r==l) return 0;
        if(r-l==1) return min(arr[l],arr[r]);
        if(dp[l][r]!=-1) return dp[l][r];

        int ans=0;
        for(int k=l;k<r;k++){
            int leftsum= l<1? presum[k] : presum[k]-presum[l-1];
            int rigtsum= presum[r]-presum[k];

            if(leftsum<rigtsum){
                ans= max(ans,leftsum + solve(l,k,arr,presum));
            }
            else if(rigtsum<leftsum){
                ans=max(ans,rigtsum + solve(k+1,r,arr,presum));
            }
            else{
                ans= max(ans,leftsum + max(solve(l,k,arr,presum),solve(k+1,r,arr,presum)));
            }
        }
        return dp[l][r]=ans;
    }
    int tabu(vector<int>&arr,vector<int>&presum){
        int n=arr.size();
        for(int r=0;r<n;r++){
            dp[r][r]=0;
            if(r>0) dp[r-1][r]=min(arr[r],arr[r-1]);
        }

        for(int l=n-2;l>=0;l--){
            for(int r=l+1;r<=n-1;r++){
                int ans=0;
                for(int k=l;k<r;k++){
                    int leftsum= l<1? presum[k] : presum[k]-presum[l-1];
                    int rigtsum= presum[r]-presum[k];

                    if(leftsum<rigtsum){
                        ans= max(ans,leftsum + dp[l][k]);
                    }
                    else if(rigtsum<leftsum){
                        ans=max(ans,rigtsum + dp[k+1][r]);
                    }
                    else{
                        ans= max(ans,leftsum + max(dp[l][k],dp[k+1][r]));
                    }
                }
                dp[l][r]=ans;
            }
        }
        return dp[0][n-1];
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        if(n==1) return 0;
        vector<int>presum(n,0);
        presum[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1]+stoneValue[i];
        }
        memset(dp,-1,sizeof(dp));
        // return solve(0,n-1,stoneValue,presum);
        return tabu(stoneValue,presum);
        
    }
};