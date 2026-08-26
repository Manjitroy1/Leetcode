class Solution {
public:
    int n;
    vector<int> bit;
    const long long mod=1e9+7;

    void update(int id, int val) {
        while (id <= n) {
            bit[id] += val;
            id += id & -id;
        }
    }

    int query(int id) {
        int ans = 0;

        while (id > 0) {
            ans += bit[id];
            id -= id & -id;
        }

        return ans;
    }

    int createSortedArray(vector<int>& ins) {
        n = 100000;  // maximum value in ins
        bit.assign(n + 1, 0);

        long long ans = 0;

        for (int i = 0; i < ins.size(); i++) {
            int x = ins[i];

            // Previous elements strictly smaller than x
            int smaller = query(x - 1);

            // Previous elements strictly greater than x
            int greater = i - query(x);

            ans = (ans + min(smaller, greater))%mod;

            // Insert current value
            update(x, 1);
        }

        return ans;
    }
};