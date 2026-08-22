class Solution {
public:
    void solve(int idx, int cnt, int& ans,
               vector<vector<int>>& req,
               vector<int>& balance) {

        if(idx == req.size()){
            for(int x : balance){
                if(x != 0) return;
            }

            ans = max(ans, cnt);
            return;
        }

        int from = req[idx][0];
        int to = req[idx][1];

        // Pick this request
        balance[from]++;
        balance[to]--;

        solve(idx + 1, cnt + 1, ans, req, balance);

        balance[from]--;
        balance[to]++;

        // Don't pick this request
        solve(idx + 1, cnt, ans, req, balance);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> balance(n, 0);
        int ans = 0;

        solve(0, 0, ans, requests, balance);

        return ans;
    }
};