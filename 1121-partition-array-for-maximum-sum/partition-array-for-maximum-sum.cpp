class Solution {
public:
    int recc(int start, int end, vector<int>&arr, int k,vector<vector<int>>&dp){
        if(start>= arr.size()) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int n=arr.size();
        int ans=0;
        int mx=arr[start];
        for(int c=start;c < min(n, start+k); c++){
            mx= max(mx,arr[c]);
            int len = c-start+1;

            ans = max(ans, mx*len + recc(c+1,end,arr,k,dp));

        }
        return dp[start][end] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int start=0;
        int end =arr.size()-1;
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return recc(start,end,arr,k,dp);
    }
};