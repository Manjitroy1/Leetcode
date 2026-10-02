#define ll long long
class Solution {
public:
    ll z_func(string& s){
        int n=s.size();
        vector<int>z(n,0);

        // l to r is the z box which is equal to the prefix;
        int l=0;
        int r=0;

        for(int i=1;i<n;i++){
            //resue the prev
            if(i<=r){
                int k=i-l; //l shifted to 0 and i shifted to i-l
                z[i]=min(r-i+1,z[k]);
            }
            //extend the limit
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                z[i]++;
            }
            //update the limit
            if(i+z[i]-1 > r){
                l=i;
                r=i+z[i]-1;
            }
        }
        z[0]=n;

        ll ans =0;
        for(int i=0;i<n;i++){
            ans+=z[i];
        }
        return ans;

    }
    long long sumScores(string s) {
        return z_func(s);
    }
};