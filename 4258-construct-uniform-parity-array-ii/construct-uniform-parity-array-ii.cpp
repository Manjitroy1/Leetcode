class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool even=true;
        bool odd=true;
        int n=nums1.size();
        ///store the odd
        // vector<int>store;
        int mno=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums1[i]%2==1){
                even=false;
                mno=min(mno,nums1[i]);
            }
            if(nums1[i]%2==0) odd=false;
        }

        if(even || odd) return true;

        for(int i = 0; i < n; i++) {

            if(nums1[i] % 2 == 0) {

                bool mn = (mn<INT_MAX)? (nums1[i] - mno) >= 1 :  false;
                if(!mn) return false;
            }
        }

        return true;  // FIX
    }
};