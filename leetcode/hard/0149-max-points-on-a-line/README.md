# Max Points on a Line

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an array of `points` where `points[i] = [xi, yi]` represents a point on the  **X-Y**  plane, return  *the maximum number of points that lie on the same straight line*.

 

 **Example 1:** 

```
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

```

 **Example 2:** 

```
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4

```

 

 **Constraints:** 

- 1 <= points.length <= 300
- points[i].length == 2
- -104 <= xi, yi <= 104
- All the points are unique.

## Solution

**Language:** C++  
**Runtime:** 70 ms (beats 10.81%)  
**Memory:** 30.2 MB (beats 5.95%)  
**Submitted:** 2026-08-20T18:47:52.613Z  

```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // Ay+Bx+C=0
        using t= tuple<int,int,int>;
        map<t,set<int>>mpp;
        int ans=0;
        int n=points.size();
        if(n==1) return 1;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1= points[i][0];
                int y1= points[i][1];

                int x2= points[j][0];
                int y2= points[j][1];

                int a= (x1-x2);
                int b=(y2-y1);
                int c= -1*(b*x1 + a*y1);

                int g=__gcd(abs(a), __gcd(abs(b),abs(c)));
                a/=g;
                b/=g;
                c/=g;

                //we have make unique sign 
                if(a<0 || (a==0 && b<0)){
                    a*=-1;
                    b*=-1;
                    c*=-1;
                }
                
                mpp[{a,b,c}].insert(i);
                mpp[{a,b,c}].insert(j);

            }
        }
        


        for(auto& it:mpp){
            int sz=it.second.size();
            ans= max(ans,sz);
        }
        return ans;
    }

    
};
```

---

[View on LeetCode](https://leetcode.com/problems/max-points-on-a-line/)