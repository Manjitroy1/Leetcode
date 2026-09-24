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
    // int solveq(int n,int k){
        
    // }
    int josephus(int n, int k) {
        return solve(n,k);
    }
    
};