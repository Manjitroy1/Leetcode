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
    
    int josephus(int n, int k) {
        // return solve(n,k);
        return solveq(n,k);
    }
    
};