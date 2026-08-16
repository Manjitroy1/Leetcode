class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int dis=INT_MAX;
        int n=drones.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int x=drones[i][0];
            int y=drones[i][1];
            int r=drones[i][2];
            int d= abs(target[0]-x) + abs(target[1]-y);

            // if(d<dis && r>=d){
            //     dis=d;
            //     ans=i;
            // }
            if(r>=d){
                if(d<dis){
                    dis=d;
                    ans=i;
                }
            }
        }
        return ans;
    }
};