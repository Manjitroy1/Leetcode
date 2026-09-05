# Q1. Check ASCII Palindromic

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given a string `s` consisting of lowercase English letters.

Construct a  **binary string**  by replacing each character in `s` with the 8-bit binary representation of its ASCII value,  **including leading zeros**, while preserving the original order of the characters.

Return `true` if the resulting binary string is a  **palindrome**. Otherwise, return `false`.

 

 **Example 1:** 

 **Input:**  s = "ff"

 **Output:**  true

 **Explanation:** 

- The ASCII value of f is 102, whose 8-bit binary representation is 01100110.
- Thus, the binary string is 0110011001100110.
- Since this binary string is a palindrome, the output is true.

 **Example 2:** 

 **Input:**  s = "leet"

 **Output:**  false

 **Explanation:** 

- The ASCII values of l, e, e, and t are 108, 101, 101, and 116, respectively.
- Their 8-bit binary representations are 01101100, 01100101, 01100101, and 01110100.
- Thus, the binary string is 01101100011001010110010101110100.
- Since this binary string is not a palindrome, the output is false.

 

 **Constraints:** 

- 1 <= s.length <= 100
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 5 ms (beats 16.25%)  
**Memory:** 10.3 MB (beats 21.38%)  
**Submitted:** 2026-09-05T12:31:00.488Z  

```cpp
class Solution {
public:
    bool check(string& res){
        int l=0;
        int r=res.size()-1;
        while(l<=r){
            if(res[l]!=res[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool isPalindromic(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            char c=s[i];
            int val=(int)c; //go tthe ascii value 
            //we need 8 bit repsentation]
            for(int j=7;j>=0;j--){
                int bit= ((val>>j) & 1)? 1:0;
                res+=to_string(bit);
            }
        }
        return check(res);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/check-ascii-palindromic/)