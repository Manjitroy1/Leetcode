class Solution {
public:
    int brute(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,-1e9);
        int ans=-1e9;
        for(int i=0;i<n;i++){
            int now=0;
            for(int left=max(0,i-k);left<i;left++){
                now= max(now,dp[left]);
            }
            dp[i]= nums[i] + now;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        using t= pair<int,int>; // {dp[i],i}
        priority_queue<t>pq;
        
        int ans=-1e9;
        for(int i=0;i<n;i++){
            if(!pq.empty()){
                while(!pq.empty() && pq.top().second < (i-k)){
                    pq.pop();
                }
            }
            int now=0;
            if(!pq.empty()){
                int currtop=pq.top().first;
                now= max(now,currtop);
            }
            int curr=now+nums[i];
            ans=max(ans,now+nums[i]);
            pq.push({curr,i});
        }

        return ans;
    }
};