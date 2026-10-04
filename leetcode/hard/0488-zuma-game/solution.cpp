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