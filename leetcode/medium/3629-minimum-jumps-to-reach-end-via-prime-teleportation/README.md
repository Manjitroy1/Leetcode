# Minimum Jumps to Reach End via Prime Teleportation

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` of length `n`.

You start at index 0, and your goal is to reach index `n - 1`.

From any index `i`, you may perform one of the following operations:

- Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
- Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.

Return the  **minimum**  number of jumps required to reach index `n - 1`.

 

 **Example 1:** 

 **Input:**  nums = [1,2,4,6]

 **Output:**  2

 **Explanation:** 

One optimal sequence of jumps is:

- Start at index i = 0. Take an adjacent step to index 1.
- At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to index i = 3 as nums[3] = 6 is divisible by 2.

Thus, the answer is 2.

 **Example 2:** 

 **Input:**  nums = [2,3,4,7,9]

 **Output:**  2

 **Explanation:** 

One optimal sequence of jumps is:

- Start at index i = 0. Take an adjacent step to index i = 1.
- At index i = 1, nums[1] = 3 is a prime number. Therefore, we teleport to index i = 4 since nums[4] = 9 is divisible by 3.

Thus, the answer is 2.

 **Example 3:** 

 **Input:**  nums = [4,6,5,8]

 **Output:**  3

 **Explanation:** 

- Since no teleportation is possible, we move through 0 → 1 → 2 → 3. Thus, the answer is 3.

 

 **Constraints:** 

- 1 <= n == nums.length <= 105
- 1 <= nums[i] <= 106

## Solution

**Language:** C++  
**Runtime:** 409 ms (beats 79.13%)  
**Memory:** 338.3 MB (beats 41.95%)  
**Submitted:** 2026-09-30T09:23:12.936Z  

```cpp
class Solution {
public:
    int minJumps(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        int MAX = *max_element(nums.begin(), nums.end());

        // SPF
        vector<int> spf(MAX + 1);

        for (int i = 0; i <= MAX; i++)
            spf[i] = i;

        for (int i = 2; 1LL * i * i <= MAX; i++) {

            if (spf[i] == i) {

                for (int j = i * i; j <= MAX; j += i) {

                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        // prime -> indices whose value is divisible by prime
        unordered_map<int, vector<int>> store;

        for (int i = 0; i < n; i++) {

            int x = nums[i];

            while (x > 1) {

                int p = spf[x];

                store[p].push_back(i);

                // remove duplicate factor
                while (x % p == 0)
                    x /= p;
            }
        }

        vector<int> dist(n, -1);
        vector<bool> used(MAX + 1, false);

        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            if (u == n - 1)
                return dist[u];

            // right
            if (u + 1 < n && dist[u + 1] == -1) {

                dist[u + 1] = dist[u] + 1;
                q.push(u + 1);
            }

            // left
            if (u > 0 && dist[u - 1] == -1) {

                dist[u - 1] = dist[u] + 1;
                q.push(u - 1);
            }

            // teleport
            int p = nums[u];

            if (p >= 2 && spf[p] == p && !used[p]) {

                used[p] = true;

                for (int v : store[p]) {

                    if (dist[v] == -1) {

                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/)