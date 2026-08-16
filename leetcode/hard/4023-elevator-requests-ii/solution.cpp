class Solution {
public:
    long long dp[1501][1501][2];

    long long recc(int l, int r, vector<int>& requests,
                   int side, int start) {

        // base case
        if (l == 0 && r == requests.size() - 1) {
            return 0;
        }

        if (dp[l][r][side] != -1)
            return dp[l][r][side];

        long long ans = LLONG_MAX;

        int curr = side == 0 ? requests[l] : requests[r];

        long long time = 0;

        if (side == 0) {
            // start -> requests[r] -> requests[l]
            time = 1LL * (requests[r] - start)
                 + (requests[r] - requests[l]);
        }
        else {
            // start -> requests[l] -> requests[r]
            time = 1LL * (start - requests[l])
                 + (requests[r] - requests[l]);
        }

        // go to l-1
        if (l > 0) {

            long long next = requests[l - 1];

            long long newtime =
                time + abs(curr - next);

            long long cost =
                newtime +
                recc(l - 1, r, requests, 0, start);

            ans = min(ans, cost);
        }

        // go to r+1
        if (r + 1 < requests.size()) {

            long long next = requests[r + 1];

            long long newtime =
                time + abs(curr - next);

            long long cost =
                newtime +
                recc(l, r + 1, requests, 1, start);

            ans = min(ans, cost);
        }

        return dp[l][r][side] = ans;
    }

    long long elevatorRequests(int n, int start,
                               vector<int>& requests) {

        bool flag = false;

        for (const int& r : requests) {
            if (r == start) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            requests.push_back(start);
        }

        sort(requests.begin(), requests.end());

        int s = lower_bound(
            requests.begin(),
            requests.end(),
            start
        ) - requests.begin();

        memset(dp, -1, sizeof(dp));

        int side = 0;

        return recc(s, s, requests, side, start);
    }
};