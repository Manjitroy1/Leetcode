#define ll long long

class Solution {
  public:
    int getCount(int n) {
        // code here
        int ans=0;
        for(int a=1;a<n;a++){
            ll d = 1LL*2*n + 1LL*a*(a-1);
            d*=4LL;
            d+=1;
            //d must be perfect square
            ll p = sqrt(d);
            if(p*p == d){
                if(p%2 && p>2){
                    int b = (-1+p)/2;
                    if(b>a){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};