#define ll long long
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        ll ans=0;
        int l=0;
        multiset<int>stt;
        for(int r=0;r<n;r++){
            stt.insert(nums[r]);
            int mn= *stt.begin();
            int mx = *prev(stt.end());

            while(l<r && !stt.empty() && (mx-mn)>2){
                auto it = stt.find(nums[l]);
                stt.erase(it);
                l++;
                mn= *stt.begin();
                mx = *prev(stt.end());
            }
            ans += (r-l+1)*1LL;        
        }
        return ans;
    }
};