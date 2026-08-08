# Permutation Sequence

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

The set `[1, 2, 3,..., n]` contains a total of `n!` unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for `n = 3`:

- "123"
- "132"
- "213"
- "231"
- "312"
- "321"

Given `n` and `k`, return the `kth` permutation sequence.

 

 **Example 1:** 

```
Input: n = 3, k = 3
Output: "213"

```

 **Example 2:** 

```
Input: n = 4, k = 9
Output: "2314"

```

 **Example 3:** 

```
Input: n = 3, k = 1
Output: "123"

```

 

 **Constraints:** 

- 1 <= n <= 9
- 1 <= k <= n!

## Solution

**Language:** C++  
**Runtime:** 55 ms (beats 16.54%)  
**Memory:** 7.8 MB (beats 98.04%)  
**Submitted:** 2026-08-08T08:54:09.615Z  

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        string arr="";
        for(int i=1;i<=n;i++){
            // arr.push_back(i);
            arr+=(i+'0');
        }
        string ans="";
        do{
            if(k==1) ans=arr;
            k--;
        }while(k && next_permutation(arr.begin(),arr.end()));
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/permutation-sequence/)