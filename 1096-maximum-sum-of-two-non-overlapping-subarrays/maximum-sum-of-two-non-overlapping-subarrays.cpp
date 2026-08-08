class Solution {
public:
    int func(int first,int second,vector<int>&presum){
        int n=presum.size();
        // first of L window
        int ans=0;
        int bestfirst=0;
        for(int i=first-1;i<n-second;i++){
            int fmx= presum[i] - (i-first>=0 ? presum[i-first] : 0 );
            int smx= presum[i+second] - presum[i]; 

            bestfirst=max(bestfirst,fmx);
            ans= max(ans, bestfirst+smx);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        if(nums.size() == firstLen + secondLen){
            return accumulate(nums.begin(),nums.end(),0);
        }
        int n=nums.size();

        vector<int>presum(n);
        presum[0]=nums[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1] + nums[i];
        }
        int f =func(firstLen,secondLen,presum);  //first second
        int s =func(secondLen,firstLen,presum);
        return max(f,s);

    }
};