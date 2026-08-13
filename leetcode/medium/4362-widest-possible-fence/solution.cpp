class Solution {
public:
    int maximumWidth(vector<int>& planks) {

        unordered_map<int, int> freq;

        for(int x : planks) {
            freq[x]++;
        }

        // All distinct plank heights
        vector<int> vals;

        for(auto &it : freq) {
            vals.push_back(it.first);
        }

        // pairs[h] = number of planks of height h
        // that we can make by joining two planks
        unordered_map<int, long long> pairs;

        int ans = 0;

        // We can directly use planks having the same height
        for(auto &it : freq) {
            ans = max(ans, it.second);
        }

        int k = vals.size();

        for(int i = 0; i < k; i++) {

            for(int j = i; j < k; j++) {

                int x = vals[i];
                int y = vals[j];

                int height = x + y;

                long long cnt;

                if(x == y) {
                    // Need two different planks
                    cnt = freq[x] / 2;
                }
                else {
                    cnt = min(freq[x], freq[y]);
                }

                // Multiple pairs can produce the same height,
                // so add their contributions.
                pairs[height] += cnt;
            }
        }

        // Now combine:
        // original planks of height h
        // + planks created by joining two planks to get h
        for(auto &it : pairs) {

            int height = it.first;

            long long total = it.second;

            if(freq.count(height)) {
                total += freq[height];
            }

            ans = max(ans, (int)total);
        }

        return ans;
    }
};