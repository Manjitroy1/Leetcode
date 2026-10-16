#define ll long long
class Solution {
public:
    //dp[x] = maximum i get where x is the end
    //if the current rides does not end in this dono take
    //if current ends check the ride that gives maximum greedyly
    // dp[x] = dp[x-1] //if curr not end
    //dp[x] = max(dp[s] + (current cost get)) // this ride start at s and end at x thus get dp[s]
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        using p = pair<int,int>;
        vector<vector<p>>stops(n+1); // start tips
        for(auto& node:rides){
            int s=node[0];
            int e=node[1];
            int t=node[2];
            stops[e].push_back({s,t});
        }
        //we will process for each end time
        vector<ll>dp(n+1,0);

        for(int e=2;e<=n;e++){
            dp[e]=dp[e-1];
            
            if(stops[e].empty()){ //nothing stops at this 
                continue;
            }
            //check for all possible starts
            ll mx=0;
            for(auto& [s,t] : stops[e]){
                mx = max(mx, dp[s] + (e-s) + t);
            }
            dp[e] = max(dp[e],mx);
        }
        return dp[n];
    }
};