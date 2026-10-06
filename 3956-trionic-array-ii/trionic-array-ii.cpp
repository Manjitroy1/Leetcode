#define ll long long
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        //increasing decreasing increasing
        //up1 = maximum increasing subarry
        //down = inceasing + currently deacreaing
        // up2= increasing + decreasing + currenlty increasing
        const ll NEG= LLONG_MIN/4;
        int n=nums.size();
        ll ans=NEG;

        ll up1=NEG;
        ll up2=NEG;
        ll dn=NEG;


        for(int i=1;i<n;i++){
            ll x=nums[i-1];
            ll y=nums[i];

            if(x<y){
                //increasing
                up1=max(up1,x)+y;
                up2=max(up2,dn)+y;
                dn=NEG;

                ans=max(ans,up2);
            }
            else if(x>y){
                // decrasing
                dn=max(up1,dn)+y;
                up1=NEG;
                up2=NEG;
            }else{
                //straight
                up1=up2=dn=NEG;
            }
        }
        return ans;
    }
};