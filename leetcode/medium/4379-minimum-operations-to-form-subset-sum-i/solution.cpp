class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        //for each number 
        //we will have this possibility 
        //check for other possibility
        //store the minimum
        
        unordered_map<int,int>dp;
        dp[0]=0;
        
        for(int i=0;i<n;i++){
            int num=nums[i];

            unordered_map<int,int>newdp;
            //currect must inlcude the previous also
            newdp=dp;
            
            //what we already have
            for(auto node:dp){
                int s=node.first;
                int step=node.second;

                //use num as it is
                int total = s+num;
                if(total<=sum){
                    int tillstep = newdp.count(total)? newdp[total]:1e9;
                    newdp[total] = min(tillstep,step);
                }
                
                //multiply
                int scount=0;
                long long curr=nums[i];
                while(curr*2<=sum){
                    
                    curr*=2;
                    scount++;
                    
                    long long newval = curr+s;
                    if(newval<=sum){
                        int tillstep = newdp.count(newval)? newdp[newval]:1e9;
                        newdp[newval]=min(tillstep,step+scount);
                    }
                    
                }
                //devide
                curr=nums[i];
                scount=0;
                while(curr/2 >=1){
                    curr/=2;
                    scount++;
                    int newval = curr+s;
                    if(newval<=sum){
                        int tillstep = newdp.count(newval)? newdp[newval]:1e9;
                        newdp[newval]=min(tillstep,step+scount);
                    }
                }
            }
            dp=newdp;
        }
        if(!dp.count(sum)) return -1;

        return dp[sum];
    }
};