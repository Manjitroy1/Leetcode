class Solution {
public:
    const int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        if(nums[0]>target) return 0;
        long long ans=0;
        int i=0;
        int j=n-1;

        while(j>=0 && nums[j]>target){
            j--;
        }
        vector<long long>pow2(n,1);
        long long p=1;
        for(int i=1;i<n;i++){
            p= (p*2) % mod;
            pow2[i]=p;
        }
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                int len=j-i;
                // for(int l=1;l<=len;l++){
                //     p= (p*2) % mod;
                // }

                //we have to precompute

                ans = (ans + pow2[len]) % mod;
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};