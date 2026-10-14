class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        for(int& x:nums){
            x%=k;
        }
        int n=nums.size();

        int l=0;
        int r=0;
        int ans=1;
        
        while(r<n){
            int rem = nums[l];
            while(r<n && nums[r]==rem){
                if(rem*(r-l) % k ==0){
                    ans= max(ans,r-l+1);
                }
                r++;
            }
            l=r;
        }
        return ans;
    }
};