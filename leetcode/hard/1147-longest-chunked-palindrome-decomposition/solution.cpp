class Solution {
public:
    int dp[1001][1001];
    int solve(int l,int h,string& text){
        if(l>h) return 0;
        if(l==h) return 1;
        
        // int ans=0;
        // int take=0;
        if(dp[l][h]!=-1) return dp[l][h];

        for(int i=l;i<=(l+h)/2;i++){
            int j=h+l-i;
            int len = i-l+1;
            if(text.compare(l,len,text,j,len) ==0){
                return dp[l][h]=(2+solve(i+1,j-1,text));
            }
        }
        return dp[l][h]=1;
    }
    int longestDecomposition(string text){
        int l=0;
        int h=text.size()-1;
        // vector<vector<int>>dp(h+1,vector<int>(h+1,-1));
        memset(dp,-1,sizeof(dp));
        return solve(l,h,text);
        
    }
};