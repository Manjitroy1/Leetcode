class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        mpp[0]=1;
        int presum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remove = presum-k;
            ans+=mpp[remove];
            mpp[presum]++;
        }
        return ans;
    }
};