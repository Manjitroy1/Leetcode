#define ll long long
class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        //sweep line
        vector<vector<int>>events;
        
        for(auto& node:intervals){
            int s=node[0];
            int e=node[1];
            events.push_back({s,0});
            events.push_back({e,1});
        }
        sort(events.begin(),events.end());
        ll active=0;
        ll ans=0;
        
        for(auto&node : events){
            int x= node[0];
            int type=node[1];
            if(type==0){
                ans+=active;
                active++;
            }else{
                active--;
            }
        }
        return ans;
    }
};