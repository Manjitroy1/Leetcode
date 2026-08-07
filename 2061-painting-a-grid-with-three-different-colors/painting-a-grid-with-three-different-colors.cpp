class Solution {
public:
    const int MOD= 1e9+7;
    vector<vector<int>>states;
    vector<vector<int>>adj; //graph to store compatibility

    void generate(int idx,int m,vector<int>&curr){
        if(idx>=m){
            states.push_back(curr);
            return;
        }
        for(int c=0;c<3;c++){
            if(idx>=1 && curr[idx-1]==c) continue;
            curr.push_back(c);
            generate(idx+1,m,curr);
            curr.pop_back();
        }
        
    }
    bool compatibility(vector<int>&a, vector<int>&b){
        int m=a.size();
        for(int j=0;j<m;j++){
            if(a[j]==b[j]) return false;
        }
        return true;
    }
    void graph(){
        int s= states.size();
        adj.resize(s);
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                if(compatibility(states[i],states[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }

    int colorTheGrid(int m, int n) {
        //generates states of m boxes
        vector<int>curr;
        generate(0,m,curr);
        graph();
        int S=states.size();
        //now we have adj matrix
        vector<long long> dp(S, 1), ndp(S);

        // Process remaining columns
        for (int col = 1; col < n; col++) {

            fill(ndp.begin(), ndp.end(), 0);

            for (int prev = 0; prev < S; prev++) {

                for (int nxt : adj[prev]) {

                    ndp[nxt] = (ndp[nxt] + dp[prev]) % MOD;
                }
            }

            dp = ndp;
        }

        long long ans = 0;

        for (long long x : dp)
            ans = (ans + x) % MOD;

        return ans;
    }
};