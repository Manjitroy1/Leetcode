class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>pge(n,-1);
        stack<int>stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && nums[i] >= nums[stk.top()]){
                stk.pop();
            }
            pge[i] = stk.empty()? -1: stk.top();
            stk.push(i);
        }
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            //end index is the i
            //start index have to find from mpp
            mpp[nums[i]].push_back(i);
            int pos = pge[i];
            if(pos==-1) ans+= mpp[nums[i]].size();
            else{
                //find the upper bound of pos
                ans+= mpp[nums[i]].end() - upper_bound(mpp[nums[i]].begin(),mpp[nums[i]].end(),pos);
            }
        }
        return ans;
    }
};