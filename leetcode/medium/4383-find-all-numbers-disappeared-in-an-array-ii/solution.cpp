class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        // if(upper<nums[0] || lowe>nums[n-1]) return {{lower,upper}};
        int sz=upper-lower+1;
        vector<int>temp(sz);
        
        for(int i=0;i<sz;i++){
            temp[i]=lower+i;
        }
        for(int i=0;i<n;i++){
            if(lower<=nums[i] && nums[i]<=upper){
                int idx= nums[i]-lower;
                temp[idx]=0;
            }
        }
        int first=-1;
        int second=-1;
        for(int i=0;i<sz;i++){
            if(temp[i]!=0 && first==-1) first=temp[i];
            if(first!=-1 && temp[i]==0 && second==-1) ans.push_back({first});
            
            if(temp[i]!=0 && first!=-1) second=temp[i];
            if(first!=-1 && second!=-1 && temp[i]==0){
                ans.push_back({first,second});
                first=-1;
                second=-1;
            }
        }
        if(first!=-1 && second!=-1) ans.push_back({first,second});

        return ans;
    }
};