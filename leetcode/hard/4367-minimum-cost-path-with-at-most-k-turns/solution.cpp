class Solution {
public:
    struct Node{
        int cost;
        int moves;
        int d;
        int r;
        int c;
    };
    int solve(vector<vector<int>>& grid,vector<pair<int,int>>&direction,int k){
        int n=grid.size();
        int m=grid[0].size();
        // int dis[][][][] r c d moves = store the min cost
        vector<vector<vector<vector<int>>>>dis(n+1,
                vector<vector<vector<int>>>(m+1,
                        vector<vector<int>>(4,
                                vector<int>(k+1,INT_MAX))));

        auto cmp= [](const Node& a,const Node& b){
            return a.cost>b.cost;
        };

        priority_queue<Node,vector<Node>, decltype(cmp)>pq(cmp); //min cost at first

        //first push special case
        for(int dir=0;dir<4;dir++){
            int vr=direction[dir].first;
            int vc=direction[dir].second;
            if(vr<0 || vr>=n || vc<0 || vc>=m) continue;
            
            int cost=grid[0][0]+ grid[vr][vc];
            dis[vr][vc][dir][0]= cost;
            
            pq.push({cost,0,dir,vr,vc});
        }

        while(!pq.empty()){
            auto node= pq.top();
            pq.pop();
            //currently i am at this node
            int cost=node.cost;
            int moves=node.moves;
            int d=node.d;
            int r=node.r;
            int c=node.c;


            if(moves>k) continue;
            if(r==n-1 && c==m-1) return cost;
            
            if(cost!=dis[r][c][d][moves]) continue;

            for(int dir=0;dir<4;dir++){
                int vr=r+ direction[dir].first;
                int vc=c+ direction[dir].second;
                if(vr<0 || vr>=n || vc<0 || vc>=m) continue;

                int newmoves=moves;
                if(d!=dir){
                    newmoves++;
                }
                if(newmoves>k) continue;
                
                int newcost=cost+grid[vr][vc];
                if(newcost<dis[vr][vc][dir][newmoves]){
                    dis[vr][vc][dir][newmoves]=newcost;
                    pq.push({newcost,newmoves,dir,vr,vc});
                }
            }            
        }
        return -1;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1) return grid[0][0];
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}}; //left right down up
        int ans = solve(grid,dir,k);
        
        return ans;
    }
    
};