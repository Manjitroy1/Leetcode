# Longest Substring of One Repeating Character

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a  **0-indexed**  string `s`. You are also given a  **0-indexed**  string `queryCharacters` of length `k` and a  **0-indexed**  array of integer  **indices**  `queryIndices` of length `k`, both of which are used to describe `k` queries.

The `ith` query updates the character in `s` at index `queryIndices[i]` to the character `queryCharacters[i]`.

Return  *an array*  `lengths`  *of length* `k` *where*  `lengths[i]`  *is the  **length**  of the  **longest substring**  of* `s` *consisting of  **only one repeating**  character  **after**  the*  `ith`  *query** is performed.* 

 

 **Example 1:** 

```
Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
Output: [3,3,4]
Explanation: 
- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2nd query updates s = "bbbccc". 
  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].

```

 **Example 2:** 

```
Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
Output: [2,3]
Explanation:
- 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
- 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
Thus, we return [2,3].

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of lowercase English letters.
- k == queryCharacters.length == queryIndices.length
- 1 <= k <= 105
- queryCharacters consists of lowercase English letters.
- 0 <= queryIndices[i] < s.length

## Solution

**Language:** C++  
**Runtime:** 123 ms (beats 90.89%)  
**Memory:** 103.3 MB (beats 68.51%)  
**Submitted:** 2026-09-30T19:06:12.475Z  

```cpp
struct Node{
    char leftchar;
    char rightchar;
    int pref;
    int suff;
    int best;

};
class Segment{
public:
    vector<Node>sgt;
    Segment(int n){
        sgt.resize(4*n+1);
    }
    Node merge(int idx1,int idx2,int leftlen,int rightlen){
        Node node1= sgt[idx1];
        Node node2= sgt[idx2];


        Node ans;
        ans.best=max(node1.best,node2.best); //may be updated

        if(node1.rightchar==node2.leftchar){
            ans.best=max(ans.best, node1.suff + node2.pref);
        }

        ans.leftchar=node1.leftchar;
        ans.rightchar=node2.rightchar;

        //what about updated pref and suff
        ans.pref=node1.pref;
        ans.suff=node2.suff;

        if(node1.rightchar==node2.leftchar){
            if(node1.pref==leftlen) ans.pref=leftlen + node2.pref;
            if(node2.suff==rightlen) ans.suff=rightlen + node1.suff;  
        }
        return ans;

    }
    void build(int idx,int low,int high,string& s){
        if(low==high){
            Node leaf;
            leaf.leftchar=s[low];
            leaf.rightchar=s[low];
            leaf.pref=1;
            leaf.suff=1;
            leaf.best=1;
            sgt[idx]=leaf;
            return ;
        }
        int mid=low+(high-low)/2;
        build(2*idx+1,low,mid,s);
        build(2*idx+2,mid+1,high,s);
        
        int leftlen=mid-low+1;
        int rightlen=high-mid;

        sgt[idx]=merge(2*idx+1,2*idx+2,leftlen,rightlen); //merge those two segment

    }
    void update(int idx,int low,int high, int pos,char c){
        if(low==high){
            // we reach at the pos
            sgt[idx].leftchar=c;
            sgt[idx].rightchar=c;
            return;
        }
        int mid= low+(high-low)/2;
        if(pos<=mid) update(2*idx+1,low,mid,pos,c);
        else update(2*idx+2,mid+1,high,pos,c);

        int leftlen=mid-low+1;
        int rightlen=high-mid;

        sgt[idx]=merge(2*idx+1,2*idx+2,leftlen,rightlen);
    }

};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n=s.size();
        int q=queryCharacters.size();
        
        Segment first(n);
        first.build(0,0,n-1,s);

        vector<int>ans;
        for(int i=0;i<q;i++){
            //update
            int pos=queryIndices[i];
            char c=queryCharacters[i];
            first.update(0,0,n-1,pos,c);
            ans.push_back(first.sgt[0].best);
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-substring-of-one-repeating-character/)