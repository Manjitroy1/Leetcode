class Solution {
public:
    int minOperations(string s) {
        //rotate n times and calculate the cost of making palind
        int n=s.size();
        if(n==1) return 0;
        int ans=1e9;

        for(int i=0;i<n;i++){
            int cost=0;

            for(int k=0;k<n/2;k++){
                char a=s[k];
                char b=s[n-k-1];
                int diff= abs(a-b);
                cost+=min(diff,26-diff);
            }
            ans= min(ans,i + cost);

            char first= s[0];
            s.erase(0,1);
            s.push_back(first);
        }
        return ans;
    }
};