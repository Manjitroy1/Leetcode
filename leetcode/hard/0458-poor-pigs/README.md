# Poor Pigs

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

There are `buckets` buckets of liquid, where  **exactly one**  of the buckets is poisonous. To figure out which one is poisonous, you feed some number of (poor) pigs the liquid to see whether they will die or not. Unfortunately, you only have `minutesToTest` minutes to determine which bucket is poisonous.

You can feed the pigs according to these steps:

- Choose some live pigs to feed.
- For each pig, choose which buckets to feed it. The pig will consume all the chosen buckets simultaneously and will take no time. Each pig can feed from any number of buckets, and each bucket can be fed from by any number of pigs.
- Wait for minutesToDie minutes. You may not feed any other pigs during this time.
- After minutesToDie minutes have passed, any pigs that have been fed the poisonous bucket will die, and all others will survive.
- Repeat this process until you run out of time.

Given `buckets`, `minutesToDie`, and `minutesToTest`, return  *the  **minimum**  number of pigs needed to figure out which bucket is poisonous within the allotted time*.

 

 **Example 1:** 

```
Input: buckets = 4, minutesToDie = 15, minutesToTest = 15
Output: 2
Explanation: We can determine the poisonous bucket as follows:
At time 0, feed the first pig buckets 1 and 2, and feed the second pig buckets 2 and 3.
At time 15, there are 4 possible outcomes:
- If only the first pig dies, then bucket 1 must be poisonous.
- If only the second pig dies, then bucket 3 must be poisonous.
- If both pigs die, then bucket 2 must be poisonous.
- If neither pig dies, then bucket 4 must be poisonous.

```

 **Example 2:** 

```
Input: buckets = 4, minutesToDie = 15, minutesToTest = 30
Output: 2
Explanation: We can determine the poisonous bucket as follows:
At time 0, feed the first pig bucket 1, and feed the second pig bucket 2.
At time 15, there are 2 possible outcomes:
- If either pig dies, then the poisonous bucket is the one it was fed.
- If neither pig dies, then feed the first pig bucket 3, and feed the second pig bucket 4.
At time 30, one of the two pigs must die, and the poisonous bucket is the one it was fed.

```

 

 **Constraints:** 

- 1 <= buckets <= 1000
- 1 <= minutesToDie <= minutesToTest <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 7.7 MB (beats 97.18%)  
**Submitted:** 2026-09-11T09:20:07.345Z  

```cpp
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs=0;
        int combinations =1;
        int state= minutesToTest/minutesToDie + 1;  //each pig has some state 
        //die at 0 , 5, 10 15, 20 or survive at the end 
        // so it state are 0 1 2 3 4 if states are 5
        // so two pigs can give 5*5 possibilities
        //for buckets 17 = (023) base 5 0 is the state of 1st 2 is the state of 2nd p and 3 is state of 3rd pig

        while(combinations< buckets){
            combinations*=state;
            pigs++;
        }
        return pigs;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/poor-pigs/)