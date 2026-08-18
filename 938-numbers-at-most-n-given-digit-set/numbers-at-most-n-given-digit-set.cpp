class Solution {
public:
    int dp[20][2];
    int countways(int pos,int tight,vector<string>&dig,vector<string>&digits){
        if(pos==dig.size()) return 1;

        if(dp[pos][tight]!=-1) return dp[pos][tight];
        
        int res=0;

        string limit = tight? dig[pos]:"9";

        for(string d:digits){
            if(d<=limit){
                //we ca use this digit
                int newtight = tight && (dig[pos]==d);
                res+=countways(pos+1,newtight,dig,digits);
            }

        }
        return dp[pos][tight] = res;
    }
    int solve(int n,vector<string>&dig,vector<string>& digits){
        if(n<=0) return 0;

        while(n){
            dig.push_back(to_string(n%10));
            n/=10;
        }
        reverse(dig.begin(),dig.end());

        int sz=dig.size();  //the number is of sz size
        int choice=digits.size();
        //total number of numbers possible leass than sz size with dig of digits
        int ans=0;
        for(int len=1;len<sz;len++){
            ans+=pow(choice,len);
        }
        ans+=countways(0,1,dig,digits);
        return ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<string>dig;
        memset(dp,-1,sizeof(dp));
        return solve(n,dig,digits);
        
    }
};