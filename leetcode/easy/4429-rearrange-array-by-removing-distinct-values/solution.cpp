class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int>freq;
        for(int& e:nums){
            freq[e]++;
        }
        vector<int>ans;
        while(!freq.empty()){

            int l=ans.size();
            
            for(auto& node:freq){
                ans.push_back(node.first);
            }
            
            int r=ans.size();
            for(int i=l;i<r;i++){
                freq[ans[i]]--;
                if(freq[ans[i]]==0) freq.erase(ans[i]);
            }
        }
        return ans;
    }
};