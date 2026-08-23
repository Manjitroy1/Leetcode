# Count Different Palindromic Subsequences

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string s, return  *the number of different non-empty palindromic subsequences in*  `s`. Since the answer may be very large, return it  **modulo**  `109 + 7`.

A subsequence of a string is obtained by deleting zero or more characters from the string.

A sequence is palindromic if it is equal to the sequence reversed.

Two sequences `a1, a2,...` and `b1, b2,...` are different if there is some `i` for which `ai != bi`.

 

 **Example 1:** 

```
Input: s = "bccb"
Output: 6
Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.

```

 **Example 2:** 

```
Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
Output: 104860361
Explanation: There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 109 + 7.

```

 

 **Constraints:** 

- 1 <= s.length <= 1000
- s[i] is either 'a', 'b', 'c', or 'd'.

## Solution

**Language:** C++  
**Runtime:** 42 ms (beats 96.36%)  
**Memory:** 68.9 MB (beats 23.75%)  
**Submitted:** 2026-08-23T10:49:00.550Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/count-different-palindromic-subsequences/)