class Solution {
public:
    string solve(int num){
        string s="";
        for(int i=31;i>=0;i--){
            if((num>>i) & 1){
                if(i>=25){
                    s+='z';
                }else{
                    s+=(i+'a');
                }
            }
        }
        return s;
    }
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        for(int i=0;i<nums.size();i++){
            string s=solve(nums[i]);
            ans.push_back(s);
        }
        return ans;
    }
};