class Solution {
public:
    int recc(int n,unordered_map<int,int>&mpp){
        if(n==0) return 0;
        if(n==1) return 1;

        // int ans=INT_MAX;
        if(mpp.count(n)) return mpp[n];

        int b=1e9,c=1e9;
        int a= 1+ recc(n-1,mpp);
        if(n%2==0) b= 1+ recc( (n/2), mpp);
        if(n%3==0) c= 1+ recc( (n/3), mpp);

        return mpp[n] = min(a,min(b,c));
    }
    // int tabu(int n){
    //     vector<int>dp(n+1,1e9);
    //     dp[0]=0;
    //     dp[1]=1;
    //     dp[2]=2;
    //     for(int i=2;i<=n;i++){
    //         int b=1e9,c=1e9;
    //         int a= 1+ dp[i-1];
    //         if(i%2==0) b= 1+ dp[i - (i/2)];
    //         if(i%3==0) c= 1+ dp[i- (2*(i/3))];

    //         dp[i]= min(a,min(b,c));
    //     }
    //     return dp[n];
    // }
    int minDays(int n) {
        // return recc(n);
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        // return tabu(n);
        unordered_map<int,int>mpp;
        return recc(n,mpp);
    }
};