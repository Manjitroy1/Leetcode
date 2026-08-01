class Solution {
public:
    int dp[101][101];
    int recc(int start, string& s, int k,vector<vector<int>>&palind){
        int n=s.size();

        if (start == n)
            return (k == 0) ? 0 : 1e9;

        if (k == 0)
            return 1e9;

        if (k > n - start)
            return 1e9;

        if(dp[start][k]!=-1) return dp[start][k];

        int ans=INT_MAX;
        for(int c=start;c<=n-k;c++){
            ans = min(ans, palind[start][c] + recc(c+1,s,k-1,palind) );
        }
        return dp[start][k] = ans;
    }
    int palindromePartition(string s, int k) {

        int n=s.size();
        vector<vector<int>>palind(n,vector<int>(n));  //count of char req to make it palind if 0 then it is a p
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(j-i<=1){
                    palind[i][j] = s[i]==s[j] ? 0:1;
                }
                else{
                    palind[i][j] = palind[i+1][j-1];
                    if(s[i]!=s[j]){
                        palind[i][j]+=1;
                    }
                }
            }
        }
        int start=0;
        memset(dp,-1,sizeof(dp));
        return recc(start,s,k,palind);


    }
};