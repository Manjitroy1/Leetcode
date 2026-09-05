# Range Queries for At Least K Frequent

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an integer array  **arr[]** and  a 2D array  **queries[][]** of size q × 2, where each queries[i] = [l, r] represents a query on the subarray nums[l...r] (1-based indexing), and an integer k.

For each query, find the count of distinct elements in the specified subarray that occur at least k times.

 **Examples:** 

```
Input: arr[] = [1, 1, 2, 1, 3], queries[][] = [[1, 5], [2, 4]], k = 1
Output: [3, 2]
Explanation: For the 1st query, from l=1 to r=5, 1, 2 and 3 have the frequency at least 1.
For the second query, from l=2 to r=4, 1 and 2 have the frequency at least 1.

```

```
Input: arr[] = [1, 2, 3, 1], queries[][] = [[1, 4], [2, 4], [4, 4], k = 2
Output: [1, 0, 0]
Explanation: For the 1st query, from l=1 to r=4, 1 has frequency 2. 
For the second query, from l=2 to r=4, no number has frequency at least 2.
For the third query, from l=4 to r=4, no number has frequency at least 2. 
```

 **Constraints:** 
1 ≤ n, q, k ≤ 104, where n is the size of the array
1 ≤ nums[i] ≤ 103
1 ≤ queries[i][0] ≤ queries[i][1] ≤ n

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-05T15:51:12.034Z  

```cpp
class Solution {
  public:
  static int block;
  static bool comp(const vector<int>&q1,const vector<int>&q2){
      int b1=q1[0]/block;
      int b2=q2[0]/block;
      if(b1!=b2) return b1<b2; //according to block size least first
      
      return q1[1]<q2[1]; //large value of r last
  }
    vector<int> solveQueries(vector<int>& arr, vector<vector<int>>& queries, int k) {
        //atleast k frequent in the query
        //Reorder the queries so that consecutive queries have similar l and r.
        //with the help of block size
        //l begin with least bloxk index. r with max value r side ,need compartor
        int n=arr.size();
        block=sqrt(n);
        // store the queries with additional value idx
        int q=queries.size();
        
        vector<int>ans(q,0); // answer to be return
        
        for(int i=0;i<q;i++){
            queries[i].push_back(i);
        }
        
        sort(queries.begin(),queries.end(),comp);
        int currl=0;
        int currr=-1;
        int good=0;
        unordered_map<int,int>mpp; // help to find disticnt elem that occur at leask k times
        
        for(int i=0;i<q;i++){
            
            int l=queries[i][0]-1; //zero based
            int r=queries[i][1]-1; //zero based
            int idx=queries[i][2];
            
            while(currl>l){//we have to go left for l
                currl--;
                mpp[arr[currl]]++;
                if(mpp[arr[currl]]==k) good++; //from now going to more than k
                
            }
            while(currr<r){
                currr++;
                mpp[arr[currr]]++;
                if(mpp[arr[currr]]==k) good++;
                
            }
            
            while(currl<l){ //we have to move right for l
                if(mpp[arr[currl]]==k) good--; // from now going to less than k
                mpp[arr[currl]]--;
                currl++;
            }
            
            while(currr>r){
                if(mpp[arr[currr]]==k) good--;
                mpp[arr[currr]]--;
                currr--;
            }
        
            ans[idx]=good;
        }
        return ans;
    }
    
};
int Solution::block;

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/interesting-queries4742/1)