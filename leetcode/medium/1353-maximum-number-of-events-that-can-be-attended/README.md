# Maximum Number of Events That Can Be Attended

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array of `events` where `events[i] = [startDayi, endDayi]`. Every event `i` starts at `startDayi` and ends at `endDayi`.

You can attend an event `i` at any day `d` where `startDayi <= d <= endDayi`. You can only attend one event at any time `d`.

Return  *the maximum number of events you can attend*.

 

 **Example 1:** 

```
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.

```

 **Example 2:** 

```
Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4

```

 

 **Constraints:** 

- 1 <= events.length <= 105
- events[i].length == 2
- 1 <= startDayi <= endDayi <= 105

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 8 MB  
**Submitted:** 2026-10-16T06:00:42.753Z  

```cpp
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq; //contains end time in ascending order

        int day=0;//starting day
        int cnt=0;
        int i=0;
        //we will try to complete with minimum  ending date from o to i
        //if ending is less than current day we can attend

        while(i<n || !pq.empty()){
            if(pq.empty()){
                day = max(0,events[i][0]);
            }
            //push the elements whose start is less than day
            while(i<n && events[i][0] <= day){
                pq.push(events[i][1]);
                i++;
            }
            // if ending is less than day we cannot attend those
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
            while(!pq.empty()){
                pq.pop();
                cnt++;
                day++;
            }
        }
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)