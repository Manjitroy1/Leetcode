class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        stack<int>stk;
        long long ans=0;

        // num[i] is the minimum in range i to j
        for(int i=0;i<n;i++){
            while(!stk.empty() && stk.top()>nums[i]){
                freq[stk.top()]--;
                stk.pop();
            }
            //number of elemts less thatn equal to nums [i] - freq of[i]
            ans+=(stk.size()-freq[nums[i]]);
            freq[nums[i]]++;
            stk.push(nums[i]);
        }
        return ans;
        
    }
};