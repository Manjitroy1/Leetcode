# Minimum Number of Moves to Make Palindrome

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `s` consisting only of lowercase English letters.

In one  **move**, you can select any two  **adjacent**  characters of `s` and swap them.

Return  *the  **minimum number of moves**  needed to make*  `s`  *a palindrome*.

 **Note**  that the input will be generated such that `s` can always be converted to a palindrome.

 

 **Example 1:** 

```
Input: s = "aabb"
Output: 2
Explanation:
We can obtain two palindromes from s, "abba" and "baab". 
- We can obtain "abba" from s in 2 moves: "aabb" -> "abab" -> "abba".
- We can obtain "baab" from s in 2 moves: "aabb" -> "abab" -> "baab".
Thus, the minimum number of moves needed to make s a palindrome is 2.

```

 **Example 2:** 

```
Input: s = "letelt"
Output: 2
Explanation:
One of the palindromes we can obtain from s in 2 moves is "lettel".
One of the ways we can obtain it is "letelt" -> "letetl" -> "lettel".
Other palindromes such as "tleelt" can also be obtained in 2 moves.
It can be shown that it is not possible to obtain a palindrome in less than 2 moves.

```

 

 **Constraints:** 

- 1 <= s.length <= 2000
- s consists only of lowercase English letters.
- s can be converted to a palindrome using a finite number of moves.

## Solution

**Language:** C++  
**Runtime:** 11 ms (beats 66.81%)  
**Memory:** 9.4 MB (beats 98.91%)  
**Submitted:** 2026-09-13T09:23:43.776Z  

```cpp
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        //using two pointer
        //s[i]==s[j] i++,j--
        //if not equal find k such that s[i]==s[k] , find k from the right 
        //we have to swap with j and along the path
        //if no match found then s[i] is the odd freq middle one so push toward centre
        int n=s.size();
        int l=0;
        int r=n-1;
        int ans=0;

        while(l<r){
            //both char match nothing to do
            while(l<r && s[l]==s[r]){
                l++;
                r--;
            }
            if(s[l]!=s[r]){
                int k=r;
                while(l<k && s[l]!=s[k]){
                    k--;
                }
                //if we get a value k
                if(l<k){
                    ans+=(r-k);
                    while(k<r){
                        swap(s[k],s[k+1]);
                        k++;
                    }
                    l++;
                    r--;

                }else{//we did not a value k
                    swap(s[l],s[l+1]);
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/)