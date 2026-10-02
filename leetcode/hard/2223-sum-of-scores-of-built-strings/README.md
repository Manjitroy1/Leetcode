# Sum of Scores of Built Strings

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are  **building**  a string `s` of length `n`  **one**  character at a time,  **prepending**  each new character to the  **front**  of the string. The strings are labeled from `1` to `n`, where the string with length `i` is labeled `si`.

- For example, for s = "abaca", s1 == "a", s2 == "ca", s3 == "aca", etc.

The  **score**  of `si` is the length of the  **longest common prefix**  between `si` and `sn` (Note that `s == sn`).

Given the final string `s`, return *the  **sum**  of the  **score**  of every* `si`.

 

 **Example 1:** 

```
Input: s = "babab"
Output: 9
Explanation:
For s1 == "b", the longest common prefix is "b" which has a score of 1.
For s2 == "ab", there is no common prefix so the score is 0.
For s3 == "bab", the longest common prefix is "bab" which has a score of 3.
For s4 == "abab", there is no common prefix so the score is 0.
For s5 == "babab", the longest common prefix is "babab" which has a score of 5.
The sum of the scores is 1 + 0 + 3 + 0 + 5 = 9, so we return 9.
```

 **Example 2:** 

```
Input: s = "azbazbzaz"
Output: 14
Explanation: 
For s2 == "az", the longest common prefix is "az" which has a score of 2.
For s6 == "azbzaz", the longest common prefix is "azb" which has a score of 3.
For s9 == "azbazbzaz", the longest common prefix is "azbazbzaz" which has a score of 9.
For all other si, the score is 0.
The sum of the scores is 2 + 3 + 9 = 14, so we return 14.

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 10 ms (beats 83.91%)  
**Memory:** 24.3 MB (beats 95.30%)  
**Submitted:** 2026-10-02T09:02:28.467Z  

```cpp
#define ll long long
class Solution {
public:
    ll z_func(string& s){
        int n=s.size();
        vector<int>z(n,0);

        // l to r is the z box which is equal to the prefix;
        int l=0;
        int r=0;

        for(int i=1;i<n;i++){
            //resue the prev
            if(i<=r){
                int k=i-l; //l shifted to 0 and i shifted to i-l
                z[i]=min(r-i+1,z[k]);
            }
            //extend the limit
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                z[i]++;
            }
            //update the limit
            if(i+z[i]-1 > r){
                l=i;
                r=i+z[i]-1;
            }
        }
        z[0]=n;

        ll ans =0;
        for(int i=0;i<n;i++){
            ans+=z[i];
        }
        return ans;

    }
    long long sumScores(string s) {
        return z_func(s);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-scores-of-built-strings/)