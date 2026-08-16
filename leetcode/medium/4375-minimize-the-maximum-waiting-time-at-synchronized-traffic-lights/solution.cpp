class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
     int mx=*max_element(lights.begin(),lights.end());
     
        int n=arrivalTime.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int r= arrivalTime[i] % period;
            if(r>=mx){
                ans=max(ans, period-r);
            }
        }
        return ans;
    }
};