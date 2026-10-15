class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int>>dp(n,vector<int>(2,1e9));
        // dp[i][swap] = minimum number of swaps so that 0 to i is in strictly incrasing order
        dp[0][0] = 0; //we did not swap
        dp[0][1] = 1; //we swapped 0 index

        for(int i=1;i<n;i++){
            for(int s=0;s<2;s++){ //let s denote previos ones swap not swap
                if(s==0){//prev one not swapped
                    //this one swap
                    if(nums1[i-1] < nums2[i] && nums2[i-1]< nums1[i]){
                        dp[i][1] = min(dp[i][1], 1 + dp[i-1][0]);
                    }
                    //this not swap
                    if(nums1[i-1] < nums1[i] && nums2[i-1]< nums2[i]){
                        dp[i][0] = min(dp[i][0], dp[i-1][0]);
                    }

                }
                else{ // prev is swapped
                    //this not swap
                    if(nums2[i-1]< nums1[i] && nums1[i-1]< nums2[i]){
                        dp[i][0] = min(dp[i][0], dp[i-1][1]);
                    }
                    //this swap
                    if(nums2[i-1] < nums2[i] && nums1[i-1] < nums1[i]){
                        dp[i][1] = min(dp[i][1], 1 + dp[i-1][1]);
                    }

                }
            }
        } 
        return min(dp[n-1][0],dp[n-1][1]);
    }
};