class Solution {
public:
    bool ispalid(int l, int r, string& s){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int recc(int start,int end, string& s,vector<vector<int>>&dp){
        if(start>=s.size()) return 0;
        if(dp[start][end]!=-1) return dp[start][end];

        int ans=INT_MAX;
        int curr=0;
        for(int k=start;k<=end;k++){
            if(ispalid(start,k,s)){
                curr= 1 + recc(k+1,end,s,dp);
            }
            ans=min(ans,curr);
        }
        return dp[start][end] = ans;
    }
    int minCut(string s) {
        int n=s.size();
        int start=0;
        int end=n-1;

        vector<vector<int>>dp(n,vector<int>(n,-1));
        return recc(start,end,s,dp)-1;
    }
};