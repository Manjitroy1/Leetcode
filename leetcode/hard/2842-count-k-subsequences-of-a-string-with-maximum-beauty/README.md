# Count K-Subsequences of a String With Maximum Beauty

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `s` and an integer `k`.

A  **k-subsequence**  is a  **subsequence**  of `s`, having length `k`, and all its characters are  **unique**,  **i.e**., every character occurs once.

Let `f(c)` denote the number of times the character `c` occurs in `s`.

The  **beauty**  of a  **k-subsequence**  is the  **sum**  of `f(c)` for every character `c` in the k-subsequence.

For example, consider `s = "abbbdd"` and `k = 2`:

- f('a') = 1, f('b') = 3, f('d') = 2
- Some k-subsequences of s are: "abbbdd" -> "ab" having a beauty of f('a') + f('b') = 4 "abbbdd" -> "ad" having a beauty of f('a') + f('d') = 3 "abbbdd" -> "bd" having a beauty of f('b') + f('d') = 5

Return *an integer denoting the number of k-subsequences  **whose** beauty **is the** maximum **among all** k-subsequences***. Since the answer may be too large, return it modulo `109 + 7`.

A subsequence of a string is a new string formed from the original string by deleting some (possibly none) of the characters without disturbing the relative positions of the remaining characters.

 **Notes** 

- f(c) is the number of times a character c occurs in s, not a k-subsequence.
- Two k-subsequences are considered different if one is formed by an index that is not present in the other. So, two k-subsequences may form the same string.

 

 **Example 1:** 

```
Input: s = "bcca", k = 2
Output: 4
Explanation: From s we have f('a') = 1, f('b') = 1, and f('c') = 2.
The k-subsequences of s are: 
bcca having a beauty of f('b') + f('c') = 3 
bcca having a beauty of f('b') + f('c') = 3 
bcca having a beauty of f('b') + f('a') = 2 
bcca having a beauty of f('c') + f('a') = 3
bcca having a beauty of f('c') + f('a') = 3 
There are 4 k-subsequences that have the maximum beauty, 3. 
Hence, the answer is 4. 

```

 **Example 2:** 

```
Input: s = "abbcd", k = 4
Output: 2
Explanation: From s we have f('a') = 1, f('b') = 2, f('c') = 1, and f('d') = 1. 
The k-subsequences of s are: 
abbcd having a beauty of f('a') + f('b') + f('c') + f('d') = 5
abbcd having a beauty of f('a') + f('b') + f('c') + f('d') = 5 
There are 2 k-subsequences that have the maximum beauty, 5. 
Hence, the answer is 2. 

```

 

 **Constraints:** 

- 1 <= s.length <= 2 * 105
- 1 <= k <= s.length
- s consists only of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8 MB  
**Submitted:** 2026-09-07T11:10:12.579Z  

```cpp
#define ll long long
class Solution {
public:
    const ll mod=1e9+7;
    ll powmod(ll a,ll p){
        ll res=1;
        while(p){
            if(p & 1){
                res=(res*a) % mod;
            }
            a= (a*a) % mod;
            p>>=1;
        }
        return res;
    }
    ll comb(int n,int r){
        r=min(r,n-r);
        ll ways=1;

        for(int i=0;i<r;i++){
            ways = (ways* (n-i)) % mod;
            ways = (ways* powmod(i+1,mod-2)) % mod;
        }
        return ways;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int n=s.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        if(freq.size()<k || k > 26) return 0;
        // if(freq.size()==k) return 1;
        vector<int>nums;
        for(auto& node:freq){
            nums.push_back(node.second);
        }

        sort(nums.rbegin(),nums.rend()); //sort in desc
        //we have to find sum of last k element 
        //that is the maximum among all k-subsequences that equal to target
        // we have to find total possible k element sum == target
        //total possibility is the product of that k window
        int m=nums.size();

        int x=nums[k-1];
        //number of number greater than x;
        int greater=0;
        ll ans=1;

        for(int elem:nums){
            if(elem>x){
                ans= (ans * 1LL*elem)%mod;
                greater++;
            }
        }

        int need = k-greater;

        //eqal to x
        int equal=0;
        for(int elem:nums){
            if(elem==x){
                equal++;
            }
        }

        // number of combination of x::  comb(equal,need)
        ll ways=1;
        ways=comb(equal,need);
        ans= (ans*ways)%mod;

        for(int i=0;i<need;i++){
            ans=(ans*x)%mod;
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-k-subsequences-of-a-string-with-maximum-beauty/)