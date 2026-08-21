class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int presum=0;
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) presum--;
            else presum++;

            if(mpp.count(presum)){
                ans=max(ans,i-mpp[presum]);
            }else{
                mpp[presum]=i;
            }
        }
        return ans;
    }
};