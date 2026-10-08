class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //sorted by their x coordinates
        vector<pair<int,int>>events;
        vector<vector<int>>ans;

        for(auto& node : buildings){
            int s=node[0];
            int e=node[1];
            int h=node[2];
            
            events.push_back({s,h});
            events.push_back({e,-h});
        }
        sort(events.begin(),events.end());

        //we want at this x the maximum active height we have
        multiset<int>stt; //can hold multiple values
        stt.insert(0);
        int prev=0;
        int i=0;
        
        while(i<events.size()){
            int x= events[i].first;
            while(i<events.size() && events[i].first==x){
                int h=events[i].second;

                if(h>0){
                    stt.insert(h);
                }else{  
                    stt.erase(stt.find(-h)); //to delete one instance
                }
                i++;
            }
            int mxh=*stt.rbegin();
            if(mxh!=prev){
                ans.push_back({x,mxh});
                prev=mxh;
            }

        }
        return ans;
    }
};