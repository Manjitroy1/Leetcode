# Count Vowels Permutation

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an integer `n`, your task is to count how many strings of length `n` can be formed under the following rules:

- Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
- Each vowel 'a' may only be followed by an 'e'.
- Each vowel 'e' may only be followed by an 'a' or an 'i'.
- Each vowel 'i' may not be followed by another 'i'.
- Each vowel 'o' may only be followed by an 'i' or a 'u'.
- Each vowel 'u' may only be followed by an 'a'.

Since the answer may be too large, return it modulo `10^9 + 7`.

 

 **Example 1:** 

```
Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i", "o" and "u".

```

 **Example 2:** 

```
Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".

```

 **Example 3:** 

```
Input: n = 5
Output: 68
```

 

 **Constraints:** 

- 1 <= n <= 2 * 10^4

## Solution

**Language:** C++  
**Runtime:** 94 ms (beats 26.86%)  
**Memory:** 30.1 MB (beats 41.08%)  
**Submitted:** 2026-10-15T10:04:35.050Z  

```cpp
class Solution {
public:
    int mod = 1e9+7;

    int countVowelPermutation(int n) {
        // int preva=1;
        // int preve=1;
        // int previ=1;
        // int prevo=1;
        // int prevu=1;
        vector<int>prev(5,1); //a e i o u
        if(n==1) return 5;
        // if(n==2) return 10;

        for(int i=2;i<=n;i++){
            // int curra=0;
            // int curre=0;
            // int curri=0;
            // int curro=0;
            // int curru=0;
            vector<int>curr(5,0);

            //a will generate e;
            curr[1]= (curr[1] + prev[0]) % mod;

            //e will generate i and a
            // curri+=preve;
            // curra+=preve;

            curr[2]= (curr[2] + prev[1]) % mod;
            curr[0]= (curr[0] + prev[1]) % mod;


            //i will generate a e o u
            // curra+=previ;
            // curre+=previ;
            // curro+=previ;
            // curru+=previ;

            curr[0]= (curr[0] + prev[2]) % mod;
            curr[1]= (curr[1] + prev[2]) % mod;
            curr[3]= (curr[3] + prev[2]) % mod;
            curr[4]= (curr[4] + prev[2]) % mod;


            //o will generate i u
            // curri+=prevo;
            // curru+=prevo;

            curr[2]= (curr[2] + prev[3]) % mod;
            curr[4]= (curr[4] + prev[3]) % mod;


            //u will generate a
            // curra+=prevu;
            curr[0]= (curr[0] + prev[4]) % mod;



            //restore
            // preva=curra;
            // preve=curre;
            // previ=curri;
            // prevo=curro;
            // prevu=curru;
            prev=curr;
        }
        int sum =0;
        // return (preva+preve+previ+prevo+prevu);
        for(int i=0;i<5;i++){
            sum = (sum + prev[i])%mod;
        }
        return sum;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-vowels-permutation/)