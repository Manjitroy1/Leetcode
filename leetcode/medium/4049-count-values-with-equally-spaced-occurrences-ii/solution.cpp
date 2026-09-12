class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp;
        int n=nums.size();

        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        int ans=0;
        
        for(auto& node:mpp){
            vector<int>temp=node.second;
            int s=temp.size();
            if(s<3)continue;
            int gap=temp[1]-temp[0];

            bool flag=true;
            for(int i=2;i<s && flag;i++){
                if(temp[i]-temp[i-1] != gap){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
        
    }
};