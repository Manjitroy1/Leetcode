class Solution {
public:

    bool dfs(int i, int j, int pos, string& word,
             vector<vector<char>>& board,
             vector<string>& ans) {

        int n = board.size();
        int m = board[0].size();

        // Entire word matched
        if(pos >= word.size()){
            ans.push_back(word);
            return true;
        }

        // Current character doesn't match
        if(word[pos] != board[i][j])
            return false;

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int d = 0; d < 4; d++){

            int vr = i + dr[d];
            int vc = j + dc[d];

            if(vr >= 0 && vr < n &&
               vc >= 0 && vc < m &&
               board[vr][vc] != '#') {

                if(dfs(vr, vc, pos + 1, word, board, ans)) {

                    // Restore current cell
                    board[i][j] = temp;

                    return true;
                }
            }
        }

        // Restore current cell
        board[i][j] = temp;

        return false;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        int n = board.size();
        int m = board[0].size();

        vector<string> ans;

        for(int k = 0; k < words.size(); k++){

            bool found = false;

            for(int i = 0; i < n && !found; i++){

                for(int j = 0; j < m; j++){

                    if(board[i][j] == words[k][0]) {

                        if(dfs(i, j, 0, words[k], board, ans)) {

                            found = true;
                            break;
                        }
                    }
                }
            }
        }

        return ans;
    }
};