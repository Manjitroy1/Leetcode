class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
         int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        
        int ans=0;
        for(int i=0;i<n;i++){
            int b=intervals[i][1];
            
            for(int j=i+1;j<n;j++){
                int c=intervals[j][0];
                if(b>=c){
                    ans++;
                }
            }
        }
        return ans;
    }
};