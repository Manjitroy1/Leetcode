
class Solution {
public:
    vector<int> solve(vector<int>& nums, int s) {
        int n = nums.size();
        const int INF = n + 1;

        // suff[i][j] = minimum number of primes from i to n-1
        // needed to form sum j.
        vector<vector<int>> suff(
            n + 1, vector<int>(s + 1, INF)
        );

        suff[n][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= s; j++) {
                // Do not pick nums[i]
                suff[i][j] = suff[i + 1][j];

                // Pick nums[i]
                if (nums[i] <= j &&
                    suff[i + 1][j - nums[i]] != INF) {
                    suff[i][j] = min(
                        suff[i][j],
                        1 + suff[i + 1][j - nums[i]]
                    );
                }
            }
        }

        // Find maximum achievable sum
        int mx = 0;
        for (int j = s; j >= 1; j--) {
            if (suff[0][j] != INF) {
                mx = j;
                break;
            }
        }

        if (mx == 0) return {};

        // Greedy reconstruction for lexicographically smallest array
        int rem = mx;
        int need = suff[0][mx];
        vector<int> ans;

        for (int i = 0; i < n && need > 0; i++) {
            int x = nums[i];

            if (rem >= x &&
                suff[i + 1][rem - x] == need - 1) {
                ans.push_back(x);
                rem -= x;
                need--;
            }
        }

        return ans;
    }

    vector<int> maxPrimeSubset(int n, int s) {
        if (n < 2 || s < 2) return {};

        // Sieve of Eratosthenes
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;

        for (int i = 2; 1LL * i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        vector<int> store;
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                store.push_back(i);
            }
        }

        return solve(store, s);
    }
};
