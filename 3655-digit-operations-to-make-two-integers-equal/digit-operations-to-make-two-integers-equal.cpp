class Solution {
public:
    int total = 1e4+1;
    vector<bool>primes;
    void sieve(vector<bool>&primes){
        primes[0]=false;
        primes[1]=false;

        for(int i=2;i*i<=total;i++){
            if(primes[i]){
                for(int j=i*i;j<=total;j+=i){
                    primes[j]=false;
                }
            }
        }
    }
    bool isprime(int num){
        return primes[num];
    }
    int minOperations(int n, int m) {
        //both are same number of digit
        primes.resize(total,true);
        sieve(primes);
        if(primes[n] || primes[m]) return -1;

        using p =pair<int,int>;
        priority_queue<p,vector<p>,greater<p>>pq; //steps,n
        pq.push({n,n}); //initial cost is n
        vector<bool>used(total+1,false);

        while(!pq.empty()){
            auto [steps,num] = pq.top();
            pq.pop();

            if(used[num]) continue;
            used[num] = true;


            if(num==m) return steps; 

            //try possibility
            string s = to_string(num);
            for(int i=0;i<s.size();i++){
                char c = s[i];
                //increment
                if(s[i]<'9'){
                    s[i]++;
                    int next = stoi(s);
                    //check prime and used
                    if(!primes[next] && !used[next]){
                        pq.push({next+steps,next});
                    }
                    s[i]=c;
                }
                //decrement
                if(s[i]>'0' && !(i==0 && s[i]=='1')){
                    s[i]--;
                    int next = stoi(s);
                    //check prime and used
                    if(!primes[next] && !used[next]){
                        pq.push({next+steps,next});
                    }
                    s[i]=c;
                }
               
            }
        }
        return -1;
    }
};