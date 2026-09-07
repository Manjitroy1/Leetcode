class Solution {
public:
    const int mod= 1e9+7;
    int better(string s) {
        int n=s.size();
        vector<int>dp(n,1);
        int total =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(s[i]!=s[j]){
                    dp[i]= (dp[i] + dp[j]) % mod;
                }
            }
            total=(total + (dp[i])) % mod;
        }
        return total;
    }
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int>dp(26,0);
        int total =0;
        
        // dp[char]= number of disticnt subsequences ending with this char

        for(int i=0;i<n;i++){
            int c= s[i]-'a';
            int add= (total-dp[c]+ mod) %mod; //number of new distinct subseqeunces by subtracting that can cause duplicates
            dp[c]= (1+total)%mod; //total number of disticnt subsqquences ending with char c so far
            total = (total + 1 + add)%mod; // adding new subsequences to the previous total
        }
        
        return total;
    }
};