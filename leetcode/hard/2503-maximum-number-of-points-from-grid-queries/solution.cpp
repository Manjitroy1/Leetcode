class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();
        int qs=queries.size();
    
        vector<pair<int,int>>q;

        for(int i=0;i<qs;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        
        vector<int>ans(qs,0);
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        using t=tuple<int,int,int>;
        priority_queue<t,vector<t>,greater<t>>pq; //value of grid r c
        pq.push({grid[0][0],0,0});
        vis[0][0]=true;

        int cnt=0;
        //for each query process
        for(auto& [val,idx] : q){
            while(!pq.empty() && get<0>(pq.top()) < val){
                auto [gval,r,c]=pq.top();
                pq.pop();
                cnt++;

                for(auto d:dir){
                    int vr= r+ d.first;
                    int vc= c+ d.second;
                    if(vr>=0 && vr<n && vc>=0 && vc<m && !vis[vr][vc]){
                        pq.push({grid[vr][vc],vr,vc});
                        vis[vr][vc]=true;
                    }
                }
            }
            ans[idx]=cnt;

        }
        return ans;
    }
};