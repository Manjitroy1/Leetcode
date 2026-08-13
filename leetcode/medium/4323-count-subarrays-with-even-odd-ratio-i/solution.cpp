class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<int>odd(n,0);
        vector<int>even(n,0);
        
        nums[0]%2==0 ? even[0]=1: odd[0]=1;
        
        for(int i=1;i<n;i++){
            if(nums[i]%2==0){
                even[i]= 1+ even[i-1];
                odd[i]= odd[i-1];
            }else{
                odd[i] = 1+ odd[i-1];
                even[i]=even[i-1];
            }
        }
        int cnt=0;
        double act=(double)a/(double)(b);
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int e= i>0?  even[j]- even[i-1] : even[j];
                int o= i>0 ? odd[j]- odd[i-1] : odd[j];
                
                
                if(o>0){
                    double curr=(double)e/(double)(o);
                    if(curr<=act) cnt++;
                }
            }
        }
        return cnt;
        
    }
};