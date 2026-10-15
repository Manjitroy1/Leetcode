#define ll long long
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        // dp[i][parity][deletion used] till index i the max value with 
        //parity begin 0 1 --> next is + and -
        //deletion used --> 0 1 still we did not dele as we can delete at most 1

        //for this i start as a new subarray
        //can be consider for previous value
        //if del ==0 we can now delete this 1
        int n=nums.size();
        ll INF = LLONG_MIN/4;
        ll ans = INF;

        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(2,vector<ll>(2,INF)));
        for(int i=0;i<n;i++){
            dp[i][1][0]=nums[i]; //fresh start of a new subarray

            //we have a prev element only for i>0
            if(i>0){
                for(int p=0;p<2;p++){
                    for(int d=0;d<2;d++){
                        ll prev = dp[i-1][p][d]; //prev maximum value
                        if(prev<=INF) continue; // useless

                        //accoding to the p nums[i] have + or - val
                        ll val = (p==0)? prev + nums[i] : prev -nums[i];

                        //if we take this parity will change
                        dp[i][1-p][d] =max(dp[i][1-p][d], val);

                        //we cal delete alo
                        if(d==0){
                            dp[i][p][1] = max(dp[i][p][1], prev);
                        }
                    }
                }
            }
            //

            //the answer can be at any index
            for(int p=0;p<2;p++){
                for(int d=0;d<2;d++){
                    ans = max(ans,dp[i][p][d]);
                }
            }
        }
        return ans;
    }
};