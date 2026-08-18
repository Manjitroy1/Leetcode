class Solution {
public:
    int dp[32][2][2];
    int unique(int pos,int prevone,int tight,vector<int>&bits){
        if(pos==bits.size()) return 1;

        if(dp[pos][prevone][tight]!=-1) return dp[pos][prevone][tight];

        int res=0;
        int limit = tight? bits[pos] : 1;

        for(int b=0;b<=limit;b++){
            if(b==1 && prevone) continue;
            int newprevone = (b==1);
            int newtight = tight && bits[pos]==b;

            res+=unique(pos+1,newprevone,newtight,bits);
        }
        return dp[pos][prevone][tight]=res;
    }
    
    int findIntegers(int n) {
        vector<int>bits;
        for(int i=30;i>=0;i--){
            bits.push_back((n>>i) & 1);
        }
        memset(dp,-1,sizeof(dp));
        return unique(0,0,1,bits);
    }
};