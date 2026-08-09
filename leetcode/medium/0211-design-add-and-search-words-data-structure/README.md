# Design Add and Search Words Data Structure

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the `WordDictionary` class:

- WordDictionary() Initializes the object.
- void addWord(word) Adds word to the data structure, it can be matched later.
- bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

 

 **Example:** 

```
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

```

 

 **Constraints:** 

- 1 <= word.length <= 25
- word in addWord consists of lowercase English letters.
- word in search consist of '.' or lowercase English letters.
- There will be at most 2 dots in word for search queries.
- At most 104 calls will be made to addWord and search.

## Solution

**Language:** C++  
**Runtime:** 348 ms (beats 59.28%)  
**Memory:** 583.6 MB (beats 67.71%)  
**Submitted:** 2026-08-09T18:37:55.243Z  

```cpp
struct Node{
    Node* lists[26]={};
    bool flag=false;

    bool containkey(char c){
        return lists[c-'a'] != nullptr;
    }
    void put(char c, Node* node){
        lists[c-'a'] = node;
        return;
    }
    Node* next(char c){
        return lists[c-'a'];
    }
    void setend(){
        flag=true;
        return;
    }
    bool isend(){
        return flag;
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containkey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->next(word[i]);
        }
        node->setend();
    }
    bool dfs(Node* node, int idx, string& word){
        if(idx>=word.size()){
            return node->isend();
        }
        //normal charecter
        if(word[idx]!='.'){
            if(!node->containkey(word[idx])){
                return false;
            }
            return dfs(node->next(word[idx]), idx+1,word);
        }

        //if char is dot try all possibilieties
        for(int i=0;i<26;i++){
            if(node->lists[i]!=nullptr){
                //if a char then try this as a dot replacement
                if(dfs(node->lists[i], idx+1,word)){
                    return true;
                }
            }
        }
        return false;
    }
    bool search(string word) {
        return dfs(root,0,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
```

---

[View on LeetCode](https://leetcode.com/problems/design-add-and-search-words-data-structure/)