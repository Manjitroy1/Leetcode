# Q2. Widest Possible Fence

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `planks`, where `planks[i]` represents the height of the `ith` wooden plank. Each plank has a width of 1 unit.

You want to build a fence consisting of planks that all have the  **same**  height.

You may either use a plank as is, or combine  **exactly**  two distinct original planks into a single plank whose height  **equals**  the sum of their heights. Each original plank can be used  **at most**  once, and not all original planks need to be used.

Return the  **maximum possible width**  of the fence that can be built.

 

 **Example 1:** 

 **Input:**  planks = [1,3,2,5,7,5,4,2,1]

 **Output:**  4

 **Explanation:** 

We can have four planks of height 5.

- planks[3] = 5
- planks[5] = 5
- planks[0] + planks[6] = 1 + 4 = 5
- planks[1] + planks[2] = 3 + 2 = 5

Hence, the maximum width is 4.

 **Example 2:** 

 **Input:**  planks = [2,3,7]

 **Output:**  1

 **Explanation:** 

- It is impossible to form two planks of the same height, even after combining two distinct original planks.
- Since not all original planks need to be used, we can choose any one plank as the fence.
- Therefore, the maximum possible width is 1.

 

 **Constraints:** 

- 1 <= planks.length <= 1000
- 1 <= planks[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 1556 ms (beats 29.66%)  
**Memory:** 403.2 MB (beats 40.54%)  
**Submitted:** 2026-08-13T09:52:49.062Z  

```cpp
class Solution {
public:
    int maximumWidth(vector<int>& planks) {

        unordered_map<int, int> freq;

        for(int x : planks) {
            freq[x]++;
        }

        // All distinct plank heights
        vector<int> vals;

        for(auto &it : freq) {
            vals.push_back(it.first);
        }

        // pairs[h] = number of planks of height h
        // that we can make by joining two planks
        unordered_map<int, long long> pairs;

        int ans = 0;

        // We can directly use planks having the same height
        for(auto &it : freq) {
            ans = max(ans, it.second);
        }

        int k = vals.size();

        for(int i = 0; i < k; i++) {

            for(int j = i; j < k; j++) {

                int x = vals[i];
                int y = vals[j];

                int height = x + y;

                long long cnt;

                if(x == y) {
                    // Need two different planks
                    cnt = freq[x] / 2;
                }
                else {
                    cnt = min(freq[x], freq[y]);
                }

                // Multiple pairs can produce the same height,
                // so add their contributions.
                pairs[height] += cnt;
            }
        }

        // Now combine:
        // original planks of height h
        // + planks created by joining two planks to get h
        for(auto &it : pairs) {

            int height = it.first;

            long long total = it.second;

            if(freq.count(height)) {
                total += freq[height];
            }

            ans = max(ans, (int)total);
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/widest-possible-fence/)