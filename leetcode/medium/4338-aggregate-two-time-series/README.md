# Q2. Aggregate Two Time Series

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two 2D integer arrays `series1` and `series2`.

Each element in both series is of the form `[timestamp, value]`, where:

- timestamp is an integer representing the time.
- value is an integer representing the value at that timestamp.

Each array is sorted in strictly increasing order of `timestamp`.

For any timestamp  **not present**  in a series, its value is taken from the  **next available timestamp**  in the same series if one exists. Otherwise, its value is considered 0.

The  **aggregated series**  is formed by summing the corresponding values from both series at every timestamp that appears in either series.

Return the  **aggregated series**  as a 2D integer array of `[timestamp, summedValue]` pairs, sorted in  **strictly increasing**  order of timestamp.

 

 **Example 1:** 

 **Input:**  series1 = [[1,3],[4,1]], series2 = [[2,2],[5,2]]

 **Output:**  [[1,5],[2,3],[4,3],[5,2]]

 **Explanation:** 

Timestamp	`series1`	`series2`	`summedValue`
1	3	2	5
2	1	2	3
4	1	2	3
5	0	2	2

Thus, the aggregated series is `[[1, 5], [2, 3], [4, 3], [5, 2]]`.

 **Example 2:** 

 **Input:**  series1 = [[1,5],[3,1]], series2 = [[2,2]]

 **Output:**  [[1,7],[2,3],[3,1]]

 **Explanation:** 

Timestamp	`series1`	`series2`	`summedValue`
1	5	2	7
2	1	2	3
3	1	0	1

Thus, the aggregated series is `[[1, 7], [2, 3], [3, 1]]`.

 **Example 3:** 

 **Input:**  series1 = [[1,5]], series2 = [[1000000000,2]]

 **Output:**  [[1,7],[1000000000,2]]

 **Explanation:** 

At timestamp 1, the next available value in `series2` is 2 at timestamp 1000000000. At timestamp 1000000000, there is no later timestamp in `series1`, so its value is 0. Only timestamps that appear in at least one of the two series are included.

 

 **Constraints:** 

- 1 <= series1.length, series2.length <= 105
- series1[i].length == series2[i].length == 2
- 1 <= series1[i][0], series2[i][0] <= 109
- 1 <= series1[i][1], series2[i][1] <= 109
- Each series is sorted in strictly increasing order of timestamp.

## Solution

**Language:** C++  
**Runtime:** 579 ms (beats 5.89%)  
**Memory:** 447.7 MB (beats 5.83%)  
**Submitted:** 2026-08-13T18:04:47.536Z  

```cpp
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>>ans;
        
        map<int,int>mp;
        map<int,int>mpp;

        set<int>times;

        for(int i=0;i<series1.size();i++){
            int k=series1[i][0];
            int v=series1[i][1];
            mp[k]=v;
            times.insert(k);
        }

         for(int i=0;i<series2.size();i++){
            int k=series2[i][0];
            int v=series2[i][1];
            mpp[k]=v;
            times.insert(k);
        }

        for(int t:times){
            auto it1=mp.lower_bound(t);
            auto it2=mpp.lower_bound(t);

            int v1=0;
            if(it1!=mp.end()){
                v1=it1->second;
            }
            int v2=0;
            if(it2!=mpp.end()){
                v2=it2->second;
            }
            ans.push_back({t,v1+v2});
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/aggregate-two-time-series/)