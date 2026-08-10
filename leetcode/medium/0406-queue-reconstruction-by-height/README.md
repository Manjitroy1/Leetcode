# Queue Reconstruction by Height

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array of people, `people`, which are the attributes of some people in a queue (not necessarily in order). Each `people[i] = [hi, ki]` represents the `ith` person of height `hi` with  **exactly**  `ki` other people in front who have a height greater than or equal to `hi`.

Reconstruct and return  *the queue that is represented by the input array* `people`. The returned queue should be formatted as an array `queue`, where `queue[j] = [hj, kj]` is the attributes of the `jth` person in the queue (`queue[0]` is the person at the front of the queue).

 

 **Example 1:** 

```
Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.

```

 **Example 2:** 

```
Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]

```

 

 **Constraints:** 

- 1 <= people.length <= 2000
- 0 <= hi <= 106
- 0 <= ki < people.length
- It is guaranteed that the queue can be reconstructed.

## Solution

**Language:** C++  
**Runtime:** 23 ms (beats 30.34%)  
**Memory:** 16.2 MB (beats 34.88%)  
**Submitted:** 2026-08-10T13:56:02.683Z  

```cpp
// class SGT{
// public:
//     vector<int>sgt;
//     SGT(int n){
//         sgt.resize(4*n+1);
//     }
//     //build
//     void build(int idx,int low,int high,vector<int>&arr){
//         if(low==high){
//             sgt[idx]=arr[low];
//             return;
//         }
//         int mid= (low+high)>>1;
//         build(2*idx+1,low,mid,arr);
//         build(2*idx+2,mid+1,high,arr);

//         sgt[idx] = min(sgt[2*idx + 1], sgt[2*idx + 2]);
//     }

//     //find
//     int find(int idx,int low,int high,int l,int r){
//         //no overlap.  l r low high    low high l r
//         if(r<low || l>high) return INT_MAX;
//         //complete overlap.  l low high  r
//         if(l<=low && high<=r) return sgt[idx];
//         //partial overlap
//         int mid= (low+high)>>1;

//         int left= find(2*idx+1,low,mid,l,r);
//         int right=find(2*idx+2,mid+1,high,l,r);

//         return min(left,right);
//     }
// };

class Solution {
public:
static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];  //ascending by k position
        }
        return a[0]>b[0];  //descending by height
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);  

        vector<vector<int>>ans;
        ans.push_back(people[0]);

        for(int i=1;i<people.size();i++){
            int h=people[i][0];
            int k=people[i][1];
            ans.insert(ans.begin()+k, people[i]);
        } 
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/queue-reconstruction-by-height/)