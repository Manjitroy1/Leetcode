class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        if(n==0) return 0;
        int ans=1;

        unordered_map<int,int>mpp; //num-->max cnt
        mpp[arr[0]]=1;
        for(int i=1;i<n;i++){
            int prev = arr[i]-d;
            
            if(mpp.count(prev)){
                mpp[arr[i]] = 1 + mpp[prev];
            }else{
                mpp[arr[i]] = 1;
            }
            ans= max(ans, mpp[arr[i]]);
        }
        return ans;
    }
};