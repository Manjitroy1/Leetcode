class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> curr = mat[0];
        if (curr.size() > k)
            curr.resize(k);

        for (int i = 1; i < m; i++) {
            vector<int> temp;

            // Merge current smallest sums with the current row
            for (int sum : curr) {
                for (int j = 0; j < n; j++) {
                    temp.push_back(sum + mat[i][j]);
                }
            }

            sort(temp.begin(), temp.end());

            // Keep only the first k smallest sums
            if (temp.size() > k)
                temp.resize(k);

            curr = temp;
        }

        return curr[k - 1];
    }
};