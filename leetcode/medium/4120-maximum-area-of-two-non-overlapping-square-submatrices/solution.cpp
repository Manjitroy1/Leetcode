class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // up[i][j] = largest square ending at (i,j)
        vector<vector<int>> up(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0)
                    continue;

                if (i == 0 || j == 0) {
                    up[i][j] = 1;
                }
                else {
                    up[i][j] = 1 + min({
                        up[i-1][j],
                        up[i][j-1],
                        up[i-1][j-1]
                    });
                }
            }
        }

        // down[i][j] = largest square starting at (i,j)
        vector<vector<int>> down(n, vector<int>(m, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (mat[i][j] == 0)
                    continue;

                if (i == n - 1 || j == m - 1) {
                    down[i][j] = 1;
                }
                else {
                    down[i][j] = 1 + min({
                        down[i+1][j],
                        down[i][j+1],
                        down[i+1][j+1]
                    });
                }
            }
        }

        int ans = 0;

        /*
            CASE 1:
            Two squares are separated vertically.

            left square  | right square
                         |
        */

        vector<int> left(m, 0);
        vector<int> right(m, 0);

        // Largest square completely contained in columns [0 ... j]
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                left[j] = max(left[j], up[i][j]);
            }

            if (j > 0)
                left[j] = max(left[j], left[j-1]);
        }

        // Largest square completely contained in columns [j ... m-1]
        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                right[j] = max(right[j], down[i][j]);
            }

            if (j + 1 < m)
                right[j] = max(right[j], right[j+1]);
        }

        // Split between j and j+1
        for (int j = 0; j < m - 1; j++) {
            int k = min(left[j], right[j+1]);
            ans = max(ans, k);
        }


        /*
            CASE 2:
            Two squares are separated horizontally.

            top
            ---
            bottom
        */

        vector<int> top(n, 0);
        vector<int> bottom(n, 0);

        // Largest square completely contained in rows [0 ... i]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                top[i] = max(top[i], up[i][j]);
            }

            if (i > 0)
                top[i] = max(top[i], top[i-1]);
        }

        // Largest square completely contained in rows [i ... n-1]
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                bottom[i] = max(bottom[i], down[i][j]);
            }

            if (i + 1 < n)
                bottom[i] = max(bottom[i], bottom[i+1]);
        }

        // Split between i and i+1
        for (int i = 0; i < n - 1; i++) {
            int k = min(top[i], bottom[i+1]);
            ans = max(ans, k);
        }

        return ans * ans;
    }
};