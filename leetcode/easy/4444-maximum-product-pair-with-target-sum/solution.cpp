class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int>p = {-1,-1};
        int n=nums.size();

        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]) continue;
                if(nums[i]+nums[j]==target){
                    if(ans < (nums[i]*nums[j])){
                        ans = nums[i]*nums[j];
                        if(nums[i]>nums[j])
                            p={i,j};
                        else p= {j,i};
                    }
                }
            }
        }
        return p;
    }
};