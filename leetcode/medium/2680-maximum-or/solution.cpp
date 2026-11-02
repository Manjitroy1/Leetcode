#define ll long long
class Solution {
public:
    // long long solve(vector<int>& nums, int k) {
    //     int n = nums.size();

    //     vector<vector<ll>> dp(n, vector<ll>(k + 1, 0));

    //     // Base case
    //     for (int j = 0; j <= k; j++) {
    //         dp[0][j] = (ll)nums[0] << j;
    //     }

    //     // Transitions
    //     for (int i = 1; i < n; i++) {

    //         for (int j = 0; j <= k; j++) {

    //             ll num = (ll)nums[i] << j;

    //             for (int l = 0; l <= k - j; l++) {

    //                 dp[i][j + l] = max(
    //                     dp[i][j + l],
    //                     dp[i - 1][l] | num
    //                 );
    //             }
    //         }
    //     }

    //     return dp[n - 1][k];
    // }
    long long maximumOr(vector<int>& nums, int k) {
      
        //apply k operation to only one elements to i 
        //we need or of all prev i = or of 0---i-1
        //we need or of all suff i = i----n-1
        int n=nums.size();
        vector<ll>prev(n+1,0);
        vector<ll>suff(n+1,0);

        for(int i=0;i<n;i++){
            prev[i+1] = prev[i] | (ll)nums[i];
        }
        for(int i=n-1;i>=0;i--){
            suff[i] = suff[i+1] | (ll)nums[i];
        }
        ll ans =0;
        for(int i=0;i<n;i++){
            ll val = (ll)nums[i]<<k | prev[i] | suff[i+1];
            ans = max(ans,val);
        }

        return ans;
    }
};