# Make Array Strictly Increasing

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two integer arrays `arr1` and `arr2`, return the minimum number of operations (possibly zero) needed to make `arr1` strictly increasing.

In one operation, you can choose two indices `0 <= i < arr1.length` and `0 <= j < arr2.length` and do the assignment `arr1[i] = arr2[j]`.

If there is no way to make `arr1` strictly increasing, return `-1`.

 

 **Example 1:** 

```
Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].

```

 **Example 2:** 

```
Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

```

 **Example 3:** 

```
Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.
```

 

 **Constraints:** 

- 1 <= arr1.length, arr2.length <= 2000
- 0 <= arr1[i], arr2[i] <= 10^9

## Solution

**Language:** C++  
**Runtime:** 314 ms (beats 67.06%)  
**Memory:** 77.4 MB (beats 67.64%)  
**Submitted:** 2026-08-28T18:34:53.193Z  

```cpp
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        arr2.erase(unique(arr2.begin(),arr2.end()),arr2.end()); //unique element
        int n=arr1.size();
        int m=arr2.size();
        //we have two choices
        //keep the same number or replace with the upperbound with cost 1

        // dp[last]= minimum operation 
        map<int,int>dp; //prev element with mininum cost till that index

        dp[arr1[0]]=0; //keep the same;
        

        if(!arr2.empty()){
            //minimum value 
            if(arr2[0]<arr1[0]) dp[arr2[0]]=1;
            // dp[arr2[0]]=1; //replace with the first elem of arr2
        }
       

        for(int i=1;i<n;i++){ //try for all possible index
            map<int,int>newdp; ///we will create newdp with help of prevone

            for(const auto&[last,cost]:dp){
                //we will not replace
                if(arr1[i]>last){
                    if(!newdp.count(arr1[i])){
                        newdp[arr1[i]]=cost;
                    }
                    else{
                        newdp[arr1[i]] = min(newdp[arr1[i]],cost);
                    }
                }
                //we will replace with upperbound
                auto it=upper_bound(arr2.begin(),arr2.end(),last);
                if(it!=arr2.end()){//there is an upperbound val
                    int val=*it;
                    if(!newdp.count(val)){
                        newdp[val]=cost+1;
                    }else{
                        newdp[val]=min(newdp[val],cost+1);
                    }
                }

            }
            dp=newdp;
        }
        int ans=INT_MAX;
        for(const auto& [last,cost]:dp){
            ans=min(ans,cost);
        }  

        return ans>=INT_MAX? -1:ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/make-array-strictly-increasing/)