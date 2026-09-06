#define ll long long
class Solution {
public:
    // int brute(vector<int>& nums) {
    //     int n=nums.size();
    //     int m=2*n;
        
    //     ll pref=0;
    //     ll suff=0;
        
    //     for(int i=0;i<n;i++){
    //         if(i<n/2) pref+=nums[i];
    //         else suff+=nums[i];
    //     }
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
            
    //         if(pref>suff) cnt++;
            
    //         int j=(i+n)%n;
    //         int k=(i+(n/2))%n;
            
    //         pref-=nums[i];
    //         pref+=nums[k];
    //         suff-=nums[k];
    //         suff+=nums[j];   
    //     }
    //     return cnt;
    // }
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        ll pref=0;
        ll total=0;
        int len=n/2; //half
        
        for(int i=0;i<n;i++){
            total+=nums[i];
            if(i<len) pref+=nums[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(2*pref>total){
                cnt++;
            }
            pref-=nums[i];
            pref+=nums[(i+len) % n];
        }
        return cnt;
    }
};