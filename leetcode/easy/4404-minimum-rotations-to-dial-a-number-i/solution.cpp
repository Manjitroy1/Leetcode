class Solution {
public:
    int minRotations(string s) {
        int n=s.size();
        int ans=0;
        int prev='0';
        for(int i=0;i<n;i++){
            int a= abs(prev - s[i]);
            int b= 10-a;
            ans+= min(a,b);
            prev=s[i];
        }
        return ans;
    }
};