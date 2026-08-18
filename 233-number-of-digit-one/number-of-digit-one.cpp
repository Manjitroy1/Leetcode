class Solution {
public:
    int dp[20][20][2];
    int countone(int pos,int cnt,int tight,vector<int>&digits){
        if(pos==digits.size()) return cnt;

        if(dp[pos][cnt][tight]!=-1) return dp[pos][cnt][tight];
        int limit = tight? digits[pos] : 9;
        int res=0;

        for(int dig=0;dig<=limit;dig++){
            int newcount=cnt;

            if(dig==1){
                newcount++;
            }
            int newtight = tight && (digits[pos]==dig);
            res+=countone(pos+1,newcount,newtight,digits);
        }
        return dp[pos][cnt][tight]=res;
    }
    int solve(int n,vector<int>&digits){
        if(n<=0) return 0;

        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        reverse(digits.begin(),digits.end());
        return countone(0,0,1,digits);  //pos cnt tight

    }
    int countDigitOne(int n) {
        vector<int>digits;
        memset(dp,-1,sizeof(dp));
        return solve(n,digits);
    }
};