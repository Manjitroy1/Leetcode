class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            if(nums[i]) arr.push_back(i);
        }
        for(int i=0;i<arr.size();i++){
            arr[i] = arr[i]-i;
        }
        long long ans=INT_MAX;
        for(int i=0;i+k<=arr.size();i++){
            int mid= i + k/2;
            long long cost =0;
            for(int j=i;j<i+k;j++){
                cost+=abs(arr[j]-arr[mid]);
            }
            ans=min(ans,cost);
        }
        return (int)ans;
    }
};