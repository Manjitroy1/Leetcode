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
**Runtime:** 67 ms (beats 77.53%)  
**Memory:** 83.1 MB (beats 29.35%)  
**Submitted:** 2026-08-22T14:17:57.703Z  

```cpp
class Solution {
public:
    // long long dp[1001][1001];
    const int mod= 1e9+7;
    // long long solve(int i,int j,vector<string>&words,string& target){
    //     int w=words.size();
    //     int n=words[0].size();
    //     int m=target.size();
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(j>=m) return 1;
    //     if(i>=n || (m-j > n-i)) return 0;

    //     int cnt=0;
    //     for(int k=0;k<w;k++){
    //         if(words[k][i]==target[j]) cnt++;
    //     }
    //     long long match = cnt* solve(i+1,j+1,words,target);
    //     long long  nmatch = solve(i+1,j,words,target);
    //     return dp[i][j] = (match + nmatch)%mod;
    // }


    int tabu(vector<string>& words, string target){
        int w=words.size();
        int n=words[0].size();
        int m=target.size();
        // vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        vector<long long>prev(m+1,0);
        prev[m]=1;

        // for(int i=0;i<=n;i++){
        //     dp[i][m]=1;
        // }
        vector<vector<int>>freq(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(int k=0;k<w;k++){
                // ith index of every k the word
                freq[i][words[k][i]-'a']++;
            }
        }

        for(int i=n-1;i>=0;i--){
            vector<long long>curr(m+1,0);
            curr[m]=1;
            for(int j=m-1;j>=0;j--){

                int cnt=freq[i][target[j]-'a'];
                long long match = 1LL*cnt * prev[j+1];
                long long  nmatch = prev[j];
                
                curr[j] = (match + nmatch)%mod;
            }
            prev=curr;
        }
        return prev[0];
    }
    int numWays(vector<string>& words, string target) {
        // memset(dp,-1,sizeof(dp));
        // return (int)solve(0,0,words,target);
        return (int)tabu(words,target);
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/)