class Solution {
public:
    const long long mod= 1e9+7;

    long long power(long long a,long long p){
        long long res=1;
        while(p){
            if(p & 1) res=(res*a) % mod;
            a=(a*a)%mod;
            p>>=1;
        }
        return res;
    }

    long long solve(long long num){
        int w=num%10;
        long long d= num/10;

        long long dup=d;
        int len=0;
        
        while(dup){
            dup/=10;
            len++;
        }

        long long p=1;
        for(int i=0;i<len-w;i++){
            p*=10;
        }
        long long y=d%p;
        long long x=d/p;
        return power(x,y);
        
    }
    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
        long long sum=0;

        for(int i=0;i<n;i++){
            sum = (sum + solve(nums[i])) % mod;
        }
        return (int) sum;
        
    }
};