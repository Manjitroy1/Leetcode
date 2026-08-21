class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mpp;
        int n=nums.size();

        int sum=0;
        // mpp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            int m=sum/k;
            for(int j=0;j<=m;j++){
                int need= sum - (j*k);
                if(mpp.count(need)) return true;
            }
            mpp[sum]++;
        }
        return false;
    }
};