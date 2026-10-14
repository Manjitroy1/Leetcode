class Solution {
public:
    const long long mod = 1e9+7;
    int countGoodStrings(long long n) {

        long long pprev=0;
        long long prev=1;
        for(long long i=2;i<=n;i++){
           long long curr = ((prev+ pprev))%mod;
            pprev=prev;
            prev=curr;
        }
        return (2*prev)%mod;
    }
};