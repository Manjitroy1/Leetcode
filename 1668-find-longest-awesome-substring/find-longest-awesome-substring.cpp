class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size();
        int mask=0;
        unordered_map<int,int>mpp;
        int ans=1;

        for(int i=0;i<n;i++){
            int b= s[i]-'0';
            mask ^= (1<<b);

            if(mpp.count(mask)){
                ans= max(ans,i-mpp[mask]);
            }else mpp[mask]=i;

            if(mask==0 || ((mask & (mask-1)) ==0) ){
                ans= max(ans,i+1);
            }

            for(int pos=0;pos<=10;pos++){
                int newmask = mask ^ (1<<pos);
                if(mpp.count(newmask)){
                    ans=max(ans,i-mpp[newmask]);
                }
            }
        }
        return ans;
        
    }
};