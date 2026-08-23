class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countPalindromicSubsequences(string s) {

        int n = s.size();

        // next[i] = next occurrence of s[i]
        vector<int> next(n, -1);

        // prev[i] = previous occurrence of s[i]
        vector<int> prev(n, -1);

        vector<int> pos(4, -1);

        // Find next occurrence
        for(int i = n - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            if(pos[c] != -1)
                next[i] = pos[c];

            pos[c] = i;
        }

        // Reset
        fill(pos.begin(), pos.end(), -1);

        // Find previous occurrence
        for(int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            if(pos[c] != -1)
                prev[i] = pos[c];

            pos[c] = i;
        }

        // dp[i][j] = number of distinct palindromic
        // subsequences in s[i...j]
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // Every single character is a palindrome
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Build for increasing substring length
        for(int i = n - 2; i >= 0; i--) {

            for(int j = i + 1; j < n; j++) {

                if(s[i] != s[j]) {

                    // Union of:
                    // dp[i+1][j]
                    // dp[i][j-1]
                    //
                    // dp[i+1][j-1] was counted twice
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                }

                else {

                    int l = next[i];
                    int r = prev[j];

                    if(l > r) {
                        // No same character inside
                        dp[i][j] =
                            (2LL * dp[i + 1][j - 1] + 2) % MOD;
                    }
                    else if(l == r) {
                        // Exactly one same character inside
                        dp[i][j] =
                            (2LL * dp[i + 1][j - 1] + 1) % MOD;
                    }
                    else {
                        // At least two same characters inside
                        dp[i][j] = (2LL * dp[i + 1][j - 1] - dp[l+1][r-1] + MOD) % MOD;
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};