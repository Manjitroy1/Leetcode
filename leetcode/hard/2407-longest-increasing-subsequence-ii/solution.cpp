class SGT{
public:
    vector<int>sgt;
    int h;
    
    SGT(int n){
        h = n;
        sgt.resize(4*n+1);
    }

    void update(int idx,int low,int high,int pos,int val){
        if(low==high){
            sgt[idx]=val;
            return;
        }
        int mid= low+ (high-low)/2;
        if(pos<=mid) update(2*idx+1,low,mid,pos,val);
        else update(2*idx+2,mid+1,high,pos,val);

        sgt[idx] = max(sgt[2*idx+1],sgt[2*idx+2]);
    }
    int query(int idx, int low,int high,int l,int r){
        //no overlap low high l r .... l r low high
        if(high<l || r<low) return -1e9;
        
        //complete l  low high r
        if(l<=low && high<=r){
            return sgt[idx];
        }
        int mid= low+ (high-low)/2;
        int left= query(2*idx+1, low, mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);

        return max(left,right);
    }
    void update(int pos,int val){
        update(0,0,h-1,pos,val);

    }
    int query(int l,int r){
        return query(0,0,h-1,l,r);
    }
};
class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,1);
        
        int ans=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && nums[i] - nums[j] <= k && dp[i] < 1+dp[j]){
                    dp[i] = 1+ dp[j];
                    ans= max(ans,dp[i]);
                }
            }
        }
        return ans;
    }

    //using segment tree we can get maximum value in that range
    int lengthOfLIS(vector<int>& nums, int k) {
        int n=nums.size();
        int total = 1e5+1;
        SGT first(total);

        vector<int>dp(n,0);
        int ans=1;
        for(int i=0;i<n;i++){
            int v= nums[i];

            int left= max(0,v-k);
            int right = v-1;
            int mx= first.query(left,right); //maximum value in this range

            if(dp[i] < 1+mx){
                dp[i]= 1+mx;
                ans= max(ans,dp[i]);
                first.update(v,dp[i]);
            }
        }
        return ans;
    }
};