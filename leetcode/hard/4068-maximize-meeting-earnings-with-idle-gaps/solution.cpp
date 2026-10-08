#define ll long long
class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        int n=meetings.size();
        if(n==0) return 0;

        sort(meetings.begin(),meetings.end()); 
        vector<ll>dp(n,0);
        dp[0]=meetings[0][2];
        ll ans=dp[0];

        if(n==1) return ans;

        for(int i=1;i<n;i++){
            dp[i] = meetings[i][2];

            for(int j=0;j<i;j++){
                if(meetings[j][1]<=meetings[i][0]){
                    ll canbe= (meetings[i][0]- meetings[j][1]) + meetings[i][2];
                    dp[i] = max(dp[i],dp[j] + canbe);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};