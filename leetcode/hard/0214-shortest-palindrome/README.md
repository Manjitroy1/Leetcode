# Shortest Palindrome

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `s`. You can convert `s` to a palindrome by adding characters in front of it.

Return  *the shortest palindrome you can find by performing this transformation*.

 

 **Example 1:** 

```
Input: s = "aacecaaa"
Output: "aaacecaaa"

```

 **Example 2:** 

```
Input: s = "abcd"
Output: "dcbabcd"

```

 

 **Constraints:** 

- 0 <= s.length <= 5 * 104
- s consists of lowercase English letters only.

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 56.11%)  
**Memory:** 16.2 MB (beats 10.01%)  
**Submitted:** 2026-08-23T05:57:15.157Z  

```cpp
class Solution {
public:
    string better(string s) {

        int n = s.size();
        if(n==1) return s;
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for(int len = 1; len <= n; len++) {

            for(int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if(len == 1) {
                    pal[i][j] = true;
                }
                else if(len == 2) {
                    pal[i][j] = (s[i] == s[j]);
                }
                else {
                    pal[i][j] = (s[i] == s[j]) && pal[i + 1][j - 1];
                }
            }
        }
        int idx=0;
        for(int i=n-1;i>=0;i--){
            if(pal[0][i]){
                idx=i;
                break;
            }
        }
        string ans="";

        if(idx+1<n){
            ans=s.substr(idx+1);
            reverse(ans.begin(),ans.end());
        } 
        ans+=s;
        return ans;
    }

    string shortestPalindrome(string s) {

        int n = s.size();
        if(n==1) return s;
        string str=s;
        str+='#';
        string t=s;
        reverse(t.begin(),t.end());
        str+=t;
        int m=str.size();

        vector<int>lps(m,0);
        
        lps[0]=0;
        int len=0;
        int i=1;
        while(i<str.size()){
            if(str[i]==str[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        // int mx= max_element(lps.begin(),lps.end());
        int mx=lps[m-1];
        string ans="";
        if(mx<n) ans+=s.substr(mx);
        reverse(ans.begin(),ans.end());
        ans+=s;

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/shortest-palindrome/)