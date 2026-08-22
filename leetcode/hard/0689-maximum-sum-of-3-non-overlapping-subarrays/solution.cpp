class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ksum;
        

        int sum = accumulate(nums.begin(),nums.begin()+k,0);
        ksum.push_back(sum);
        int l=0;
        int r=k;
        while(r<n){
            sum-=nums[l];
            sum+=nums[r];
            l++;
            r++;
            ksum.push_back(sum);
        }  
        int ks=ksum.size();
        vector<int>left(ks,0);
        vector<int>right(ks,0);

        int best=0;
        for(int i=0;i<ks;i++){
            if(ksum[i]>ksum[best]){
                best=i;
            }
            left[i] = best;
        }     

        best=ks-1;
        for(int i=ks-1;i>=0;i--){
            if(ksum[i]>=ksum[best]){
                best=i;
            }
            right[i]=best;
        } 

        vector<int>result(3,0);
        int mxsum=0;

        for(int i=k;i<ks-k;i++){
            int leftidx= left[i-k];
            int rightidx= right[i+k];
            int total= ksum[leftidx] + ksum[i] + ksum[rightidx];
            if(total>mxsum){
                mxsum=total;
                result={leftidx,i,rightidx};
            }
        }

        return result;

    }
};