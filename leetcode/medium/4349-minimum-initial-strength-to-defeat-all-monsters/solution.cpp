class Solution {
public:
    long long minInitialStrength(vector<int>& monsters,
                                  vector<vector<int>>& boosts) {
        
        int n = monsters.size();

        // Difference array to calculate total bonus for every monster
        vector<long long> diff(n, 0);

        for (auto &b : boosts) {
            int l = b[0];
            int r = b[1];
            int v = b[2];

            diff[l] += v;

            if (r + 1 < n)
                diff[r + 1] -= v;
        }

        long long answer = 0;
        long long prefix = 0;
        long long bonus = 0;

        for (int i = 0; i < n; i++) {

            // Calculate bonus applicable to monster i
            bonus += diff[i];

            // Actual strength required for this monster
            long long need = monsters[i] - bonus;

            if (need > 0) {
                answer = max(answer, prefix + need);
            }

            // This monster will decrease our actual strength
            prefix += monsters[i];
        }

        return answer;
    }
};