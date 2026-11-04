
#define ll long long

class Solution {
public:
    const ll mod = 1e9 + 7;

    int sumOfGoodSubsequences(vector<int>& nums) {

        unordered_map<int, ll> cnt, sum;

        ll ans = 0;

        for (int v : nums) {

            ll ways = 1;
            ll curr = v;

            if (cnt.count(v - 1)) {
                ways = (ways + cnt[v - 1]) % mod;

                curr = (curr + sum[v - 1]
                        + v * cnt[v - 1]) % mod;
            }

            if (cnt.count(v + 1)) {
                ways = (ways + cnt[v + 1]) % mod;

                curr = (curr + sum[v + 1]
                        + v * cnt[v + 1]) % mod;
            }

            cnt[v] = (cnt[v] + ways) % mod;
            sum[v] = (sum[v] + curr) % mod;

            ans = (ans + curr) % mod;
        }

        return ans;
    }
};
