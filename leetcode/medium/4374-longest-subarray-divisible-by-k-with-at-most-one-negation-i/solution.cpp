class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i] = ((nums[i]%k) + k)%k;
        }
        int ans=0;
        vector<int>seen(k,0);
        
        for(int i=0;i<n;i++){
            int sum=0;
            vector<int>newvals;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                
                int rem=sum%k;
                int val=(2*nums[j])%k;
                newvals.push_back(val);
                
                seen[val]++;
                if(rem==0 || seen[rem]>0){
                    ans=max(ans,j-i+1);
                }
            }
            for(int v:newvals){
                seen[v]--;
            }
        }
        return ans;
    }
};