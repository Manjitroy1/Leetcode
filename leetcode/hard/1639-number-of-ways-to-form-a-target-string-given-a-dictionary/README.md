# Number of Ways to Form a Target String Given a Dictionary

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a list of strings of the  **same length**  `words` and a string `target`.

Your task is to form `target` using the given `words` under the following rules:

- target should be formed from left to right.
- To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
- Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
- Repeat the process until you form the string target.

 **Notice**  that you can use  **multiple characters**  from the  **same string**  in `words` provided the conditions above are met.

Return  *the number of ways to form `target` from `words`*. Since the answer may be too large, return it  **modulo**  `109 + 7`.

 

 **Example 1:** 

```
Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

```

 **Example 2:** 

```
Input: words = ["abba","baab"], target = "bab"
Output: 4
Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")

```

 

 **Constraints:** 

- 1 <= words.length <= 1000
- 1 <= words[i].length <= 1000
- All strings in words have the same length.
- 1 <= target.length <= 1000
- words[i] and target contain only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 763 ms (beats 5.06%)  
**Memory:** 39.2 MB (beats 72.86%)  
**Submitted:** 2026-08-22T14:03:17.054Z  

```cpp
class Solution {
public:
    long long dp[1001][1001];
    const int mod= 1e9+7;
    long long solve(int i,int j,vector<string>&words,string& target){
        int w=words.size();
        int n=words[0].size();
        int m=target.size();
        if(dp[i][j]!=-1) return dp[i][j];
        if(j>=m) return 1;
        if(i>=n || (m-j > n-i)) return 0;

        int cnt=0;
        for(int k=0;k<w;k++){
            if(words[k][i]==target[j]) cnt++;
        }
        long long match = cnt* solve(i+1,j+1,words,target);
        long long  nmatch = solve(i+1,j,words,target);
        return dp[i][j] = (match + nmatch)%mod;
    }
    int numWays(vector<string>& words, string target) {
        memset(dp,-1,sizeof(dp));
        return (int)solve(0,0,words,target);
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/)