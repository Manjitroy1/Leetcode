# Stone Game V

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

There are several stones  **arranged in a row**, and each stone has an associated value which is an integer given in the array `stoneValue`.

In each round of the game, Alice divides the row into  **two non-empty rows**  (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only  **one stone remaining**. Alice's score is initially  **zero**.

Return  *the maximum score that Alice can obtain*.

 

 **Example 1:** 

```
Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.

```

 **Example 2:** 

```
Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28

```

 **Example 3:** 

```
Input: stoneValue = [4]
Output: 0

```

 

 **Constraints:** 

- 1 <= stoneValue.length <= 500
- 1 <= stoneValue[i] <= 106

## Solution

**Language:** C++  
**Runtime:** 393 ms (beats 61.52%)  
**Memory:** 15.3 MB (beats 81.88%)  
**Submitted:** 2026-08-21T09:32:06.774Z  

```cpp
class Solution {
public:
    int dp[500][500];
    int solve(int l,int r,vector<int>&arr,vector<int>&presum){
        //max among min possibilities
        if(r==l) return 0;
        if(r-l==1) return min(arr[l],arr[r]);
        if(dp[l][r]!=-1) return dp[l][r];

        int ans=0;
        for(int k=l;k<r;k++){
            int leftsum= l<1? presum[k] : presum[k]-presum[l-1];
            int rigtsum= presum[r]-presum[k];

            if(leftsum<rigtsum){
                ans= max(ans,leftsum + solve(l,k,arr,presum));
            }
            else if(rigtsum<leftsum){
                ans=max(ans,rigtsum + solve(k+1,r,arr,presum));
            }
            else{
                ans= max(ans,leftsum + max(solve(l,k,arr,presum),solve(k+1,r,arr,presum)));
            }
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        if(n==1) return 0;
        vector<int>presum(n,0);
        presum[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1]+stoneValue[i];
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,stoneValue,presum);
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/stone-game-v/)