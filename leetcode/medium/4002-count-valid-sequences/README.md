# Count Valid Sequences

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two  **positive**  integers `n` and `k`.

A  **valid sequence**  is a sequence of `k` positive integers such that:

- The sum of all integers in the sequence is equal to n.
- The product of all integers in the sequence is even.

Return the number of valid sequences. Since the answer may be very large, return it  **modulo**  `109​​​​​​​ + 7`.

Two sequences are considered  **different**  if they differ at any index. For example, `[1, 1, 2]` and `[1, 2, 1]` are considered different sequences.

 

 **Example 1:** 

 **Input:**  n = 5, k = 3

 **Output:**  3

 **Explanation:** 

The sequences of length `k = 3` whose sum is 5 are:

Sequence	Product	Parity
`[1, 1, 3]`	`1  *1*  3 = 3`	Odd
`[1, 2, 2]`	`1  *2*  2 = 4`	Even
`[2, 1, 2]`	`2  *1*  2 = 4`	Even
`[2, 2, 1]`	`2  *2*  1 = 4`	Even
`[1, 3, 1]`	`1  *3*  1 = 3`	Odd
`[3, 1, 1]`	`3  *1*  1 = 3`	Odd

There are 3 sequences with an even product, thus the answer is 3.

 **Example 2:** 

 **Input:**  n = 3, k = 2

 **Output:**  2

 **Explanation:** 

The sequences of length `k = 2` whose sum is 3 are:

Sequence	Product	Parity
`[1, 2]`	`1 * 2 = 2`	Even
`[2, 1]`	`2 * 1 = 2`	Even

There are 2 sequences with an even product, thus the answer is 2.

 **Example 3:** 

 **Input:**  n = 5, k = 5

 **Output:**  0

 **Explanation:** 

The only possible sequence of length `k = 5` whose sum is 5 is `[1, 1, 1, 1, 1]`, which has an odd product. Thus, the answer is 0.

 

 **Constraints:** 

- 1 <= n <= 5 * 105
- 1 <= k <= n

## Solution

**Language:** C++  
**Runtime:** 71 ms (beats 65.20%)  
**Memory:** 64.1 MB (beats 60.82%)  
**Submitted:** 2026-08-14T08:39:56.127Z  

```cpp
class Solution {
public:
    int mod= 1e9+7;
    vector<int>fact;
    vector<int>invfact;
    
    long long power(long long a,long long b){
        long long res=1;
        while(b){
            if(b&1){
                res= res*a % mod;
            }
            a= a*a % mod;
            b>>=1;
        }
        return res;
    }
    long long comb(int a,int b){
        if(b<0 || b>a) return 0;
        return ((1LL* fact[a] * invfact[b] ) %mod * invfact[a-b]) % mod;
    }
    int countValidSequences(int n, int k) {
        if(n<2 || k<1) return 0;

        //we got mod factorial thus have to calculate power and iinverse factorial
        fact.resize(n+1,1);
        invfact.resize(n+1,1);

        for(int i=2;i<=n;i++){
            fact[i] = (1LL * fact[i-1]*i) % mod;
        }
        invfact[n] = power(fact[n],mod-2)%mod;

        for(int i=n-1;i>=0;i--){
            invfact[i] = (1LL* invfact[i+1]* (i+1) ) %mod;
        }
        long long total = comb(n-1,k-1);
        if( (n-k) % 2 !=0) return total;

        int v= (n+k)/2;
        long long odd= comb(v-1,k-1);

        return (total - odd +mod) % mod;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-valid-sequences/)