# Numbers At Most N Given Digit Set

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an array of `digits` which is sorted in  **non-decreasing**  order. You can write numbers using each `digits[i]` as many times as we want. For example, if `digits = ['1','3','5']`, we may write numbers such as `'13'`, `'551'`, and `'1351315'`.

Return  *the number of positive integers that can be generated* that are less than or equal to a given integer `n`.

 

 **Example 1:** 

```
Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.

```

 **Example 2:** 

```
Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation: 
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.

```

 **Example 3:** 

```
Input: digits = ["7"], n = 8
Output: 1

```

 

 **Constraints:** 

- 1 <= digits.length <= 9
- digits[i].length == 1
- digits[i] is a digit from '1' to '9'.
- All the values in digits are unique.
- digits is sorted in non-decreasing order.
- 1 <= n <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 11.4 MB (beats 12.05%)  
**Submitted:** 2026-08-18T12:33:12.718Z  

```cpp
class Solution {
public:
    int dp[20][2];
    int countways(int pos,int tight,vector<string>&dig,vector<string>&digits){
        if(pos==dig.size()) return 1;

        if(dp[pos][tight]!=-1) return dp[pos][tight];
        
        int res=0;

        string limit = tight? dig[pos]:"9";

        for(string d:digits){
            if(d<=limit){
                //we ca use this digit
                int newtight = tight && (dig[pos]==d);
                res+=countways(pos+1,newtight,dig,digits);
            }

        }
        return dp[pos][tight] = res;
    }
    int solve(int n,vector<string>&dig,vector<string>& digits){
        if(n<=0) return 0;

        while(n){
            dig.push_back(to_string(n%10));
            n/=10;
        }
        reverse(dig.begin(),dig.end());

        int sz=dig.size();  //the number is of sz size
        int choice=digits.size();
        //total number of numbers possible leass than sz size with dig of digits
        int ans=0;
        for(int len=1;len<sz;len++){
            ans+=pow(choice,len);
        }
        ans+=countways(0,1,dig,digits);
        return ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<string>dig;
        memset(dp,-1,sizeof(dp));
        return solve(n,dig,digits);
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/)