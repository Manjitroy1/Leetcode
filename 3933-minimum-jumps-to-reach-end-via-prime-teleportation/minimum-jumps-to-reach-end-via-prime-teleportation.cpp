class Solution {
public:
    int minJumps(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        int MAX = *max_element(nums.begin(), nums.end());

        // SPF
        vector<int> spf(MAX + 1);

        for (int i = 0; i <= MAX; i++)
            spf[i] = i;

        for (int i = 2; 1LL * i * i <= MAX; i++) {

            if (spf[i] == i) {

                for (int j = i * i; j <= MAX; j += i) {

                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        // prime -> indices whose value is divisible by prime
        unordered_map<int, vector<int>> store;

        for (int i = 0; i < n; i++) {

            int x = nums[i];

            while (x > 1) {

                int p = spf[x];

                store[p].push_back(i);

                // remove duplicate factor
                while (x % p == 0)
                    x /= p;
            }
        }

        vector<int> dist(n, -1);
        vector<bool> used(MAX + 1, false);

        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            if (u == n - 1)
                return dist[u];

            // right
            if (u + 1 < n && dist[u + 1] == -1) {

                dist[u + 1] = dist[u] + 1;
                q.push(u + 1);
            }

            // left
            if (u > 0 && dist[u - 1] == -1) {

                dist[u - 1] = dist[u] + 1;
                q.push(u - 1);
            }

            // teleport
            int p = nums[u];

            if (p >= 2 && spf[p] == p && !used[p]) {

                used[p] = true;

                for (int v : store[p]) {

                    if (dist[v] == -1) {

                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        return -1;
    }
};