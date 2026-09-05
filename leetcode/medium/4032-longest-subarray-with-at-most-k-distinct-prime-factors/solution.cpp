class Solution {
public:
    int total=1e5+1;
    vector<int>prime;

    void minprimefactor(vector<int>&prime){
        int n=prime.size();
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i<n;i++){
            prime[i]=i;
        }
        for(int i=2;i*i<n;i++){
            if(prime[i]==i){
                
                for(int j=i*i;j<n;j+=i){
                    if(prime[j]==1) prime[j]=i;
                }
            }else continue;
        }
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        prime=vector<int>(total,1);
        minprimefactor(prime);

        //i have to store each num factors
        vector<vector<int>>factors;
        
        for(int i=0;i<n;i++){
            vector<int>store;
            int num=nums[i];

            while(num>1){
                int f=prime[num];
                store.push_back(f);
                
                while(num%f==0){
                    num/=f;
                }
            }
            factors.push_back(store);
        }

        // i have factors of each
        //we need map
        unordered_map<int,int>mpp;
        int l=0;
        int r=0;
        //we need atmost k prime factors
        while(r<n){
            for(int pf:factors[r]){
                mpp[pf]++;
            }
            while(mpp.size()>k){
                //we will reduce the size
                //remove all the factors of num
                for(int pf:factors[l]){
                    mpp[pf]--;
                    if(mpp[pf]==0) mpp.erase(pf);
                }
                l++;
            }
            //now we have size less than k
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};