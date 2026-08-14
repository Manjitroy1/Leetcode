class Solution {
public:
    int mod= 1e9+7;
    vector<int>fact;
    vector<int>invfact;
    
    long long power(long long a,long long b){
        long long res=1;
        while(b){
            if(b&1){
                res= res*a % mod;
            }
            a= a*a % mod;
            b>>=1;
        }
        return res;
    }
    long long comb(int a,int b){
        if(b<0 || b>a) return 0;
        return ((1LL* fact[a] * invfact[b] ) %mod * invfact[a-b]) % mod;
    }
    int countValidSequences(int n, int k) {
        if(n<2 || k<1) return 0;

        //we got mod factorial thus have to calculate power and iinverse factorial
        fact.resize(n+1,1);
        invfact.resize(n+1,1);

        for(int i=2;i<=n;i++){
            fact[i] = (1LL * fact[i-1]*i) % mod;
        }
        invfact[n] = power(fact[n],mod-2)%mod;

        for(int i=n-1;i>=0;i--){
            invfact[i] = (1LL* invfact[i+1]* (i+1) ) %mod;
        }
        long long total = comb(n-1,k-1);
        if( (n-k) % 2 !=0) return total;

        int v= (n+k)/2;
        long long odd= comb(v-1,k-1);

        return (total - odd +mod) % mod;
    }
};