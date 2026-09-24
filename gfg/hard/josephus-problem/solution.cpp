class Solution {
  public:
    int solve(int n, int k) {
        // code here
        vector<int>person;
        for(int i=1;i<=n;i++){
            person.push_back(i);
        }
        k--;
        int i=0;
        
        while(person.size()>1){
            int s=person.size();
            i = (i+k) % s;
            person.erase(person.begin()+i);
        }
        return person[0];
    }
    int solveq(int n,int k){
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            //we will take k-1 element from the top and push to the queue
            for(int cnt=1;cnt<=k-1;cnt++){
                q.push(q.front());
                q.pop();
            }
            q.pop(); //pop the kth element
        }
        return q.front();
    }
    
    int opt(int n,int k){ //return 0 based answer
    
        //we can go with recursion
        if(n==1) return 0;
        int x= opt(n-1,k);
        int y= (x+k) % n;
        return y;
    }
    int tabu(int n,int k){
        vector<int>dp(n+1,k);
        dp[1]=0;
        
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+k) % i;
        }
        return dp[n];
    }
    
    int spopt(int n,int k){
        int prev=0;
        
        for(int i=2;i<=n;i++){
            int curr = (prev+k) % i;
            prev=curr;
        }
        return prev;
    }
    
    int josephus(int n, int k) {
        // return solve(n,k);
        // return solveq(n,k);
        // return opt(n,k) +1 ; 
        // return tabu(n,k)+1;
        return spopt(n,k)+1;
    }
    
};