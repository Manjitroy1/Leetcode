class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long g= __gcd(nums[i],nums[j]);
                long long f=nums[i]/g;
                long long s= nums[j]/g;
                ans= max(ans,f*s);
            }
        }
        return ans;
    }
};