class Solution {
public:
    const int mod = 1e9+7;
    vector<int>rollmax;
    int dp[7][16][5001];
    int solve(int i,int cnt,int n){
        if(i>0 &&  cnt >= rollmax[i-1]) return 0; //if comes max times consecutively return 0
        if(n==0) return 1; //base case taken n times roll

        if(dp[i][cnt][n]!=-1) return dp[i][cnt][n]; 

        int ans=0;
        //try all possibility
        for(int d=1;d<=6;d++){
            if(i==d){
                ans = (ans + solve(d,cnt+1,n-1)) % mod;
            }else{
                ans= (ans + solve(d,0,n-1))% mod;
            }
        }
        return dp[i][cnt][n] = (ans) % mod;

    }
    int dieSimulator(int n, vector<int>& rollMax) {
        rollmax=rollMax;
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,n);
        return ans;
        
    }
};