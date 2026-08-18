class Solution {
public:
    int dp[20][2][2][1 << 10];

    int countways(int pos, int tight, int started, int mask, vector<int>& digit) {
        if(pos == digit.size()) {
            // We don't count 0
            return started ? 1 : 0;
        }

        if(dp[pos][tight][started][mask] != -1)
            return dp[pos][tight][started][mask];

        int limit = tight ? digit[pos] : 9;
        int res = 0;

        for(int d = 0; d <= limit; d++) {

            int newtight = tight && (d == digit[pos]);

            // Still dealing with leading zeroes
            if(!started && d == 0) {
                res += countways(pos + 1, newtight, 0, mask, digit);
            }
            else {

                // This digit is already used
                if(mask & (1 << d))
                    continue;

                int newmask = mask | (1 << d);

                res += countways(pos + 1,newtight, 1, newmask, digit );
            }
        }

        return dp[pos][tight][started][mask] = res;
    }

    int solve(int n, vector<int>& digit) {
        while(n) {
            digit.push_back(n % 10);
            n /= 10;
        }

        reverse(digit.begin(), digit.end());

        memset(dp, -1, sizeof(dp));

        return countways(0, 1, 0, 0, digit);
    }

    int numDupDigitsAtMostN(int n) {
        vector<int>digit;
        int unique = solve(n,digit);

        return n - unique;
    }
};