class Solution {
public:
    int solve(vector<int>&height){
        int n=height.size();
        vector<int>pre(n,0);
        vector<int>suff(n,0);

        int pmx=height[0];
        int smx=height[n-1];
        for(int i=1;i<n;i++){
            int j=n-i-1;
            pre[i]=pmx;
            suff[j]=smx;
            smx=max(smx,height[j]);
            pmx=max(pmx,height[i]);
        }

        // smx=height[n-1];
        // for(int i=n-2;i>=0;i--){
        //     suff[i]=smx;
        //     smx=max(smx,height[i]);
        // }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int curr= height[i];
            if(curr<pre[i] && curr<suff[i]){
                ans+= (min(pre[i],suff[i]) - curr);
            }
        }
        return ans;
    }
    int solveopt(vector<int>&height){
        int n=height.size();
        int l=0;
        int r=n-1;
        int lmx=0;
        int rmx=0;
        int ans=0;
        while(l<r){
            if(height[l]<=height[r]){
                ans+= (lmx-height[l]) >0 ? (lmx-height[l]) : 0;
                lmx=max(lmx, height[l]);
                l++;
            }else{
                ans+= (rmx-height[r]) >0 ? (rmx-height[r]) : 0;
                rmx=max(rmx, height[r]);
                r--;
            }
        }
        return ans;
    }
    int trap(vector<int>& height) {
        return solveopt(height);
    }
};