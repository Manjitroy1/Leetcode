class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int ans=0;
        unordered_map<int,int>presum;
        unordered_map<int,int>diff;
        
        while(r<n){
            int x=nums[r];
            bool invalid= ( presum[x]>0 || diff[x]>0 );

            while(l<r && invalid){
                //remove l
                int val=nums[l];
                for(int i=l+1;i<r;i++){
                    presum[val+nums[i]]--;
                    int md=abs(nums[l]-nums[i]);
                    diff[md]--;
                    
                    if(presum[val+nums[i]]==0) presum.erase(val+nums[i]);
                    if(diff[md]==0) diff.erase(md);
                }
                l++;
                
                invalid= ( presum[x]>0 || diff[x]>0 );
            }
            ans=max(ans,r-l+1);

            //insert the value in both the mp
            int val=nums[r];
            for(int i=l;i<r;i++){
                presum[val+nums[i]]++;
                int md=abs(nums[i]-nums[r]);
                diff[md]++;
            }
            
            r++;
        }
        return ans;
    }
};