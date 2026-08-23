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
**Runtime:** 1033 ms (beats 21.43%)  
**Memory:** 563.5 MB (beats 16.56%)  
**Submitted:** 2026-08-23T16:46:19.412Z  

```cpp
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.size();
        set<string>stt;
        for(int len=1;len<=(n/2);len++){
            int consecutive=0;
            for(int i=0;i+len<n;i++){
                if(text[i]==text[i+len]){
                    consecutive++;
                }else{
                    consecutive=0;
                }

                if(consecutive==len){
                    string echo = text.substr(i,len);
                    stt.insert(echo);
                    consecutive--;
                }
            }
        }
        return stt.size();
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/distinct-echo-substrings/)