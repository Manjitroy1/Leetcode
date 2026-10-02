# Repeated Substring Pattern

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string `s`, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

 **Example 1:** 

```
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

```

 **Example 2:** 

```
Input: s = "aba"
Output: false

```

 **Example 3:** 

```
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.

```

 

 **Constraints:** 

- 1 <= s.length <= 104
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 11 ms (beats 39.10%)  
**Memory:** 17.1 MB (beats 34.89%)  
**Submitted:** 2026-10-02T08:25:39.676Z  

```cpp
class Solution {
public:
    void create(string& s, vector<int>&lps){
        int n=s.size();
        int len=0;
        int i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    i++;
                }
            }
        }
    }
    bool repeatedSubstringPattern(string s) {
        //concat s with s 
        //remove first and last index char
        int n=s.size();
        string t = s+s;
        vector<int>lps(n,0);
        create(s,lps);

        int i=1;
        int j=0;
        while(i<(2*n)-1){
            if(t[i]==s[j]){
                i++;
                j++;
                if(j==n){
                    return true;
                    j=lps[j-1];
                }
            }else{
                if(j>=1)
                    j=lps[j-1];
                else{
                    i++;
                }
            }
        }
        return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/repeated-substring-pattern/)