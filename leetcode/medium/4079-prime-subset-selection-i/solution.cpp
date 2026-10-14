class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        //sieve of erast
        int total = n;
        vector<bool>prime(total+1,true);
        prime[0]=false;
        prime[1]=false;

        vector<int>store;
        for(int i=2;i*i<=total;i++){
            if(prime[i]){
                for(int j=i*i;j<=total;j+=i){
                    prime[j]=false;
                }
            }
        }
        int sum=0;
        for(int i=2;i<=n;i++){
            if(prime[i] && sum+i<=s){
                sum+=i;
                store.push_back(i);
            }
        }
        return store;
    }
};