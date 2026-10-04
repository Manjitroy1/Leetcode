# Zuma Game

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are playing a variation of the game Zuma.

In this variation of Zuma, there is a  **single row**  of colored balls on a board, where each ball can be colored red `'R'`, yellow `'Y'`, blue `'B'`, green `'G'`, or white `'W'`. You also have several colored balls in your hand.

Your goal is to  **clear all**  of the balls from the board. On each turn:

- Pick any ball from your hand and insert it in between two balls in the row or on either end of the row.
- If there is a group of three or more consecutive balls of the same color, remove the group of balls from the board. If this removal causes more groups of three or more of the same color to form, then continue removing each group until there are none left.
- If there are no more balls on the board, then you win the game.
- Repeat this process until you either win or do not have any more balls in your hand.

Given a string `board`, representing the row of balls on the board, and a string `hand`, representing the balls in your hand, return  *the  **minimum**  number of balls you have to insert to clear all the balls from the board. If you cannot clear all the balls from the board using the balls in your hand, return* `-1`.

 

 **Example 1:** 

```
Input: board = "WRRBBW", hand = "RB"
Output: -1
Explanation: It is impossible to clear all the balls. The best you can do is:
- Insert 'R' so the board becomes WRRRBBW. WRRRBBW -> WBBW.
- Insert 'B' so the board becomes WBBBW. WBBBW -> WW.
There are still balls remaining on the board, and you are out of balls to insert.
```

 **Example 2:** 

```
Input: board = "WWRRBBWW", hand = "WRBRW"
Output: 2
Explanation: To make the board empty:
- Insert 'R' so the board becomes WWRRRBBWW. WWRRRBBWW -> WWBBWW.
- Insert 'B' so the board becomes WWBBBWW. WWBBBWW -> WWWW -> empty.
2 balls from your hand were needed to clear the board.

```

 **Example 3:** 

```
Input: board = "G", hand = "GGGGG"
Output: 2
Explanation: To make the board empty:
- Insert 'G' so the board becomes GG.
- Insert 'G' so the board becomes GGG. GGG -> empty.
2 balls from your hand were needed to clear the board.

```

 

 **Constraints:** 

- 1 <= board.length <= 16
- 1 <= hand.length <= 5
- board and hand consist of the characters 'R', 'Y', 'B', 'G', and 'W'.
- The initial row of balls on the board will not have any groups of three or more consecutive balls of the same color.

## Solution

**Language:** C++  
**Runtime:** 1768 ms (beats 5.00%)  
**Memory:** 305.5 MB (beats 5.80%)  
**Submitted:** 2026-10-04T17:37:16.380Z  

```cpp
class Solution {
public:

    // Remove every group of 3 or more.
    // Repeat because removals can create new groups.
    string shrink(string s) {

        bool changed = true;

        while (changed) {

            changed = false;
            string t;

            int n = s.size();
            int i = 0;

            while (i < n) {

                int j = i;

                // Find group [i, j)
                while (j < n && s[j] == s[i]) {
                    j++;
                }

                int len = j - i;

                if (len >= 3) {
                    // Remove this group
                    changed = true;
                }
                else {
                    // Keep this group
                    t += s.substr(i, len);
                }

                i = j;
            }

            s = t;
        }

        return s;
    }


    unordered_map<string, int> memo;


    // Create unique representation of:
    // board + cnt[5]
    string getKey(const string& board, vector<int>& cnt) {

        string key = board;

        for (int i = 0; i < 5; i++) {
            key.push_back('#');
            key.push_back('0' + cnt[i]);
        }

        return key;
    }


    int dfs(string& board, vector<int>& cnt) {

        if (board.empty()) {
            return 0;
        }

        string key = getKey(board, cnt);

        if (memo.count(key)) {
            return memo[key];
        }

        int ans = 100;


        // 5 possible colors
        for (int color = 0; color < 5; color++) {

            if (cnt[color] == 0) {
                continue;
            }

            char c;

            if (color == 0) c = 'R';
            if (color == 1) c = 'Y';
            if (color == 2) c = 'B';
            if (color == 3) c = 'G';
            if (color == 4) c = 'W';


            // Use one ball
            cnt[color]--;


            int n = board.size();

            // Try every insertion position
            for (int i = 0; i <= n; i++) {

                bool useful = false;


                // Case 1:
                // New ball touches same color on left
                if (i > 0 && board[i - 1] == c) {
                    useful = true;
                }


                // Case 2:
                // New ball touches same color on right
                if (i < n && board[i] == c) {
                    useful = true;
                }


                // Case 3:
                // We insert a DIFFERENT color between
                // two equal-colored balls.
                //
                // Example:
                // RR -> RBR
                //
                // This is necessary for:
                // RRWWRRBBRR, hand = WB
                if (i > 0 && i < n &&
                    board[i - 1] == board[i]) {
                    useful = true;
                }


                if (!useful) {
                    continue;
                }


                // Insert c at position i
                string newBoard =
                    board.substr(0, i) +
                    c +
                    board.substr(i);


                // Remove groups + chain reactions
                newBoard = shrink(newBoard);


                int res = dfs(newBoard, cnt);

                if (res != 100) {
                    ans = min(ans, 1 + res);
                }
            }


            // Backtrack
            cnt[color]++;
        }


        return memo[key] = ans;
    }


    int findMinStep(string board, string hand) {

        vector<int> cnt(5, 0);


        // Build frequency array
        for (char c : hand) {

            if (c == 'R') cnt[0]++;
            else if (c == 'Y') cnt[1]++;
            else if (c == 'B') cnt[2]++;
            else if (c == 'G') cnt[3]++;
            else if (c == 'W') cnt[4]++;
        }


        memo.clear();

        int ans = dfs(board, cnt);

        if (ans >= 100) {
            return -1;
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/zuma-game/)