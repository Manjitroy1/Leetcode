# Numbers With Repeated Digits

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an integer `n`, return  *the number of positive integers in the range* `[1, n]` *that have  **at least one**  repeated digit*.

 

 **Example 1:** 

```
Input: n = 20
Output: 1
Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.

```

 **Example 2:** 

```
Input: n = 100
Output: 10
Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.

```

 **Example 3:** 

```
Input: n = 1000
Output: 262

```

 

 **Constraints:** 

- 1 <= n <= 109

## Solution

**Language:** C++  
**Runtime:** 10 ms (beats 55.29%)  
**Memory:** 8.4 MB (beats 34.31%)  
**Submitted:** 2026-08-18T13:44:13.768Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/numbers-with-repeated-digits/)