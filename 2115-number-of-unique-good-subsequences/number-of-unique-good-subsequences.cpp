class Solution {
public:
    const int mod=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        bool zero=false;
        int n=binary.size();
        int end0=0;
        int end1=0;
        for(int i=0;i<n;i++){
            if(binary[i]=='0'){
                zero=true;
                end0 = (end0+end1)%mod;
            }else{
                end1 = (end0 + end1 + 1)% mod;
            }

        }
        int ans = (end0+end1)%mod;
        return zero? ans+1 : ans;

    }
};