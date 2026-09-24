# Josephus problem

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are playing a game with  **n**  people standing in a circle, numbered from  **1** to **n**. Starting from person 1, every  **kth**  person is eliminated in a circular fashion. The process continues until only one person remains.
Given integers n and k, return the position (1-based index) of the person who will survive.

 **Examples :** 

```
Input: n = 5, k = 2
Output: 3
Explanation: Firstly, the person at position 2 is killed, then the person at position 4 is killed, then the person at position 1 is killed. 
Finally, the person at position 5 is killed. So the person at position 3 survives. 
```

```
Input: n = 7, k = 3
Output: 4
Explanation: The elimination order is 3 → 6 → 2 → 7 → 5 → 1, and the person at position 4 survives.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-24T06:10:28.625Z  

```cpp
class Solution {
  public:
    int solve(int n, int k) {
        // code here
        vector<int>person;
        for(int i=1;i<=n;i++){
            person.push_back(i);
        }
        k--;
        int i=0;
        
        while(person.size()>1){
            int s=person.size();
            i = (i+k) % s;
            person.erase(person.begin()+i);
        }
        return person[0];
    }
    int solveq(int n,int k){
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            //we will take k-1 element from the top and push to the queue
            for(int cnt=1;cnt<=k-1;cnt++){
                q.push(q.front());
                q.pop();
            }
            q.pop(); //pop the kth element
        }
        return q.front();
    }
    
    int josephus(int n, int k) {
        // return solve(n,k);
        return solveq(n,k);
    }
    
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/josephus-problem/1)