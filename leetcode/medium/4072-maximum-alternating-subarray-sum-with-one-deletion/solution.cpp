// class Solution {
// public:
//     long long maxAlternatingSum(vector<int>& nums) {
//         const long long NEG = LLONG_MIN / 4;

//         // States represent the expected sign of the NEXT kept element.
//         //
//         // plus0  : No deletion used, next kept element gets '+'.
//         // minus0 : No deletion used, next kept element gets '-'.
//         // plus1  : One deletion used, next kept element gets '+'.
//         // minus1 : One deletion used, next kept element gets '-'.

//         long long plus0 = NEG, minus0 = NEG;
//         long long plus1 = NEG, minus1 = NEG;

//         long long ans = NEG;

//         for (int x : nums) {
//             // Save previous states so every transition uses old values.
//             long long p0 = plus0;
//             long long m0 = minus0;
//             long long p1 = plus1;
//             long long m1 = minus1;

//             // No deletion used:
//             // If the next sign is '-', subtract x; next sign becomes '+'.
//             plus0 = m0 - 1LL * x;

//             // If the next sign is '+', add x; next sign becomes '-'.
//             // Or start a new subarray with x.
//             minus0 = max(1LL * x, p0 + 1LL * x);

//             // One deletion used:
//             // Keep x with a '-' sign, or delete x while expecting '+'.
//             plus1 = max(m1 - 1LL * x, p0);

//             // Keep x with a '+' sign, or delete x while expecting '-'.
//             minus1 = max(p1 + 1LL * x, m0);

//             // Find the maximum valid alternating sum.
//             ans = max({ans, plus0, minus0, plus1, minus1});
//         }

//         return ans;
//     }
// };


class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 4;

        // dp[i][parity][isDel]
        // parity = 0: next kept element gets '+'
        // parity = 1: next kept element gets '-'
        // isDel = 0: no deletion used
        // isDel = 1: one deletion used
        vector<vector<vector<long long>>> dp(
            n,
            vector<vector<long long>>(2, vector<long long>(2, NEG))
        );

        long long ans = NEG;

        for (int i = 0; i < n; i++) {
            long long x = nums[i];

            // Start a new subarray at index i.
            // The first element always gets a positive sign.
            // After keeping it, the next sign must be negative.
            dp[i][1][0] = max(dp[i][1][0], x);

            // Process states from the previous index.
            if (i > 0) {
                for (int parity = 0; parity < 2; parity++) {
                    for (int isDel = 0; isDel < 2; isDel++) {
                        long long prev = dp[i - 1][parity][isDel];

                        // Ignore unreachable states.
                        if (prev == NEG) continue;

                        // Choice 1: Keep nums[i].
                        // parity 0 => add x
                        // parity 1 => subtract x
                        long long val = (parity == 0)
                                            ? prev + x
                                            : prev - x;

                        // Keeping an element flips the next expected sign.
                        dp[i][1 - parity][isDel] =
                            max(dp[i][1 - parity][isDel], val);

                        // Choice 2: Delete nums[i].
                        // Allowed only if deletion has not been used.
                        // The sum and parity remain unchanged.
                        if (isDel == 0) {
                            dp[i][parity][1] =
                                max(dp[i][parity][1], prev);
                        }
                    }
                }
            }

            // The answer may end at any index, with or without deletion.
            for (int parity = 0; parity < 2; parity++) {
                for (int isDel = 0; isDel < 2; isDel++) {
                    ans = max(ans, dp[i][parity][isDel]);
                }
            }
        }

        return ans;
    }
};
