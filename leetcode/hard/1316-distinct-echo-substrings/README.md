# Distinct Echo Substrings

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Return the number of  **distinct**  non-empty substrings of `text` that can be written as the concatenation of some string with itself (i.e. it can be written as `a + a` where `a` is some string).

 

 **Example 1:** 

```
Input: text = "abcabcabc"
Output: 3
Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".

```

 **Example 2:** 

```
Input: text = "leetcodeleetcode"
Output: 2
Explanation: The 2 substrings are "ee" and "leetcodeleetcode".

```

 

 **Constraints:** 

- 1 <= text.length <= 2000
- text has only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 1402 ms (beats 15.26%)  
**Memory:** 614.5 MB (beats 12.66%)  
**Submitted:** 2026-08-23T14:33:00.569Z  

```cpp
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.size();
        set<string>stt;
        for(int i=0;i<n-1;i++){
            for(int len=1;i+ 2*len<=n;len++){
                if(text.compare(i,len,text,i+len,len)==0){
                    stt.insert(text.substr(i,2*len));
                }
            }
        }
        for(auto& e: stt){
            cout<<e<<" ";
        }
        return stt.size();
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/distinct-echo-substrings/)