class Solution {
public:
    int brute(vector<int>& nums, int k) {
        int n=nums.size();
        // vector<int>mx(n,0);
        vector<int>mn(n,INT_MAX);
        
        // mx[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     mx[i]=max(mx[i-1],nums[i]);
        // }
        mn[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            mn[i]=min(mn[i+1],nums[i]);
        }
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            if(mx-mn[i]<=k){
                return i;
            }

        }
        return -1;
    }

    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        return brute(nums,k);
        
    }
};