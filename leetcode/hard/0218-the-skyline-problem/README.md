# The Skyline Problem

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

A city's  **skyline**  is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return  *the  **skyline**  formed by these buildings collectively*.

The geometric information of each building is given in the array `buildings` where `buildings[i] = [lefti, righti, heighti]`:

- lefti is the x coordinate of the left edge of the ith building.
- righti is the x coordinate of the right edge of the ith building.
- heighti is the height of the ith building.

You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height `0`.

The  **skyline**  should be represented as a list of "key points"  **sorted by their x-coordinate**  in the form `[[x1,y1],[x2,y2],...]`. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate `0` and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

 **Note:**  There must be no consecutive horizontal lines of equal height in the output skyline. For instance, `[...,[2 3],[4 5],[7 5],[11 5],[12 7],...]` is not acceptable; the three lines of height 5 should be merged into one in the final output as such: `[...,[2 3],[4 5],[12 7],...]`

 

 **Example 1:** 

```
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.

```

 **Example 2:** 

```
Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]

```

 

 **Constraints:** 

- 1 <= buildings.length <= 104
- 0 <= lefti < righti <= 231 - 1
- 1 <= heighti <= 231 - 1
- buildings is sorted by lefti in non-decreasing order.

## Solution

**Language:** C++  
**Runtime:** 16 ms (beats 45.26%)  
**Memory:** 27.6 MB (beats 82.30%)  
**Submitted:** 2026-10-08T13:29:09.087Z  

```cpp
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //sorted by their x coordinates
        vector<pair<int,int>>events;
        vector<vector<int>>ans;

        for(auto& node : buildings){
            int s=node[0];
            int e=node[1];
            int h=node[2];
            
            events.push_back({s,h});
            events.push_back({e,-h});
        }
        sort(events.begin(),events.end());

        //we want at this x the maximum active height we have
        multiset<int>stt; //can hold multiple values
        stt.insert(0);
        int prev=0;
        int i=0;
        
        while(i<events.size()){
            int x= events[i].first;
            while(i<events.size() && events[i].first==x){
                int h=events[i].second;

                if(h>0){
                    stt.insert(h);
                }else{  
                    stt.erase(stt.find(-h)); //to delete one instance
                }
                i++;
            }
            int mxh=*stt.rbegin();
            if(mxh!=prev){
                ans.push_back({x,mxh});
                prev=mxh;
            }

        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/the-skyline-problem/)