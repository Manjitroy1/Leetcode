class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>>ans;
        
        map<int,int>mp;
        map<int,int>mpp;

        set<int>times;

        for(int i=0;i<series1.size();i++){
            int k=series1[i][0];
            int v=series1[i][1];
            mp[k]=v;
            times.insert(k);
        }

         for(int i=0;i<series2.size();i++){
            int k=series2[i][0];
            int v=series2[i][1];
            mpp[k]=v;
            times.insert(k);
        }

        for(int t:times){
            auto it1=mp.lower_bound(t);
            auto it2=mpp.lower_bound(t);

            int v1=0;
            if(it1!=mp.end()){
                v1=it1->second;
            }
            int v2=0;
            if(it2!=mpp.end()){
                v2=it2->second;
            }
            ans.push_back({t,v1+v2});
        }
        return ans;
    }
};