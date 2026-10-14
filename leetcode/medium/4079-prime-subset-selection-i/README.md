# Q2. Prime Subset Selection I

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two integers `n` and `s`.

Consider all  **prime**  numbers less than or equal to `n`. Select some of these primes such that:

- The sum of the selected primes is less than or equal to s.
- The number of selected primes is maximized.
- Each prime can be selected at most once.

Return an integer array containing the selected primes in  **increasing**  order. If multiple optimal selections exist, return  **any**  of them.

If no prime can be selected, return an  **empty**  array.

 

 **Example 1:** 

 **Input:**  n = 7, s = 20

 **Output:**  [2,3,5,7]

 **Explanation:** 

- The prime numbers less than or equal to n = 7 are 2, 3, 5, and 7.
- The sum of all these primes is 2 + 3 + 5 + 7 = 17, which is less than or equal to s = 20.
- Thus, the answer is [2, 3, 5, 7].

 **Example 2:** 

 **Input:**  n = 15, s = 15

 **Output:**  [3,5,7]

 **Explanation:** 

- The prime numbers less than or equal to n = 15 are 2, 3, 5, 7, 11, and 13.
- One possible selection is [3, 5, 7], whose sum is 3 + 5 + 7 = 15.
- The four smallest available primes have sum 2 + 3 + 5 + 7 = 17, which exceeds s = 15. Therefore, selecting four or more primes is impossible, and the maximum number of selected primes is three.
- Thus, [3, 5, 7] is one possible answer. Other valid answers include [2, 3, 5], [2, 3, 7], and [2, 5, 7].

 **Example 3:** 

 **Input:**  n = 5, s = 1

 **Output:**  []

 **Explanation:** 

- The smallest prime number is 2, which is greater than s = 1.
- Thus, no prime can be selected, so the answer is an empty array.

 

 **Constraints:** 

- 1 <= n <= 106
- 1 <= s <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8.6 MB  
**Submitted:** 2026-10-14T14:15:02.010Z  

```cpp
class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        //sieve of erast
        int total = n;
        vector<bool>prime(total+1,true);
        prime[0]=false;
        prime[1]=false;

        vector<int>store;
        for(int i=2;i*i<=total;i++){
            if(prime[i]){
                for(int j=i*i;j<=total;j+=i){
                    prime[j]=false;
                }
            }
        }
        int sum=0;
        for(int i=2;i<=n;i++){
            if(prime[i] && sum+i<=s){
                sum+=i;
                store.push_back(i);
            }
        }
        return store;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/prime-subset-selection-i/)