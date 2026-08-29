# Q1. Minimum Bishop Moves to Reach Target

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There is an `8 x 8` empty chessboard with  **1-indexed**  rows and columns.

You are given an array `source = [sr, sc]` representing the starting position of a  **bishop**, and an array `target = [tr, tc]`. In one move, the bishop travels any number of squares along a single  **diagonal**  direction, staying within the board.

Return the  **minimum**  number of moves for the bishop to land  **exactly**  on `target`. If it can never reach `target`, return -1.

 

 **Example 1:** 

 **Input:**  source = [8,1], target = [1,8]

 **Output:**  1

 **Explanation:** 

 **​​​​​​​** 

A single diagonal move takes the bishop straight from `(8, 1)` to `(1, 8)`.

 **Example 2:** 

 **Input:**  source = [4,2], target = [1,3]

 **Output:**  2

 **Explanation:** 

The bishop moves from `(4, 2)` to `(3, 1)`, then from `(3, 1)` to `(1, 3)`, reaching the target in 2 moves.

 **Example 3:** 

 **Input:**  source = [1,1], target = [3,4]

 **Output:**  -1

 **Explanation:** 

No matter how many diagonal moves it makes, the bishop starting at `(1, 1)` can never land on `(3, 4)`. Thus, the answer is -1.

 

 **Constraints:** ​​​​​​​

- source.length == target.length == 2
- 1 <= sr, sc, tr, tc <= 8
- source != target

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 50.3 MB (beats 75.00%)  
**Submitted:** 2026-08-29T14:55:03.768Z  

```cpp
class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int x1=source[0];
        int y1=source[1];
        int sum1=x1+y1;
        int p1=(x1+y1)%2;
        
        int x2=target[0];
        int y2=target[1];
        int sum2=x2+y2;
        int p2=(x2+y2)%2;

        if(p1 ^ p2) return -1; //diff color 
        //check all the diagonal
        if(sum1==sum2) return 1;
        if(x1+ (8-y1) == (x2+ (8-y2))) return 1;
        else return 2;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/)