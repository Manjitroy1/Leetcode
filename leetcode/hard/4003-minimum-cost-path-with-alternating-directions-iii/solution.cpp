class Solution {
public:

    struct Node {
        long long cost;
        int r, c, parity;

        bool operator>(const Node& other) const {
            return cost > other.cost;
        }
    };

    long long minCost(int n, int m, vector<vector<int>>& penalty) {

        // dist[r][c][parity]
        // parity = 1 -> odd step
        // parity = 0 -> even step
        vector<vector<vector<long long>>> dist(
            n, vector<vector<long long>>(
                m, vector<long long>(2, LLONG_MAX)
            )
        );

        priority_queue<Node, vector<Node>, greater<Node>> pq;

        dist[0][0][1] = 1;
        pq.push({1, 0, 0, 1});

        vector<vector<int>> dir = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        while (!pq.empty()) {

            auto [cost, r, c, parity] = pq.top();
            pq.pop();

            // Already found a better path
            if (cost != dist[r][c][parity])
                continue;

            if (r == n - 1 && c == m - 1)
                return cost;

            long long p = penalty[r][c];

            // Move to another cell
            for (int i = 0; i < 4; i++) {

                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                long long moveCost = 1LL * (nr + 1) * (nc + 1);

                // Add penalty depending on step parity
                if (parity == 1) {
                    if (i >= 2)
                        moveCost += p;
                }
                else {
                    if (i < 2)
                        moveCost += p;
                }

                long long newCost = cost + moveCost;
                int newParity = parity ^ 1;

                if (newCost < dist[nr][nc][newParity]) {
                    dist[nr][nc][newParity] = newCost;
                    pq.push({newCost, nr, nc, newParity});
                }
            }

            // Stay at current cell
            long long newCost = cost + p;
            int newParity = parity ^ 1;

            if (newCost < dist[r][c][newParity]) {
                dist[r][c][newParity] = newCost;
                pq.push({newCost, r, c, newParity});
            }
        }

        return -1;
    }
};