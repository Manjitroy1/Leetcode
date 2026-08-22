class Solution {
public:
    // long long dp[1001][1001];
    const int mod= 1e9+7;
    // long long solve(int i,int j,vector<string>&words,string& target){
    //     int w=words.size();
    //     int n=words[0].size();
    //     int m=target.size();
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(j>=m) return 1;
    //     if(i>=n || (m-j > n-i)) return 0;

    //     int cnt=0;
    //     for(int k=0;k<w;k++){
    //         if(words[k][i]==target[j]) cnt++;
    //     }
    //     long long match = cnt* solve(i+1,j+1,words,target);
    //     long long  nmatch = solve(i+1,j,words,target);
    //     return dp[i][j] = (match + nmatch)%mod;
    // }


    int tabu(vector<string>& words, string target){
        int w=words.size();
        int n=words[0].size();
        int m=target.size();
        // vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        vector<long long>prev(m+1,0);
        prev[m]=1;

        // for(int i=0;i<=n;i++){
        //     dp[i][m]=1;
        // }
        vector<vector<int>>freq(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(int k=0;k<w;k++){
                // ith index of every k the word
                freq[i][words[k][i]-'a']++;
            }
        }

        for(int i=n-1;i>=0;i--){
            vector<long long>curr(m+1,0);
            curr[m]=1;
            for(int j=m-1;j>=0;j--){

                int cnt=freq[i][target[j]-'a'];
                long long match = 1LL*cnt * prev[j+1];
                long long  nmatch = prev[j];
                
                curr[j] = (match + nmatch)%mod;
            }
            prev=curr;
        }
        return prev[0];
    }
    int numWays(vector<string>& words, string target) {
        // memset(dp,-1,sizeof(dp));
        // return (int)solve(0,0,words,target);
        return (int)tabu(words,target);
        
    }
};