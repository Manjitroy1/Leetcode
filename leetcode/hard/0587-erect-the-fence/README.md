# Erect the Fence

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array `trees` where `trees[i] = [xi, yi]` represents the location of a tree in the garden.

Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if  **all the trees are enclosed**.

Return  *the coordinates of trees that are exactly located on the fence perimeter*. You may return the answer in  **any order**.

 

 **Example 1:** 

```
Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.

```

 **Example 2:** 

```
Input: trees = [[1,2],[2,2],[4,2]]
Output: [[4,2],[2,2],[1,2]]
Explanation: The fence forms a line that passes through all the trees.

```

 

 **Constraints:** 

- 1 <= trees.length <= 3000
- trees[i].length == 2
- 0 <= xi, yi <= 100
- All the given positions are unique.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 96.44%)  
**Memory:** 24.3 MB (beats 91.40%)  
**Submitted:** 2026-10-26T14:39:55.943Z  

```cpp
class Solution {
public:
    int calc(pair<int,int>&p1,pair<int,int>&p2,int x3,int y3){
        int x1= p1.first;
        int x2= p2.first;

        int y1= p1.second;
        int y2= p2.second;

        return (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>>result;

        //conver hull
        sort(trees.begin(),trees.end());
        //first one is the first selected one
        
        deque<pair<int,int>>lower,upper;

        for(auto& points:trees){
            int x =points[0];
            int y =points[1];

            int l=lower.size();
            int u=upper.size();

            while(l>=2 && calc(lower[l-2],lower[l-1],x,y) < 0){ //p1,p2,p3
                //we have to remove p2
                lower.pop_back();
                l--;
            }
            while(u>=2 && calc(upper[u-2],upper[u-1],x,y) > 0){
                upper.pop_back();
                u--;
            }
            lower.push_back({x,y});
            upper.push_back({x,y});
        }

        set<pair<int,int>>stt;
        for(auto& points:lower){
            stt.insert(points);
        }
        for(auto& points:upper){
            stt.insert(points);
        }
        for(auto& points :stt){
            result.push_back({points.first,points.second});
        }
        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/erect-the-fence/)