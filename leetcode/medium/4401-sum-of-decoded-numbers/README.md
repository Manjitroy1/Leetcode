# Q2. Sum of Decoded Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums`.

Each `nums[i]` is an  **encoded**  integer representing two positive integers `xi` and `yi`. To decode `nums[i]`, define:

- widthi = nums[i] % 10.
- di = floor(nums[i] / 10).
- xi as the integer formed by the first widthi digits of the decimal representation of di.
- yi as the integer formed by all remaining digits of the decimal representation of di.

It is guaranteed that the decimal representation of `di` contains more than `widthi` digits. Therefore, both `xi` and `yi` contain at least one digit.

The  **decoded value**  of `nums[i]` is `xiyi`.

Return the sum of the decoded values of all elements in `nums`, modulo `109 + 7`.

The `floor()` function returns the integer part of the division.

 

 **Example 1:** 

 **Input:**  nums = [231]

 **Output:**  8

 **Explanation:** 

- For 231, we have width = 1, d = 23, x = 2, and y = 3.
- The decoded value of 231 is 23 = 8.
- Since there is only one element in nums, the sum of the decoded values is 8.

 **Example 2:** 

 **Input:**  nums = [2522,2101]

 **Output:**  1649

 **Explanation:** 

- For 2522, we have width = 2, d = 252, x = 25, and y = 2.
- The decoded value of 2522 is 252 = 625.
- For 2101, we have width = 1, d = 210, x = 2, and y = 10.
- The decoded value of 2101 is 210 = 1024.
- The sum of the decoded values is 625 + 1024 = 1649.

 **Example 3:** 

 **Input:**  nums = [2301]

 **Output:**  73741817

 **Explanation:** 

- For 2301, we have width = 1, d = 230, x = 2, and y = 30.
- The decoded value is 230 = 1073741824.
- Therefore, the answer is 1073741824 modulo (109 + 7) = 73741817.

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 100 < nums[i] < 1015
- 1 <= widthi <= 9
- 1 <= xi, yi < 109
- The digit sequences used to form xi and yi do not have leading zeros.
- It is guaranteed that every element in nums is a valid encoded integer.

## Solution

**Language:** C++  
**Runtime:** 47 ms (beats 86.99%)  
**Memory:** 88.9 MB (beats 84.33%)  
**Submitted:** 2026-09-05T11:34:47.267Z  

```cpp
class Solution {
public:
    const long long mod= 1e9+7;

    long long power(long long a,long long p){
        long long res=1;
        while(p){
            if(p & 1) res=(res*a) % mod;
            a=(a*a)%mod;
            p>>=1;
        }
        return res;
    }

    long long solve(long long num){
        int w=num%10;
        long long d= num/10;

        long long dup=d;
        int len=0;
        
        while(dup){
            dup/=10;
            len++;
        }

        long long p=1;
        for(int i=0;i<len-w;i++){
            p*=10;
        }
        long long y=d%p;
        long long x=d/p;
        return power(x,y);
        
    }
    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
        long long sum=0;

        for(int i=0;i<n;i++){
            sum = (sum + solve(nums[i])) % mod;
        }
        return (int) sum;
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sum-of-decoded-numbers/)