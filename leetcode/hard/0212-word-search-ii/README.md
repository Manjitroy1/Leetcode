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
**Runtime:** 0 ms  
**Memory:** 8.8 MB  
**Submitted:** 2026-08-10T12:01:16.803Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/word-search-ii/)