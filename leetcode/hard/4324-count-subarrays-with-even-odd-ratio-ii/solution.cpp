class Solution {
public:
    long long  merge(int low,int mid,int high,vector<long long>&pre){
        long long cnt=0;
        vector<long long>temp;
        int l=low;
        int r=mid+1;
        while(l<=mid && r<=high){
            if(pre[l]<=pre[r]){
                cnt+=(high-r+1);
                temp.push_back(pre[l]);
                l++;
            }else{
                temp.push_back(pre[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(pre[l]);
            l++;
        }
        while(r<=high){
            temp.push_back(pre[r]);
            r++;

        }
        for(int i=low;i<=high;i++){
            pre[i] = temp[i-low];
        }
        return cnt;
        
    }
    
    long long mergetech(int low,int high,vector<long long>&pre){
        if(low>=high) return 0;
        
        long long cnt=0;
        if(low<high){
            int mid= low + (high-low)/2;
            
            cnt+=mergetech(low,mid,pre);
            cnt+=mergetech(mid+1,high,pre);
            cnt+=merge(low,mid,high,pre);
        }
        return cnt;
    }
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int g = __gcd(a,b);
        a/=g;
        b/=g;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0)  nums[i]= -b;  //even then neg
            else nums[i]=a;   //odd then pos
        }

        vector<long long>pre(n+1,0);

        for(int i=0;i<n;i++){
            pre[i+1] = nums[i] + pre[i];
        }

        return mergetech(0,n,pre);
    }
};