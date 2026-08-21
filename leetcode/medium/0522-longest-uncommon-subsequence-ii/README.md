# Longest Uncommon Subsequence II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of strings `strs`, return  *the length of the  **longest uncommon subsequence**  between them*. If the longest uncommon subsequence does not exist, return `-1`.

An  **uncommon subsequence**  between an array of strings is a string that is a  **subsequence of one string but not the others**.

A  **subsequence**  of a string `s` is a string that can be obtained after deleting any number of characters from `s`.

- For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).

 

 **Example 1:** 

```
Input: strs = ["aba","cdc","eae"]
Output: 3

```

 **Example 2:** 

```
Input: strs = ["aaa","aaa","aa"]
Output: -1

```

 

 **Constraints:** 

- 2 <= strs.length <= 50
- 1 <= strs[i].length <= 10
- strs[i] consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10.8 MB (beats 73.65%)  
**Submitted:** 2026-08-21T13:10:30.194Z  

```cpp
class Solution {
public:
    bool issubseq(string&a, string& b){
        //is a substring of b
        int n1=a.size(),n2=b.size();
        if(n1>n2) return false;

        int i=0,j=0;

        while(i<n1 && j<n2){

            if(a[i]==b[j]){
                i++;
            }
            j++;
        }
        return i==n1;
    }
    int findLUSlength(vector<string>& strs) {

        int n=strs.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            bool uncommon=true;   //we are checking if i can be a answer if uncommon with all
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(issubseq(strs[i],strs[j])){
                    uncommon=false;
                    break;
                }

            }

            if(uncommon){
                ans=max(ans, (int)strs[i].size());
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-uncommon-subsequence-ii/)