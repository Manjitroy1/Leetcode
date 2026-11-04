# Concatenated Words

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an array of strings `words` (**without duplicates**), return  *all the  **concatenated words**  in the given list of*  `words`.

A  **concatenated word**  is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.

 

 **Example 1:** 

```
Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
```

 **Example 2:** 

```
Input: words = ["cat","dog","catdog"]
Output: ["catdog"]

```

 

 **Constraints:** 

- 1 <= words.length <= 104
- 1 <= words[i].length <= 30
- words[i] consists of only lowercase English letters.
- All the strings of words are unique.
- 1 <= sum(words[i].length) <= 105

## Solution

**Language:** C++  
**Runtime:** 130 ms (beats 52.23%)  
**Memory:** 54 MB (beats 55.71%)  
**Submitted:** 2026-11-04T12:08:54.088Z  

```cpp
struct Node{
    Node* links[26] = {};
    bool flag =false;

    bool containskey(char c){
        return links[c-'a'] != nullptr;
    }
    Node* get (char c){
        return links[c-'a'];
    }
    void put(char c,Node* node){
        links[c-'a'] = node;
        return ;
    }
    void setend(){
        flag=true;
        return;
    }
    bool isend(){
        return flag;
    }
};
class Trie{
public:
    Node* root;

    Trie(){
        root= new Node();
    }
    void insert(string& s){
        int cnt=0;
        int pos =-1;
        Node* node = root;

        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(!node->containskey(c)){
                node->put(c,new Node());
            }
            if(node->isend()){
                cnt++;
                pos=i;
            }
            node = node->get(c);
        }
        node->setend();
    }

    bool search(string& s){
        Node* node = root;
        for(char& c:s){
            if(!node->containskey(c)){
                return false;
            }
            node=node->get(c);
        }
        return node->isend();
    }
    bool startwith(char& c){
        Node* node=root;
        return node->containskey(c);
    }
};
class Solution {
public:

    static bool comp(string& a,string& b){
        return a.size() < b.size();
    }
    // Trie first; //object of trie
    // Node* root = first.root;

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        //build the trie
        sort(words.begin(),words.end(),comp);
        vector<string>ans;

        unordered_set<string>st;

        for(string& w:words){
            int n=w.size();
            vector<int>dp(n+1,-1);
            // dp[i] = cnt of prefix of length i can be splitted
            dp[0]=0;
            for(int i=0;i<n;i++){
                if(dp[i]==-1) continue;
                string temp="";

                for(int j=i;j<n;j++){
                    temp+=w[j];

                    if(st.count(temp)){
                        dp[j+1] = max(dp[j+1],dp[i]+1);
                    }
                }
            }
            if(dp[n]>=2){
                ans.push_back(w);
            }
            st.insert(w);
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/concatenated-words/)