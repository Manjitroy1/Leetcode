class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        //store the index of remainder that comes earliest
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;

            if(mpp.count(rem)){
                if(i-mpp[rem] >=2) return true;
            }
            else{
                mpp[rem]=i;
            }
        }
        
        return false;
    }
};