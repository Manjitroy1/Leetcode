class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        //number of pair already equal
        int n=nums.size();
        int base=0;
        map<pair<int,int>,int>mpp;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) base++;
            else{
                int a=nums[i];
                int b=nums[i+1];
                if(a>b) swap(a,b);
                mpp[{a,b}]++;
            }
        }
        int ans=0;
        for(auto& node:mpp){
            ans=max(ans,node.second);
        }
        return ans+base;
        
    }
};