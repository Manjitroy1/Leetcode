class Solution {
public:
    int solve(vector<int>&nums){
        int n=nums.size();
        if(n<=1)return 0;
        if(n==2) (nums[0]==nums[1])? 1:0;
        int cnt=0;
        vector<int>pref(n);
        vector<int>suff(n);
        pref[0]=nums[0];
        suff[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            pref[i]=__gcd(pref[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=__gcd(suff[i+1],nums[i]);
        }

        for(int i=0;i<n-1;i++){
            if(pref[i]==suff[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
    int maxValidSplits(vector<int>& nums) {
        int ans=solve(nums);
        int n=nums.size();
        
        for(int r=0;r<n;r++){
            vector<int>arr;
            for(int i=0;i<n;i++){
                if(r!=i){
                    arr.push_back(nums[i]);
                }
            }
            int now=solve(arr);
            ans=max(ans,now);
            
        }
        return ans;
    }
};