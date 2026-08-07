# Painting a Grid With Three Different Colors

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given two integers `m` and `n`. Consider an `m x n` grid where each cell is initially white. You can paint each cell  **red**,  **green**, or  **blue**. All cells  **must**  be painted.

Return *the number of ways to color the grid with  **no two adjacent cells having the same color***. Since the answer can be very large, return it  **modulo**  `109 + 7`.

 

 **Example 1:** 

```
Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.

```

 **Example 2:** 

```
Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.

```

 **Example 3:** 

```
Input: m = 5, n = 5
Output: 580986

```

 

 **Constraints:** 

- 1 <= m <= 5
- 1 <= n <= 1000

## Solution

**Language:** C++  
**Runtime:** 19 ms (beats 89.55%)  
**Memory:** 9.4 MB (beats 91.94%)  
**Submitted:** 2026-08-07T13:38:21.740Z  

```cpp
class Solution {
public:
    const int MOD= 1e9+7;
    vector<vector<int>>states;
    vector<vector<int>>adj; //graph to store compatibility

    void generate(int idx,int m,vector<int>&curr){
        if(idx>=m){
            states.push_back(curr);
            return;
        }
        for(int c=0;c<3;c++){
            if(idx>=1 && curr[idx-1]==c) continue;
            curr.push_back(c);
            generate(idx+1,m,curr);
            curr.pop_back();
        }
        
    }
    bool compatibility(vector<int>&a, vector<int>&b){
        int m=a.size();
        for(int j=0;j<m;j++){
            if(a[j]==b[j]) return false;
        }
        return true;
    }
    void graph(){
        int s= states.size();
        adj.resize(s);
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                if(compatibility(states[i],states[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }

    int colorTheGrid(int m, int n) {
        //generates states of m boxes
        vector<int>curr;
        generate(0,m,curr);
        graph();
        int S=states.size();
        //now we have adj matrix
        vector<long long> dp(S, 1), ndp(S);

        // Process remaining columns
        for (int col = 1; col < n; col++) {

            fill(ndp.begin(), ndp.end(), 0);

            for (int prev = 0; prev < S; prev++) {

                for (int nxt : adj[prev]) {

                    ndp[nxt] = (ndp[nxt] + dp[prev]) % MOD;
                }
            }

            dp = ndp;
        }

        long long ans = 0;

        for (long long x : dp)
            ans = (ans + x) % MOD;

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/painting-a-grid-with-three-different-colors/)