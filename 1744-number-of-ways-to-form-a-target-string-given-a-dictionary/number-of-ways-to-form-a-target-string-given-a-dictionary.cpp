class Solution {
public:
    long long dp[1001][1001];
    const int mod= 1e9+7;
    long long solve(int i,int j,vector<string>&words,string& target){
        int w=words.size();
        int n=words[0].size();
        int m=target.size();
        if(dp[i][j]!=-1) return dp[i][j];
        if(j>=m) return 1;
        if(i>=n || (m-j > n-i)) return 0;

        int cnt=0;
        for(int k=0;k<w;k++){
            if(words[k][i]==target[j]) cnt++;
        }
        long long match = cnt* solve(i+1,j+1,words,target);
        long long  nmatch = solve(i+1,j,words,target);
        return dp[i][j] = (match + nmatch)%mod;
    }
    int numWays(vector<string>& words, string target) {
        memset(dp,-1,sizeof(dp));
        return (int)solve(0,0,words,target);
        
    }
};