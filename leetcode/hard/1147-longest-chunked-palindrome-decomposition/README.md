# Longest Chunked Palindrome Decomposition

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `text`. You should split it to k substrings `(subtext1, subtext2,..., subtextk)` such that:

- subtexti is a non-empty string.
- The concatenation of all the substrings is equal to text (i.e., subtext1 + subtext2 +... + subtextk == text).
- subtexti == subtextk - i + 1 for all valid values of i (i.e., 1 <= i <= k).

Return the largest possible value of `k`.

 

 **Example 1:** 

```
Input: text = "ghiabcdefhelloadamhelloabcdefghi"
Output: 7
Explanation: We can split the string on "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)".

```

 **Example 2:** 

```
Input: text = "merchant"
Output: 1
Explanation: We can split the string on "(merchant)".

```

 **Example 3:** 

```
Input: text = "antaprezatepzapreanta"
Output: 11
Explanation: We can split the string on "(a)(nt)(a)(pre)(za)(tep)(za)(pre)(a)(nt)(a)".

```

 

 **Constraints:** 

- 1 <= text.length <= 1000
- text consists only of lowercase English characters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.3 MB (beats 97.39%)  
**Submitted:** 2026-08-25T13:09:00.723Z  

```cpp
class Solution {
public:
    int solve(int l,int h,string& text){
        if(l>h) return 0;
        if(l==h) return 1;
        
        // int ans=0;
        // int take=0;
        
        for(int i=l;i<=(l+h)/2;i++){
            int j=h+l-i;
            int len = i-l+1;
            if(text.compare(l,len,text,j,len) ==0){
                return (2+solve(i+1,j-1,text));
            }
        }
        return 1;
    }
    int longestDecomposition(string text){
        int l=0;
        int h=text.size()-1;
        return solve(l,h,text);
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-chunked-palindrome-decomposition/)