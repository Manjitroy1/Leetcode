class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>maxrange(n+1,0);
        for(int i=0;i<n+1;i++){
            int l = max(0,i-ranges[i]);
            int r = min(n,i+ranges[i]);

            maxrange[l] = max(maxrange[l],r);
            //i have tap range from 2 to 3 
            // i have another tap range 2 to 5 
            //in short we can say i have a tap of range 2 to 5
            // l = each initial start (2)
        }
        int maxreach=0; //we have the change to go that max
        int currreach=0; //with the current number of tap we can go till that
        int tap=0;

        // if somehow i is greater than maxreach return -1
        for(int i=0;i<=n;i++){
            if(i>maxreach) return -1;
            if(i>currreach){
                tap++;
                currreach =  maxreach;
            }
            maxreach = max(maxreach,maxrange[i]);
        }
        return tap;
    }
};