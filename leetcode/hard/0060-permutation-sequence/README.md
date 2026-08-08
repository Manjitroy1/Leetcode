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
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.1 MB (beats 81.82%)  
**Submitted:** 2026-08-08T09:30:43.730Z  

```cpp
class Solution {
public:

string sovle(int n, int k) {
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
    int next(vector<int>&arr,int pos){
        //first indx that is not used
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                cnt++;
                if(cnt==pos){
                    arr[i]=0;
                    return i+1;
                }
            }
        }
        return 0;
    }
    string solveopt(int n,int k){
        vector<int>fact(n);
        fact[0]=1;
        for(int i=1;i<n;i++){
            fact[i]=i* fact[i-1];
        }

        string s="";
        for(int i=1;i<=n;i++){
            s+=(i+'0');
        }

        k--; // zero based

        string ans="";
        for(int i=n;i>=1;i--){
            int pos = k/fact[i-1];
            ans+= s[pos];
            s.erase(s.begin()+pos);
            k%=fact[i-1];
        }
        return ans;
       
    }
    string getPermutation(int n, int k) {
        // return solve(n,k);
        return solveopt(n,k);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/permutation-sequence/)