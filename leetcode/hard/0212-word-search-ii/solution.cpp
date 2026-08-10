struct Node {
    Node* links[26] = {};
    string word = "";

    bool containkey(char c) {
        return links[c - 'a'] != nullptr;
    }

    void put(char c, Node* node) {
        links[c - 'a'] = node;
    }

    Node* next(char c) {
        return links[c - 'a'];
    }

    void end(string& w) {
        word = w;
    }
};


class Trie {
public:

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string& word) {

        Node* node = root;

        for(int i = 0; i < word.size(); i++) {

            if(!node->containkey(word[i])) {
                node->put(word[i], new Node());
            }

            node = node->next(word[i]);
        }

        node->end(word);
    }
};


class Solution {
public:

    int n, m;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};


    void dfs(int i, int j,
             vector<vector<char>>& board,
             Node* node,
             vector<string>& ans) {

        // Current cell is already visited
        if(board[i][j] == '#')
            return;

        char c = board[i][j];

        // Check whether this character exists in Trie
        if(!node->containkey(c))
            return;

        // Move to the corresponding Trie node
        node = node->next(c);


        // We have found a complete word
        if(node->word != "") {

            ans.push_back(node->word);

            // Prevent duplicate answer
            node->word = "";
        }


        // Mark current board cell as visited
        board[i][j] = '#';


        // Explore 4 directions
        for(int d = 0; d < 4; d++) {

            int ni = i + dr[d];
            int nj = j + dc[d];

            if(ni >= 0 && ni < n &&
               nj >= 0 && nj < m) {

                dfs(ni, nj, board, node, ans);
            }
        }


        // Backtrack
        board[i][j] = c;
    }


    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        Trie first;

        Node* rootnode = first.root;


        // Insert all words into Trie
        for(string& w : words) {
            first.insert(w);
        }


        vector<string> ans;


        n = board.size();
        m = board[0].size();


        // Start DFS from every cell
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                dfs(i, j, board, rootnode, ans);
            }
        }


        return ans;
    }
};