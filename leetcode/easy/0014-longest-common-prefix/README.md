# Longest Common Prefix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

 

 **Example 1:** 

```
Input: strs = ["flower","flow","flight"]
Output: "fl"

```

 **Example 2:** 

```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

```

 

 **Constraints:** 

- 1 <= strs.length <= 200
- 0 <= strs[i].length <= 200
- strs[i] consists of only lowercase English letters if it is non-empty.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 8.48%)  
**Memory:** 12.5 MB (beats 5.37%)  
**Submitted:** 2026-08-09T17:51:38.270Z  

```cpp
struct Node{
    Node* links[26]= {};
    bool flag=false;
    int size=0;

    bool containskey(char c){
        return links[c-'a'] != nullptr;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void put(char c, Node* node){
        links[c-'a'] = node;
        return;
    }
    void setend(){
        flag=true;
        return;
    }
    bool isend(){
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node= root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
                node->size++;
            }
            node = node->get(word[i]);
        }
        node->setend();
    }
};
 
class Solution {
public:
    Trie first;
    string longestCommonPrefix(vector<string>& strs) {
        for(string& s:strs){
            first.insert(s);
        }
        Node* node = first.root;
        
        string ans="";

        while(node->size==1 && !node->isend()){
           for(int i=0;i<26;i++){
                if(node->links[i]!=nullptr){
                    ans+=(i+'a');
                    node= node->links[i];
                    break;
                }
           }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-common-prefix/)