class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        vector<int>depth(n);
        
        vector<vector<int>>adj(n);
        int height=1;
        depth[0]=1;
        
        for(int i=1;i<n;i++){
            int j=parent[i];
            adj[j].push_back(i);
        }

        queue<int>q;
        q.push(0);

        while(!q.empty()){
            int u= q.front();
            q.pop();

            for(int v:adj[u]){
                depth[v] = 1+ depth[u];
                height =max(height,depth[v]);
                q.push(v);
            }
        }
        
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=1LL*nums[i] * (height-depth[i]+1);
        }
        return ans;
    }
};