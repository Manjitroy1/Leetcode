#define ll long long
class Solution {
public:
    const int mod=1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1=0;
        ll sum2=0;
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        int res=0;

        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                sum1= (sum1 + nums1[i++]) % mod;

            }else if(nums1[i]>nums2[j]){
                sum2= (sum2 + nums2[j++]) % mod;
                
            }else{
                res= (res + max(sum1,sum2) + nums1[i] ) % mod;
                i++;
                j++;
                sum1=0,sum2=0;
            }
        }

        while(i<n){
            sum1= (sum1 + nums1[i++]) % mod;
        }
        while(j<m){
            sum2= (sum2 + nums2[j++]) % mod;
        }
        res= (res + max(sum1,sum2)) % mod;
        return res;
    }
};