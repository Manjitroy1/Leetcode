class Solution {
public:
    int calc(pair<int,int>&p1,pair<int,int>&p2,int x3,int y3){
        int x1= p1.first;
        int x2= p2.first;

        int y1= p1.second;
        int y2= p2.second;

        return (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>>result;

        //conver hull
        sort(trees.begin(),trees.end());
        //first one is the first selected one
        
        deque<pair<int,int>>lower,upper;

        for(auto& points:trees){
            int x =points[0];
            int y =points[1];

            int l=lower.size();
            int u=upper.size();

            while(l>=2 && calc(lower[l-2],lower[l-1],x,y) < 0){ //p1,p2,p3
                //we have to remove p2
                lower.pop_back();
                l--;
            }
            while(u>=2 && calc(upper[u-2],upper[u-1],x,y) > 0){
                upper.pop_back();
                u--;
            }
            lower.push_back({x,y});
            upper.push_back({x,y});
        }

        set<pair<int,int>>stt;
        for(auto& points:lower){
            stt.insert(points);
        }
        for(auto& points:upper){
            stt.insert(points);
        }
        for(auto& points :stt){
            result.push_back({points.first,points.second});
        }
        return result;
    }
};