# Find Longest Awesome Substring

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `s`. An  **awesome**  substring is a non-empty substring of `s` such that we can make any number of swaps in order to make it a palindrome.

Return  *the length of the maximum length  **awesome substring**  of*  `s`.

 

 **Example 1:** 

```
Input: s = "3242415"
Output: 5
Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.

```

 **Example 2:** 

```
Input: s = "12345678"
Output: 1

```

 **Example 3:** 

```
Input: s = "213123"
Output: 6
Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists only of digits.

## Solution

**Language:** C++  
**Runtime:** 75 ms (beats 61.62%)  
**Memory:** 14 MB (beats 47.81%)  
**Submitted:** 2026-08-20T13:57:10.875Z  

```cpp
class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size();
        int mask=0;
        unordered_map<int,int>mpp;
        int ans=1;

        for(int i=0;i<n;i++){
            int b= s[i]-'0';
            mask ^= (1<<b);

            if(mpp.count(mask)){
                ans= max(ans,i-mpp[mask]);
            }else mpp[mask]=i;

            if(mask==0 || ((mask & (mask-1)) ==0) ){
                ans= max(ans,i+1);
            }

            for(int pos=0;pos<=10;pos++){
                int newmask = mask ^ (1<<pos);
                if(mpp.count(newmask)){
                    ans=max(ans,i-mpp[newmask]);
                }
            }
        }
        return ans;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-longest-awesome-substring/)