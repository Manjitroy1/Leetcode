class Solution {
public:
    const long long mod = 1e9 + 7;

   

    int tabu(vector<int>& nums, int K) {
        int n=nums.size();
        vector<long long>dp(K+1,0);
        dp[0]=1;
        //we are creating B whose sum =k
        //whether to take x or not take x
        //take x, then one possiblity 
        //not take x , x is in A or x is not in A
        for(int& x:nums){
            for(int k=K;k>=0;k--){
                dp[k]=(2*dp[k])%mod; //not take x;
                if(k-x>=0) dp[k]=(dp[k]+dp[k-x])%mod;
            }
        }
        return (int)dp[K];
    }
    int sumOfPower(vector<int>& nums, int K) {
        int n=nums.size();
        return tabu(nums,K);
    }
};