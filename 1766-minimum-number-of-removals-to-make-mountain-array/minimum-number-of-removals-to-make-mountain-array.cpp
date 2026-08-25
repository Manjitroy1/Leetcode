class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>prev(n,0);
        vector<int>next(n,0);

        prev[0]=1;
        next[n-1]=1;

        for(int i=1;i<n;i++){
            int mx=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    mx= max(mx,prev[j]);
                }
            }
            prev[i]=1+mx;
        }

        for(int i=n-2;i>=0;i--){
            int mx=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[i]){
                    mx=max(mx,next[j]);
                }
            }
            next[i]=1+mx;
        }
        int ans=0;
        int i=1;
        while(i<n && nums[i-1]>=nums[i]){
            i++;
        }
        int j=n-2;
        while(j>0 && nums[j+1]>=nums[j]){
            j--;
        }

        if(j<i) return n-1;

        for(int k=i;k<=j;k++){
            ans=max(ans,prev[k]+next[k]);
        }
        return n-ans+1;
    }
};