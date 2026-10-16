# Meeting Rooms III

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer `n`. There are `n` rooms numbered from `0` to `n - 1`.

You are given a 2D integer array `meetings` where `meetings[i] = [starti, endi]` means that a meeting will be held during the  **half-closed**  time interval `[starti, endi)`. All the values of `starti` are  **unique**.

Meetings are allocated to rooms in the following manner:

- Each meeting will take place in the unused room with the lowest number.
- If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
- When a room becomes unused, meetings that have an earlier original start time should be given the room.

Return *the  **number**  of the room that held the most meetings.* If there are multiple rooms, return *the room with the  **lowest**  number.* 

A  **half-closed interval**  `[a, b)` is the interval between `a` and `b`  **including**  `a` and  **not including**  `b`.

 

 **Example 1:** 

```
Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 

```

 **Example 2:** 

```
Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 

```

 

 **Constraints:** 

- 1 <= n <= 100
- 1 <= meetings.length <= 105
- meetings[i].length == 2
- 0 <= starti < endi <= 5 * 105
- All the values of starti are unique.

## Solution

**Language:** C++  
**Runtime:** 109 ms (beats 33.77%)  
**Memory:** 125.9 MB (beats 38.01%)  
**Submitted:** 2026-10-16T10:58:07.930Z  

```cpp
#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //i have unique start time
        //number of rooms is less than 100

        //for this meething find the lowest room number that is avail
        sort(meetings.begin(),meetings.end());
        //first apply the brute force
        vector<vector<ll>>room(n,vector<ll>(2,0)); // end time , cnt
        int m= meetings.size();
        ll ans=0;

        for(int i=0;i<m;i++){
            //all are full then find the min endone
            ll mn=room[0][0]; //end time of the first room
            int idx=0;
            bool done=true;

            for(int j=0;j<n;j++){
                if(mn > room[j][0]){
                    idx=j;
                    mn=room[j][0];
                }
                //i got endtime less than curr start put this
                if(room[j][0]<=meetings[i][0]){
                    //i will take this room
                    room[j][0] = meetings[i][1];
                    room[j][1]++;
                    ans=max(ans,room[j][1]);
                    done=false;
                    break;
                }

            }
            if(done){//i have to give room for this meeting 
                //assign the that is ending soon \\ i have idx
                room[idx][0] = mn + (meetings[i][1] - meetings[i][0]);
                room[idx][1]++;
                ans=max(ans,room[idx][1]);
            }
        }
        for(int i=0;i<n;i++){
            // cout<<room[i][0]<<" "<<room[i][1]<<endl;

            if(room[i][1]==ans){
                return i;
            }
        }
        return 0;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/meeting-rooms-iii/)