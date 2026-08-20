# Candy

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

There are `n` children standing in a line.

Each child is assigned a rating value given in the integer array `ratings`.

You are giving candies to these children subjected to the following requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

Return the  **minimum**  number of candies you need to have to distribute the candies to the children.

 

 **Example 1:** 

```
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

```

 **Example 2:** 

```
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

```

 

 **Constraints:** 

- 1 <= n == ratings.length <= 5 * 104
- 0 <= ratings[i] <= 5 * 104

## Solution

**Language:** C++  
**Runtime:** 59 ms (beats 5.09%)  
**Memory:** 81.3 MB (beats 5.16%)  
**Submitted:** 2026-08-20T14:51:01.839Z  

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candy(n,0);

        using t=pair<int,int>;
        priority_queue<t,vector<t>,greater<t>>pq;

        for(int i=0;i<n;i++){
            pq.push({ratings[i],i});
        }

        while(!pq.empty()){
            auto node= pq.top();
            pq.pop();

            int v=node.first;
            int idx=node.second;


            int l = idx-1 >=0 ? ratings[idx-1]: 1e9;
            int r = idx+1 <n ? ratings[idx+1]: 1e9;

            int mnrating=min(l,r);

            int left = idx-1 >=0 ? candy[idx-1]:0;
            int right = idx+1 <n ? candy[idx+1]:0;

           //both small
           if(mnrating>=v) candy[idx] = 1;
           else if(l<v && r<v){
                candy[idx] =max(left,right)+1;
           }
           //both big or both equal
           //one small one equal  or one big one small rating
           else if(l<v){
            candy[idx] = left+1;
           }else{
            candy[idx]= right +1;
           }

        }
        return accumulate(candy.begin(),candy.end(),0);
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/candy/)