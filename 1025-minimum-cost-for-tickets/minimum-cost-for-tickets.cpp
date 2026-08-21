class Solution {
public:
    int dp[366];
    int solve(int idx,vector<int>&days,vector<int>&costs){
        if(idx>=days.size()) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int val=days[idx];
        int ans=INT_MAX;

        for(int i=0;i<3;i++){
            int upto=val;
            if(i==1) upto+=6;
            if(i==2) upto+=29;
            int newidx = upper_bound(days.begin(),days.end(),upto) - days.begin();
            ans= min(ans, costs[i] + solve(newidx,days,costs));
        }
        return dp[idx]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,days,costs);
        
    }
};