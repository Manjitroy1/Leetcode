class Solution {
public:
    int minRotations(int n, string s) {
        int ans=0;
        char prev='0';
        // vector<int>store(n);
        for(int i=0;i<n;i++){
            int a= abs(prev - s[i]);
            int b= 10-a;
            ans+=min(a,b);
            prev=s[i];
        }
        char last = s[n-1];
        prev= '0';
        int store = 10;
        
        for(int k=0;k<n-1;k++){
            //cost of k-1 to k 
            int a= abs(prev - s[k]);
            int b= 10-a;
            int first = min(a,b);

            int a2= abs(prev - s[n-1]);
            b= 10-a2;
            int second = min(a2,b);

            prev=s[k];
            //cost of k-1 to last
            store= min(store,second-first);
        }
        return min(ans,ans+store);
    }
};