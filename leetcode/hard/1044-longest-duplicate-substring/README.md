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
**Runtime:** 1240 ms (beats 32.96%)  
**Memory:** 427.3 MB (beats 36.57%)  
**Submitted:** 2026-08-19T14:14:36.512Z  

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
    void dfs(string& curr, string& ans,string& s,vector<int>&freq){
        if(curr.size()>ans.size()) ans=curr;

        for(char c='a';c<='z';c++){
            if(freq[c-'a']<2) continue;

            curr.push_back(c);

            if(kmp(curr,s)){
                dfs(curr,ans,s,freq);
            }
            curr.pop_back();
        }
    }
    string bnsearch(string s) {
        int n=s.size();
        int l=1;
        int h=n/2;
        string ans="";

        while(l<=h){
            int mid= (l+h)/2;
            bool flag=false;
            //check fo all possible string of length mid;
            for(int i=0;i<n-mid;i++){
                string pattern = s.substr(i,mid);
                if(kmp(pattern,s)){
                    flag=true;
                    ans=pattern;
                    l=mid+1;
                    continue;
                }
            }
            if(!flag){
                h=mid-1;
            }
        }
        return ans;
    }

    string s;
    int n;

    // Check if there is a duplicate substring of length len.
    // If found, return that substring; otherwise return "".
    string check(int len) {

        if (len == 0)
            return "";

        const long long BASE = 31;
        const long long MOD = 1000000007;

        long long hash = 0;
        long long power = 1;

        // BASE^(len-1)
        for (int i = 1; i < len; i++) {
            power = (power * BASE) % MOD;
        }

        // Hash of first window
        for (int i = 0; i < len; i++) {
            hash = (hash * BASE + (s[i] - 'a' + 1)) % MOD;
        }

        unordered_map<long long, vector<int>> mp;

        mp[hash].push_back(0);

        // Sliding window
        for (int i = len; i < n; i++) {

            // Remove leftmost character
            hash = (hash - 
                   ((s[i - len] - 'a' + 1) * power) % MOD 
                   + MOD) % MOD;

            // Add new character
            hash = (hash * BASE + (s[i] - 'a' + 1)) % MOD;

            int start = i - len + 1;

            // Same hash found
            if (mp.count(hash)) {

                // Verify actual strings to avoid hash collision
                for (int prev : mp[hash]) {

                    if (s.compare(prev, len, s, start, len) == 0) {
                        return s.substr(start, len);
                    }
                }
            }

            mp[hash].push_back(start);
        }

        return "";
    }
    string longestDupSubstring(string str) {

        s = str;
        n = s.size();

        int low = 1;
        int high = n - 1;

        string ans = "";

        while (low <= high) {

            int mid = low + (high - low) / 2;

            string cur = check(mid);

            if (!cur.empty()) {

                // Duplicate substring of length mid exists
                ans = cur;

                // Try a longer substring
                low = mid + 1;
            }
            else {

                // No duplicate of this length
                high = mid - 1;
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-duplicate-substring/)