# Q3. Longest Subarray With at Most K Distinct Prime Factors

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` consisting of positive integers and an integer `k`.

The  **prime factor set**  of a  **subarray**  is the  **union**  of the distinct  **prime**  factors of all its elements.

Return the length of the  **longest**  subarray whose prime factor set contains  **at most**  `k` distinct prime factors. If no such subarray exists, return 0.

 

 **Example 1:** 

 **Input:**  nums = [7,6,10,12,11], k = 3

 **Output:**  3

 **Explanation:** 

Consider the subarray `[6, 10, 12]`:

- The distinct prime factors of 6 are {2, 3}.
- The distinct prime factors of 10 are {2, 5}.
- The distinct prime factors of 12 are {2, 3}.
- The union of these sets is {2, 3, 5}, which contains 3 distinct prime factors.

No longer subarray satisfies the condition. Therefore, the answer is 3.

 **Example 2:** 

 **Input:**  nums = [4,6,9,18], k = 4

 **Output:**  4

 **Explanation:** 

Consider the entire array `[4, 6, 9, 18]`:

- The distinct prime factors of 4 are {2}.
- The distinct prime factors of 6 are {2, 3}.
- The distinct prime factors of 9 are {3}.
- The distinct prime factors of 18 are {2, 3}.
- The union of these sets is {2, 3}, which contains 2 distinct prime factors.

Since `2 <= 4`, the entire array is valid. Therefore, the answer is 4.

 **Example 3:** 

 **Input:**  nums = [6,10,15], k = 2

 **Output:**  1

 **Explanation:** 

Every subarray of length at least 2 has prime factor set `{2, 3, 5}`, which contains 3 distinct prime factors.

Since `3 > 2`, only subarrays of length 1 are valid. Therefore, the answer is 1.

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 2 <= nums[i] <= 105
- 1 <= k <= 104

## Solution

**Language:** C++  
**Runtime:** 3 ms  
**Memory:** 9.9 MB  
**Submitted:** 2026-09-05T13:50:11.289Z  

```cpp
class Solution {
public:
    int total=1e5+1;
    vector<int>prime;

    void minprimefactor(vector<int>&prime){
        int n=prime.size();
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i<n;i++){
            prime[i]=i;
        }
        for(int i=2;i*i<n;i++){
            if(prime[i]==i){
                
                for(int j=i*i;j<n;j+=i){
                    if(prime[j]==1) prime[j]=i;
                }
            }else continue;
        }
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        prime=vector<int>(total,1);
        minprimefactor(prime);

        //i have to store each num factors
        vector<vector<int>>factors;
        
        for(int i=0;i<n;i++){
            vector<int>store;
            int num=nums[i];

            while(num>1){
                int f=prime[num];
                store.push_back(f);
                
                while(num%f==0){
                    num/=f;
                }
            }
            factors.push_back(store);
        }

        // i have factors of each
        //we need map
        unordered_map<int,int>mpp;
        int l=0;
        int r=0;
        //we need atmost k prime factors
        while(r<n){
            for(int pf:factors[r]){
                mpp[pf]++;
            }
            while(mpp.size()>k){
                //we will reduce the size
                //remove all the factors of num
                for(int pf:factors[l]){
                    mpp[pf]--;
                    if(mpp[pf]==0) mpp.erase(pf);
                }
                l++;
            }
            //now we have size less than k
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-subarray-with-at-most-k-distinct-prime-factors/)