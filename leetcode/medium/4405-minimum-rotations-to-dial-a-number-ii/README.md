# Q2. Minimum Rotations to Dial a Number II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer `n` and a string `s` of length `n` consisting of digits.

The dial contains the digits 0 through 9 in order and is  **circular**, so 0 and 9 are adjacent. The pointer initially points to 0.

To dial each digit of `s`  **in order**, rotate the pointer until it points to that digit. Each rotation moves the pointer to an  **adjacent**  digit, and you may rotate in  **either**  direction. Dialing a digit that the pointer already points to requires no rotations.

Before dialing, you may perform the following operation  **at most once** :

- Choose an index k such that 0 <= k < n and reverse the suffix s[k..n - 1].

Return the  **minimum**  total number of rotations needed to dial the string after optimally choosing whether to perform the operation and which suffix to reverse.

 

 **Example 1:** 

 **Input:**  n = 4, s = "1502"

 **Output:**  9

 **Explanation:** 

Reverse the suffix starting at `k = 1` to obtain `"1205"`, then dial it.

Step	From	To	Rotations
1	0	1	1
2	1	2	1
3	2	0	2
4	0	5	5

The total is `1 + 1 + 2 + 5 = 9`, which is the minimum total number of rotations.

 **Example 2:** 

 **Input:**  n = 4, s = "2916"

 **Output:**  12

 **Explanation:** 

Choose not to reverse a suffix and dial `"2916"`.

Step	From	To	Rotations
1	0	2	2
2	2	9	3
3	9	1	2
4	1	6	5

The total is `2 + 3 + 2 + 5 = 12`, which is the minimum total number of rotations.

 **Example 3:** 

 **Input:**  n = 4, s = "4219"

 **Output:**  6

 **Explanation:** 

Reverse the suffix starting at `k = 0`, which reverses the entire string, to obtain `"9124"`, then dial it.

Step	From	To	Rotations
1	0	9	1
2	9	1	2
3	1	2	1
4	2	4	2

The total is `1 + 2 + 1 + 2 = 6`, which is the minimum total number of rotations.

 

 **Constraints:** 

- 1 <= n == s.length <= 105​​​​​​​
- s consists only of digits '0' to '9'

## Solution

**Language:** C++  
**Runtime:** 9 ms (beats 87.56%)  
**Memory:** 24.1 MB (beats 88.41%)  
**Submitted:** 2026-10-14T05:52:32.888Z  

```cpp
class Solution {
public:
    int minRotations(int n, string s) {
        int ans=0;
        char prev='0';
        // vector<int>store(n);
        for(int i=0;i<n;i++){
            int a= abs(prev - s[i]);
            int b= 10-a;
            ans+=min(a,b);
            prev=s[i];
        }
        char last = s[n-1];
        prev= '0';
        int store = 10;
        
        for(int k=0;k<n-1;k++){
            //cost of k-1 to k 
            int a= abs(prev - s[k]);
            int b= 10-a;
            int first = min(a,b);

            int a2= abs(prev - s[n-1]);
            b= 10-a2;
            int second = min(a2,b);

            prev=s[k];
            //cost of k-1 to last
            store= min(store,second-first);
        }
        return min(ans,ans+store);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-rotations-to-dial-a-number-ii/)