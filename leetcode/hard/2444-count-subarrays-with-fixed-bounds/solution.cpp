class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left=0;
        long long cnt =0;
        int n= nums.size();

        deque<int>dqmn,dqmx;
        for(int i=0;i<n;i++){
            // out of regin case
            if(nums[i]<minK || nums[i]>maxK){
                left= i+1;
                dqmn.clear();
                dqmx.clear();
                continue;
            }

            //maintain monotonic queue
            while(!dqmn.empty() && nums[dqmn.back()] >= nums[i]) dqmn.pop_back();
            dqmn.push_back(i); 

            while(!dqmx.empty() && nums[dqmx.back()] <= nums[i]) dqmx.pop_back();
            dqmx.push_back(i);

            //calculate the ans

            if(!dqmn.empty() && !dqmx.empty()){
                if(nums[dqmn.front()]==minK && nums[dqmx.front()]==maxK){
                    int start = min(dqmn.front(),dqmx.front());
                    cnt+=1LL*(start-left+1);
                }
            } 
        }
        return cnt;
        
    }
};