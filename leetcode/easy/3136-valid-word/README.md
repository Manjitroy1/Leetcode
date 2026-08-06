# Valid Word

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

A word is considered  **valid**  if:

- It contains a minimum of 3 characters.
- It contains only digits (0-9), and English letters (uppercase and lowercase).
- It includes at least one vowel.
- It includes at least one consonant.

You are given a string `word`.

Return `true` if `word` is valid, otherwise, return `false`.

 **Notes:** 

- 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
- A consonant is an English letter that is not a vowel.

 

 **Example 1:** 

 **Input:**  word = "234Adas"

 **Output:**  true

 **Explanation:** 

This word satisfies the conditions.

 **Example 2:** 

 **Input:**  word = "b3"

 **Output:**  false

 **Explanation:** 

The length of this word is fewer than 3, and does not have a vowel.

 **Example 3:** 

 **Input:**  word = "a3$e"

 **Output:**  false

 **Explanation:** 

This word contains a `'$'` character and does not have a consonant.

 

 **Constraints:** 

- 1 <= word.length <= 20
- word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 15.79%)  
**Memory:** 7.9 MB (beats 89.47%)  
**Submitted:** 2026-08-06T13:37:59.186Z  

```cpp
class Solution {
public:
    bool vowelandcons(string& word){
        bool vow= false;
        bool cons=false;

        for(char c:word){
            if(c=='a' || c=='e' || c=='i'|| c=='o' || c=='u'){
                vow= true;
            }
            else if(c=='A' || c=='E' || c=='I'|| c=='O' || c=='U'){
                vow= true;
            }
            else if((c>'a' && c<='z') || (c>'A' && c<='Z')){
                cons=true;
            }
            
        }
        return vow&cons;
    }
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return false;

        for(char c: word){
            int v= (int)c;
            if((v>47 && v<58) || (v>64 && v<91) || (v>96 && v<123)){
                continue;
            }else{
                return false;
            }
        }
        return vowelandcons(word);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-word/)