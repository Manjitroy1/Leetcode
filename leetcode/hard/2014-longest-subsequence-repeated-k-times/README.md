# Longest Subsequence Repeated k Times

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `s` of length `n`, and an integer `k`. You are tasked to find the  **longest subsequence repeated**  `k` times in string `s`.

A  **subsequence**  is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

A subsequence `seq` is  **repeated**  `k` times in the string `s` if `seq  *k` is a subsequence of `s`, where `seq*  k` represents a string constructed by concatenating `seq` `k` times.

- For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".

Return  *the  **longest subsequence repeated*** `k` *times in string* `s` *. If multiple such subsequences are found, return the  **lexicographically largest**  one. If there is no such subsequence, return an  **empty**  string*.

 

 **Example 1:** 

```
Input: s = "letsleetcode", k = 2
Output: "let"
Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
"let" is the lexicographically largest one.

```

 **Example 2:** 

```
Input: s = "bb", k = 2
Output: "b"
Explanation: The longest subsequence repeated 2 times is "b".

```

 **Example 3:** 

```
Input: s = "ab", k = 2
Output: ""
Explanation: There is no subsequence repeated 2 times. Empty string is returned.

```

 

 **Constraints:** 

- n == s.length
- 2 <= k <= 2000
- 2 <= n < min(2001, k * 8)
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 101 ms (beats 95.71%)  
**Memory:** 40.8 MB (beats 26.07%)  
**Submitted:** 2026-08-18T17:32:43.421Z  

```cpp
class Solution {
public:
    bool check(string str,string s, int k){
        int n=s.size();
        int m=str.size();
        int l=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==str[l]){
                l++;
                if(l>=m){
                    cnt++;
                    l=0;
                    if(cnt>=k) return true;
                }
            }
        }
        return false;
        
    }
    string bfs(string s, int k) {
        int n=s.size();
        string first="";
        if(k>n) return first;
        queue<string>q;
        q.push(first);
        string ans="";

        while(!q.empty()){
            string str = q.front();
            // ans=max(ans,str);
            q.pop();

            for(char c='a';c<='z';c++){
                string newstr =str;
                newstr+=c;
                if(check(newstr,s,k)){
                    q.push(newstr);
                    ans=newstr;
                }
            }
        }
        return ans;
    }
    void dfs(string curr,string& ans,string& s, int k, vector<int>&freq){
        if(curr.size()> ans.size() || (curr.size()==ans.size() && curr>ans)) ans=curr;

        for(char c='a';c<='z';c++){

            if(freq[c-'a']< k) continue;

            curr+=c;
            freq[c-'a']-=k;

            if(check(curr,s,k)){
                dfs(curr,ans,s,k,freq);
            }

            curr.pop_back();
            freq[c-'a']+=k;
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size();
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        //for a string to be an answer all char of c must be atleast k times present

        string ans="";
        string curr="";

        dfs(curr,ans,s,k,freq);
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-subsequence-repeated-k-times/)