# Q4. Prime Subset Selection II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given two integers `n` and `s`.

Consider all  **prime**  numbers less than or equal to `n`. Select a  **subset**  of these primes such that:

- Each prime can be selected at most once.
- The sum of the selected primes is as large as possible while remaining less than or equal to s.
- Among subsets with the maximum sum, select one containing the fewest primes.
- If multiple subsets remain tied, select the one whose elements, written in increasing order, form the lexicographically smallest array.

Return an integer array containing the selected primes in  **increasing**  order. If no valid  **non-empty**  subset exists, return an empty array.

 

 **Example 1:** 

 **Input:**  n = 7, s = 20

 **Output:**  [2, 3, 5, 7]

 **Explanation:** 

- The prime numbers less than or equal to n = 7 are 2, 3, 5, and 7.
- The sum of all these primes is 2 + 3 + 5 + 7 = 17, which is less than or equal to s = 20.
- Thus, the answer is [2, 3, 5, 7].

 **Example 2:** 

 **Input:**  n = 15, s = 18

 **Output:**  [5,13]

 **Explanation:** 

- The prime numbers less than or equal to 15 are 2, 3, 5, 7, 11, and 13.
- The subsets with sum 18 are [5, 13], [7, 11], [2, 3, 13], and [2, 5, 11]. Since this sum equals s, it is the maximum possible sum.
- Among these subsets, [5, 13] and [7, 11] contain the fewest primes: two.
- Between these two subsets, [5, 13] is lexicographically smaller because its first element, 5, is smaller than 7. Thus, the answer is [5, 13].

 **Example 3:** 

 **Input:**  n = 5, s = 1

 **Output:**  []

 **Explanation:** 

- The smallest prime number is 2, which is greater than s = 1.
- Thus, no prime can be selected, so the answer is an empty array.

 

 **Constraints:** 

- 1 <= n <= 1000
- 1 <= s <= 1000

## Solution

**Language:** C++  
**Runtime:** 86 ms (beats 67.84%)  
**Memory:** 58.4 MB (beats 77.53%)  
**Submitted:** 2026-10-14T18:13:59.765Z  

```cpp

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

```

---

[View on LeetCode](https://leetcode.com/problems/prime-subset-selection-ii/)