# Q4. Elevator Requests III

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer `n` denoting the number of floors in a building, where the floors are numbered from 0 to `n - 1`.

You are also given an integer `start` and a 2D integer array `requests`, where `requests[i] = [arrivali, floori]` indicates that a request for `floori` is made at time `arrivali`.

At time 0, the elevator is at floor `start`.

At each second, the elevator may move  **up**  by 1 floor, move  **down**  by 1 floor, or  **remain**  on its current floor.

A request can be fulfilled  **only**  at or after its arrival time; it is fulfilled  **instantly**  when the elevator is on its requested floor at any time from its arrival time onward.

Return the  **minimum**  time needed to fulfill all requests.

 

 **Example 1:** 

 **Input:**  n = 9, start = 0, requests = [[0,8],[6,5]]

 **Output:**  9

 **Explanation:** 

- Move from floor 0 (start) to floor 5 (requests[1][1]) in 5 seconds, reaching at time 5. Since requests[1][0] = 6, wait until time 6 to fulfill it.
- Move from floor 5 to floor 8 (requests[0][1]) in 3 seconds, fulfilling it at time 9.

Thus, all requests are fulfilled by time 9.

 **Example 2:** 

 **Input:**  n = 8, start = 5, requests = [[1,7],[7,3]]

 **Output:**  7

 **Explanation:** 

- Move from floor 5 (start) to floor 7 (requests[0][1]) in 2 seconds, reaching at time 2. Since requests[0][0] = 1 has already passed, floor 7 is fulfilled at time 2.
- Move from floor 7 to floor 3 (requests[1][1]) in 4 seconds, reaching at time 6. Since requests[1][0] = 7, wait until time 7.

Thus, all requests are fulfilled by time 7.

 **Example 3:** 

 **Input:**  n = 7, start = 3, requests = [[0,5],[0,1],[6,3]]

 **Output:**  8

 **Explanation:** 

- Move from floor 3 (start) to floor 5 (requests[0][1]) in 2 seconds, fulfilling it at time 2.
- Move from floor 5 to floor 1 (requests[1][1]) in 4 seconds, fulfilling it at time 6.
- Move from floor 1 to floor 3 (requests[2][1]) in 2 seconds, reaching at time 8. Its request arrived at requests[2][0] = 6, so floor 3 is fulfilled at time 8.

Thus, all requests are fulfilled by time 8.

 

 **Constraints:** 

- 1 <= n <= 109
- 1 <= requests.length <= 16
- requests[i] == [arrivali, floori]
- 0 <= arrivali <= 109
- 0 <= start, floori <= n - 1

## Solution

**Language:** C++  
**Runtime:** 322 ms (beats 50.00%)  
**Memory:** 125.3 MB (beats 50.00%)  
**Submitted:** 2026-08-17T06:39:59.920Z  

```cpp
class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m=requests.size();
        int total=1<<m;
        vector<vector<long long>>dp(total,vector<long long>(m,LLONG_MAX));

        // int dummymask=0;
        
        for(int i=0;i<m;i++){
            long long arrive= 1LL* requests[i][0];
            int floor= requests[i][1];
            // dummymask |= (1<<floor);

            long long time = abs(start-floor);
            time = max(time,arrive);
            dp[1<<i][i]= time;
        }

        for(int mask=1;mask<total;mask++){
            for(int last=0;last<m;last++){
                if( !(mask & 1<<last)) continue;
                if(dp[mask][last]>=LLONG_MAX) continue;
                
                long long currtime= dp[mask][last];
                int currfloor = requests[last][1];

                for(int j=0;j<m;j++){
                    if(mask & (1<<j)) continue;
                    int nxtfloor=requests[j][1];
                    long long arrival= 1LL*requests[j][0];
                    
                    long long newtime = currtime + abs(nxtfloor-currfloor);
                    int newmask = mask | (1<<j);
                    newtime = max(newtime, arrival);
                    dp[newmask][j] = min(newtime,dp[newmask][j]);
                }
            }
        }
        int full= (1<<m) -1;
        
        long long ans = LLONG_MAX;
        for(int i=0;i<m;i++){
            ans = min(ans,dp[full][i]);
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/elevator-requests-iii/)