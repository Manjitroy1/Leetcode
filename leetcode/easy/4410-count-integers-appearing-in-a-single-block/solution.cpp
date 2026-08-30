class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>bucket(101);
        for(int i=0;i<n;i++){
            bucket[nums[i]].push_back(i);
        }
        int cnt=0;
        
        for(int i=1;i<bucket.size();i++){
            if(!bucket[i].empty()){
                int sz=bucket[i].size();
                if(sz==1){
                    cnt++;
                    continue;
                }
                bool flag=true;
                for(int j=1;j<sz;j++){
                    if(bucket[i][j-1]+1 !=bucket[i][j]){
                        flag=false;
                    }
                }
                if(flag) cnt++;
            }
        }
        return cnt;
    }
};