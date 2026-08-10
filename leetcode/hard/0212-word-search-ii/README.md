# Word Search II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an `m x n` `board` of characters and a list of strings `words`, return  *all words on the board*.

Each word must be constructed from letters of sequentially adjacent cells, where  **adjacent cells**  are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

 **Example 1:** 

```
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

```

 **Example 2:** 

```
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

```

 

 **Constraints:** 

- m == board.length
- n == board[i].length
- 1 <= m, n <= 12
- board[i][j] is a lowercase English letter.
- 1 <= words.length <= 3 * 104
- 1 <= words[i].length <= 10
- words[i] consists of lowercase English letters.
- All the strings of words are unique.

## Solution

**Language:** C++  
**Runtime:** 318 ms (beats 60.42%)  
**Memory:** 18.8 MB (beats 89.88%)  
**Submitted:** 2026-08-10T12:47:45.628Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/word-search-ii/)