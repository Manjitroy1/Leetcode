class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    int solve(vector<vector<int>>& events, int idx, int start) {
        int l = 0, h = idx - 1;
        int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (events[mid][1] < start) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans;
    }

    int maxValue(vector<vector<int>>& events, int K) {
        int n = events.size();

        sort(events.begin(), events.end(), comp);

        // dp[i][k] = maximum value using events [0...i],
        // selecting at most k events
        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        for (int i = 0; i < n; i++) {
            int ub = solve(events, i, events[i][0]);

            for (int k = 1; k <= K; k++) {
                // Do not take current event
                if (i > 0) {
                    dp[i][k] = dp[i - 1][k];
                }

                // Take current event
                int take = events[i][2];

                if (ub != -1) {
                    take += dp[ub][k - 1];
                }

                dp[i][k] = max(dp[i][k], take);
            }
        }

        return dp[n - 1][K];
    }
};