class Solution {
public:
    double binary(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();  // i want n to be small to operate in nums1
        int m=nums2.size();
        if(n>m) return binary(nums2,nums1);
        double ans=0.0;

        int l=0;
        int h=n;
        int left = (n+m+1)/2;

        while(l<=h){
            int mid1= l + (h-l)/2;
            int mid2= left - mid1;

            int l1 = mid1-1 >=0 ? nums1[mid1-1]: INT_MIN;
            int l2=  mid2-1 >=0 ?  nums2[mid2-1] : INT_MIN;

            int r1 = mid1 < n ? nums1[mid1]: INT_MAX;
            int r2= mid2 < m ? nums2[mid2]: INT_MAX;

            if(l1<=r2 && l2<=r1){
                if((n+m) % 2==1){
                    ans= max(l1,l2);
                }else{
                    ans= (max(l1,l2)+ min(r1,r2))/2.0;
                }
                return ans;
            }else if(l2>r1){
                l=mid1+1;
            }else{
                h=mid1-1;
            }

        }
        return ans;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return binary(nums1,nums2);
    }
};