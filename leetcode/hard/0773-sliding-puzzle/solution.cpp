class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>>adj={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        // [[1,3],[0,2,4],[1,5],[0,4],[1,3,5],[2,4]];

        // unordered_map<string,int>mpp;
        string target="123450";
        // mpp[target]=0;
        set<string>vis;

        queue<string>q;

        string start="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                start+=(board[i][j] + '0');
            }
        }
        int step=0;
        if(start==target) return step;

        q.push(start);
        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                string curr=q.front();
                q.pop();
                //if we reach the target
                if(curr==target) return step;

                //we have to find the 0
                int u = curr.find('0');

                for(int v: adj[u]){
                    string next=curr;
                    swap(next[u],next[v]);

                    if(!vis.count(next)){
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};