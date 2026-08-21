class Solution {
public:
    int dp[500][500];
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
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        if(n==1) return 0;
        vector<int>presum(n,0);
        presum[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1]+stoneValue[i];
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,stoneValue,presum);
        
    }
};