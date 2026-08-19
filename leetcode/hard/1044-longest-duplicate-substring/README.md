# Longest Duplicate Substring

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string `s`, consider all  *duplicated substrings* : (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return  **any**  duplicated substring that has the longest possible length. If `s` does not have a duplicated substring, the answer is `""`.

 

 **Example 1:** 

```
Input: s = "banana"
Output: "ana"

```

 **Example 2:** 

```
Input: s = "abcd"
Output: ""

```

 

 **Constraints:** 

- 2 <= s.length <= 3 * 104
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8 MB  
**Submitted:** 2026-08-19T13:17:54.805Z  

```cpp
class Solution {
public:
   void compututelps(string& pattern, vector<int>& lps) {
        int m = pattern.size();

        int len = 0;
        lps[0] = 0;

        int i = 1;

        while (i < m) {

            // Prefix and suffix are matching
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            }

            // Characters are not matching
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    //check if this str exist two tiimes in the s or not using sliding window
    int kmp(string& pattern, string& s) {
        int m = pattern.size();
        int n = s.size();

        int cnt = 0;

        vector<int> lps(m);
        compututelps(pattern, lps);

        int i = 0;
        int j = 0;

        while (i < n) {

            // Characters match
            if (pattern[j] == s[i]) {
                i++;
                j++;
            }

            // Complete pattern matched
            if (j == m) {
                cnt++;

                if (cnt >= 2)
                    return true;

                // Allow overlapping matches
                j = lps[j - 1];
            }

            // Mismatch
            else if (i < n && pattern[j] != s[i]) {

                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        // cout << cnt << endl;

        return cnt>=2;
}

    string bfs(string& s){
        int n=s.size();
        queue<string>q;
        string first="";
        q.push(first);
        string ans="";

        while(!q.empty()){
            string node=q.front();
            q.pop();

            for(char c='a';c<='z';c++){
                string newstr=node;
                newstr+=c;
                if(kmp(newstr,s)){
                    q.push(newstr);
                    ans=newstr;
                }
            }
        }
        return ans;
    }
    string longestDupSubstring(string s) {
        return bfs(s);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-duplicate-substring/)