# Maximum Number of Events That Can Be Attended II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array of `events` where `events[i] = [startDayi, endDayi, valuei]`. The `ith` event starts at `startDayi` and ends at `endDayi`, and if you attend this event, you will receive a value of `valuei`. You are also given an integer `k` which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the  **entire**  event. Note that the end day is  **inclusive** : that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return  *the  **maximum sum**  of values that you can receive by attending events.* 

 

 **Example 1:** 

```
Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
```

 **Example 2:** 

```
Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
```

 **Example 3:** 

```
Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
```

 

 **Constraints:** 

- 1 <= k <= events.length
- 1 <= k * events.length <= 106
- 1 <= startDayi <= endDayi <= 109
- 1 <= valuei <= 106

## Solution

**Language:** C++  
**Runtime:** 171 ms (beats 68.97%)  
**Memory:** 156.9 MB (beats 91.96%)  
**Submitted:** 2026-10-16T13:58:23.857Z  

```cpp
class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    int solve(vector<vector<int>>& events, int idx, int start) {
        int l = 0, h = idx - 1;
        int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (events[mid][1] < start) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans;
    }

    int maxValue(vector<vector<int>>& events, int K) {
        int n = events.size();

        sort(events.begin(), events.end(), comp);

        // dp[i][k] = maximum value using events [0...i],
        // selecting at most k events
        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        for (int i = 0; i < n; i++) {
            int ub = solve(events, i, events[i][0]);

            for (int k = 1; k <= K; k++) {
                // Do not take current event
                if (i > 0) {
                    dp[i][k] = dp[i - 1][k];
                }

                // Take current event
                int take = events[i][2];

                if (ub != -1) {
                    take += dp[ub][k - 1];
                }

                dp[i][k] = max(dp[i][k], take);
            }
        }

        return dp[n - 1][K];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)