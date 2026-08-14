# Minimum Cost Path with Alternating Directions III

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given two integers `m` and `n` representing the number of rows and columns of a grid. Your goal is to reach cell `(m - 1, n - 1)`. You are also given a 2D integer array `penalty`.

The cost to enter cell `(i, j)` is `(i + 1) * (j + 1)`.

You begin at cell `(0, 0)` and initially pay its entrance cost. Actions performed after entering `(0, 0)` are numbered starting from 1.

On each action, you may move to an  **adjacent**  cell or wait in the current cell. A move follows the parity rule if:

- On an odd-numbered action, you move right or down.
- On an even-numbered action, you move left or up.

The cost of an action is determined as follows:

- If you move according to the parity rule, pay only the entrance cost of the destination cell.
- If you move in a direction that violates the parity rule, pay the entrance cost of the destination cell plus penalty[i][j], where (i, j) is the cell you move from.
- If you wait in cell (i, j), pay penalty[i][j].

After every move or wait, the action number increases by 1. Therefore, the required parity alternates after every action, regardless of whether a penalty was paid.

Return the  **minimum**  total cost required to reach `(m - 1, n - 1)`.

 

 **Example 1:** 

 **Input:**  m = 2, n = 2, penalty = [[5,3],[1,4]]

 **Output:**  8

 **Explanation:** 

The optimal path is:

- Start at cell (0, 0) with entry cost (0 + 1) * (0 + 1) = 1.
- Move 1: Move down to cell (1, 0) with entry cost (1 + 1) * (0 + 1) = 2.
- Move 2: Move right to cell (1, 1) with entry cost (1 + 1) * (1 + 1) = 4 and an extra cost of penalty[1][0] = 1 for violating the even parity rule.

Thus, the total cost is `1 + 2 + 4 + 1 = 8`.

 **Example 2:** 

 **Input:**  m = 2, n = 2, penalty = [[0,7],[3,2]]

 **Output:**  7

 **Explanation:** 

The optimal path is:

- Start at cell (0, 0) with entry cost (0 + 1) * (0 + 1) = 1.
- Move 1: Wait at cell (0, 0) with an extra cost of penalty[0][0] = 0 to flip to even parity.
- Move 2: Move right to cell (0, 1) with entry cost (0 + 1) * (1 + 1) = 2 and an extra cost of penalty[0][0] = 0 for violating the even parity rule.
- Move 3: Move down to cell (1, 1) with entry cost (1 + 1) * (1 + 1) = 4.

Thus, the total cost is `1 + 0 + 2 + 0 + 4 = 7`.

 **Example 3:** 

 **Input:**  m = 2, n = 3, penalty = [[8,0,9],[7,4,1]]

 **Output:**  12

 **Explanation:** 

The optimal path is:

- Start at cell (0, 0) with entry cost (0 + 1) * (0 + 1) = 1.
- Move 1: Move right to cell (0, 1) with entry cost (0 + 1) * (1 + 1) = 2.
- Move 2: Move right to cell (0, 2) with entry cost (0 + 1) * (2 + 1) = 3 and an extra cost of penalty[0][1] = 0 for violating the even parity rule.
- Move 3: Move down to cell (1, 2) with entry cost (1 + 1) * (2 + 1) = 6.

Thus, the total cost is `1 + 2 + 3 + 0 + 6 = 12`.

 

 **Constraints:** 

- 1 <= m, n <= 105
- 2 <= m * n <= 105
- penalty.length == m
- penalty[i].length == n
- 0 <= penalty[i][j] <= 105

## Solution

**Language:** C++  
**Runtime:** 816 ms (beats 36.19%)  
**Memory:** 199.3 MB (beats 39.48%)  
**Submitted:** 2026-08-14T09:46:57.463Z  

```cpp
class Solution {
public:

    struct Node {
        long long cost;
        int r, c, parity;

        bool operator>(const Node& other) const {
            return cost > other.cost;
        }
    };

    long long minCost(int n, int m, vector<vector<int>>& penalty) {

        // dist[r][c][parity]
        // parity = 1 -> odd step
        // parity = 0 -> even step
        vector<vector<vector<long long>>> dist(
            n, vector<vector<long long>>(
                m, vector<long long>(2, LLONG_MAX)
            )
        );

        priority_queue<Node, vector<Node>, greater<Node>> pq;

        dist[0][0][1] = 1;
        pq.push({1, 0, 0, 1});

        vector<vector<int>> dir = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        while (!pq.empty()) {

            auto [cost, r, c, parity] = pq.top();
            pq.pop();

            // Already found a better path
            if (cost != dist[r][c][parity])
                continue;

            if (r == n - 1 && c == m - 1)
                return cost;

            long long p = penalty[r][c];

            // Move to another cell
            for (int i = 0; i < 4; i++) {

                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                long long moveCost = 1LL * (nr + 1) * (nc + 1);

                // Add penalty depending on step parity
                if (parity == 1) {
                    if (i >= 2)
                        moveCost += p;
                }
                else {
                    if (i < 2)
                        moveCost += p;
                }

                long long newCost = cost + moveCost;
                int newParity = parity ^ 1;

                if (newCost < dist[nr][nc][newParity]) {
                    dist[nr][nc][newParity] = newCost;
                    pq.push({newCost, nr, nc, newParity});
                }
            }

            // Stay at current cell
            long long newCost = cost + p;
            int newParity = parity ^ 1;

            if (newCost < dist[r][c][newParity]) {
                dist[r][c][newParity] = newCost;
                pq.push({newCost, r, c, newParity});
            }
        }

        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-iii/)