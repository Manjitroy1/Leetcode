# Ways to Express as Sum of Consecutives

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a number  **n**, find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.

 **Examples:** 

```
Input: n = 10
Output: 1
Explanation: There is only one way, 10 = 1+2+3+4.
```

```
Input: n = 15
Output: 3
Explanation: There are 3 ways, (15 = 1+2+3+4+5), (15 = 4+5+6) and (15 = 7+8).
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-10T15:35:26.234Z  

```cpp
#define ll long long

class Solution {
  public:
    int getCount(int n) {
        // code here
        int ans=0;
        for(int a=1;a<n;a++){
            ll d = 1LL*2*n + 1LL*a*(a-1);
            d*=4LL;
            d+=1;
            //d must be perfect square
            ll p = sqrt(d);
            if(p*p == d){
                if(p%2 && p>2){
                    int b = (-1+p)/2;
                    if(b>a){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/count-of-sum-of-consecutives3741/1)