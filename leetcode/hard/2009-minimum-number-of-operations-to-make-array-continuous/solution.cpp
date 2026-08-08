class Solution {
public:
    int solve(vector<int>& nums) {
        int n=nums.size();
        int len=n-1;
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        //this can be the start point
        int l=nums[0];
        int h=nums[n-1];
        int ans=n;

        for(int start=l;start<=h;start++){
            int below= upper_bound(nums.begin(),nums.end(),start)-nums.begin();
            int above= upper_bound(nums.begin(),nums.end(),start+len)-nums.begin();
            if(nums[below-1]!=start){
                below++;
            }
            int right=n-above;
            ans=min(ans,below+right);
        }
        return ans-1;
    }
    int solveopt(vector<int>&nums){
        int n=nums.size();
        sort(nums.begin(),nums.end());

        //arr is sorted an unique elements
        vector<int>arr;
        for(int i=0;i<n;i++){
            if(!arr.empty() && arr.back()==nums[i]) continue;
            arr.push_back(nums[i]);
        }
        int m=arr.size();
        int ans=n;
        for(int i=0;i<m;i++){
            int end= arr[i]+n-1;
            int j= upper_bound(arr.begin(),arr.end(),end)- arr.begin();
            int inside= j-i;
            ans= min(ans,n-inside);
        }
        return ans;
    }
    int minOperations(vector<int>& nums) {
        // return solve(nums);
        return solveopt(nums);
    }
};