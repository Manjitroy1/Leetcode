class Solution {
public:
    vector<int>solve2(vector<int>&nums){
        int n=nums.size();
        int mask=(1<<15)-1;
        vector<int>ans(15,0);
        
        int times=15;
        vector<bool>used(n,false);
        while(times--){
            
            int cnt=0;
            for(int i=0;i<n;i++){
                if(used[i]) continue;
                if((nums[i] & mask) == mask){
                    used[i]=true;
                    cnt++;
                }
            }
            for(int j=14;j>=0;j--){
                if((mask>>j) &1){
                    ans[14-j]+=cnt;
                }
            }
            //now can i find the best
            int bestidx=-1;
            int best=0;
            for(int i=0;i<n;i++){
                if(used[i]) continue;
                if((nums[i]&mask)>best){
                    best=(nums[i] & mask);
                    // best=nums[i];
                    bestidx=i;
                }
            }
            mask&=best;
            if(bestidx!=-1) used[bestidx]=true;
            for(int j=14;j>=0;j--){
                if((mask>>j) &1){
                    ans[14-j]++;
                }
            }
        }
        return ans;
    }
    vector<int> largestPower(vector<int>& nums) {
        
        //n^2
        //we have mask of 15 set bit initially
        //check with all the unused num
        //which give me best value
        //we will use that num
        //mark that as used
        return solve2(nums);

         // TC:: 15*n   
        //our mask will change for 15 times
        //so first check for all num such that mask& num==mask
        //we will perform on them 
        // then check changes our maxk with best popcount
        //uses that and change the mask
        // repeat for 15 times
    }
};