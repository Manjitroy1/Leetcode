class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool>flip(n,false);
        int flipcount=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i>=k && flip[i-k]){
                flipcount--;
            }

            if(flipcount%2==nums[i]){
                if(i+k>n) return -1;
                //we have to flip
                flip[i]=true;
                flipcount++;
                ans++;
            }
        }
        return ans;
    }
};