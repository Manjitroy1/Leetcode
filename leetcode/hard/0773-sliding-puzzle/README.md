# Sliding Puzzle

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

On an `2 x 3` board, there are five tiles labeled from `1` to `5`, and an empty square represented by `0`. A  **move**  consists of choosing `0` and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is `[[1,2,3],[4,5,0]]`.

Given the puzzle board `board`, return  *the least number of moves required so that the state of the board is solved*. If it is impossible for the state of the board to be solved, return `-1`.

 

 **Example 1:** 

```
Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.

```

 **Example 2:** 

```
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.

```

 **Example 3:** 

```
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]

```

 

 **Constraints:** 

- board.length == 2
- board[i].length == 3
- 0 <= board[i][j] <= 5
- Each value board[i][j] is unique.

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 57.39%)  
**Memory:** 10.4 MB (beats 92.36%)  
**Submitted:** 2026-08-29T12:24:31.949Z  

```cpp
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>>adj={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        // [[1,3],[0,2,4],[1,5],[0,4],[1,3,5],[2,4]];

        // unordered_map<string,int>mpp;
        string target="123450";
        // mpp[target]=0;
        set<string>vis;

        queue<string>q;

        string start="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                start+=(board[i][j] + '0');
            }
        }
        int step=0;
        if(start==target) return step;

        q.push(start);
        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                string curr=q.front();
                q.pop();
                //if we reach the target
                if(curr==target) return step;

                //we have to find the 0
                int u = curr.find('0');

                for(int v: adj[u]){
                    string next=curr;
                    swap(next[u],next[v]);

                    if(!vis.count(next)){
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sliding-puzzle/)